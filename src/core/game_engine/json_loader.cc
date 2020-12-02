//
// Created by ravyu on 20/11/20.
//
#include <stdio.h>
#include <core/game_objects/interactive_items/static_image.h>
#include <core/game_engine/triggers/item_visibility.h>
#include <core/game_engine/triggers/room_visibility.h>
#include "core/game_objects/basic_item.h"
#include <core/game_objects/interactive_items/keypad.h>
#include "core/game_engine/json_loader.h"
#include "nlohmann/json.hpp"
#include "core/game_objects/item.h"
namespace adventure{
namespace core{
using Json = nlohmann::json;
ItemContainer JSONLoader::LoadItems(const std::string &item_fp) {
  std::ifstream is(item_fp);
  Json js;
  is >> js;

  ItemContainer ic;
  for(auto &item: js.items()){
    Item *itm = LoadItem(item.key(), item.value());
    ic.AddItem(itm);
  }
  is.close();
  return ic;
}

RoomContainer JSONLoader::LoadRooms(const std::string &room_fp) {
  std::ifstream is(room_fp);
  Json js;
  is >> js;

  RoomContainer rc;
  for(auto &room: js.items()){
    Room rm = LoadRoom(room.key(),room.value());
    rc.AddRoom(rm);
  }
  is.close();
  return rc;
}


Item* JSONLoader::LoadItem(const std::string id, Json &js) {
  core::Item *item;

  if (js["type"] == "static_image") item = new StaticImage(id, js["display_img_fp"]);
  else if(js["type"] == "keypad") item = new Keypad(id,js["unlock_code"]);
  else item = new BasicItem(id);


  TriggerMap tm;
  if(js.contains("triggers")){
    tm = GenerateTriggerMap(js["triggers"]);
  }

  item->SetBasicProperties(js["name"],js["img_fp"],tm,js["visible"]);

  if(js.contains("can_equip")){
    item->can_equip_ = true;
  }

  if(js.contains("unlockable")){
    item->SetUnlockable(js["unlock_item_id"],js["post_unlock_msg"]);
  }

  if(js.contains("simple_trigger")){
    item->simple_trigger_ = true;
    item->trigger_button_msg_ = js["trigger_button_msg"];
    item->post_trigger_msg_ = js["post_trigger_msg"];
  }

  return item;
}

Room JSONLoader::LoadRoom(const std::string id, Json &js) {
  core::Room rm(id);
  rm.name_ = js["name"];
  rm.img_fp_ = js["img_fp"];
  rm.visible_ = js["visible"];

  if(js.contains("adjacent_rooms")){
    std::vector<string> adj_rms;
    for(auto &adj_rm: js["adjacent_rooms"].items()){
      adj_rms.push_back(adj_rm.value());
    }
    rm.adjacent_rooms_ = std::move(adj_rms);
  }
  if(js.contains("room_items")){
    std::map<string , glm::vec2> rm_itms;
    for(auto& itm : js["room_items"].items()){
      glm::vec2 coords(itm.value()["x"],itm.value()["y"]);
      rm_itms[itm.key()] = coords;
    }
    rm.room_items_ = rm_itms;
  }
  return rm;
}
TriggerMap JSONLoader::GenerateTriggerMap( Json &js) {
  TriggerMap tm;

  for(auto t_set: js.items()){
    std::vector<triggers::Trigger*> t_vec;
    for(auto &t: t_set.value().items()) AddTriggerToVec(t.value(),t_vec);
    tm[t_set.key()] = t_vec;
  }
 return tm;
}

void JSONLoader::AddTriggerToVec(Json &js, std::vector<triggers::Trigger*> &t_vec) {

  if (js["type"] == "item_visibility") {
    triggers::ItemVisibility *t = new triggers::ItemVisibility(js["item_id"], js["visible"]);
    t_vec.push_back(t);
  } else if (js["type"] == "room_visibility") {
    triggers::RoomVisibility *t = new triggers::RoomVisibility(js["room_id"], js["visible"]);
    t_vec.push_back(t);
  }
}
}
}


