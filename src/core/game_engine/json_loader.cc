//
// Created by ravyu on 20/11/20.
//
#include <stdio.h>
#include "core/game_engine/json_loader.h"
#include "nlohmann/json.hpp"
namespace adventure{
namespace engine{
using Json = nlohmann::json;
ItemContainer * JSONLoader::LoadItems(const std::string &item_fp) {
  std::ifstream is(item_fp);
  Json js;
  is >> js;

  ItemContainer *ic = new ItemContainer();
  for(auto item: js["items"].items()){
    ic->AddItem(LoadItem(item.key(), item.value()));
  }
}
objects::Item * JSONLoader::LoadItem(const std::string type, const Json &js) {
  objects::Item *item = new objects::Item();
  item->id = js["id"];
  item->name = js["name"];
  item->hidden = js["hidden"];
  item->can_equip = js["can_equip"];

}
}
}
