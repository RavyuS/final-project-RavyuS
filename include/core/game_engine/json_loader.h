//
// Created by ravyu on 20/11/20.
//
#pragma once
#include <nlohmann/json.hpp>

#include "core/game_objects/item.h"
#include "core/game_objects/room.h"
#include "item_container.h"
#include "room_container.h"
namespace adventure{
namespace core{
class JSONLoader{
using Json = nlohmann::json;

 public:
  static ItemContainer LoadItems(const std::string& item_fp);
  static RoomContainer LoadRooms(const std::string& room_fp);

 private:
  static Room LoadRoom(const std::string id, Json& js);
  static Item* LoadItem(const std::string id, Json& js);
  static TriggerMap GenerateTriggerMap( Json& js);
  static void AddTriggerToVec(Json& js, std::vector<triggers::Trigger*> &t_vec);
};
}
}