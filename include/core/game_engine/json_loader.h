//
// Created by ravyu on 20/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_JSON_LOADER_H
#define FINAL_PROJECT_RAVYUS_JSON_LOADER_H

#endif  // FINAL_PROJECT_RAVYUS_JSON_LOADER_H
#include <nlohmann/json.hpp>

#include "core/game_objects/item.h"
#include "core/game_objects/room.h"
#include "item_container.h"
#include "room_container.h"
namespace adventure{
namespace engine{
class JSONLoader{
using Json = nlohmann::json;

 public:
  static ItemContainer LoadItems(const std::string& item_fp);
  static RoomContainer LoadRooms(const std::string& room_fp);

 private:
  static objects::Room LoadRoom(const Json& js);
  static objects::Item LoadItem(const std::string type, const Json& js);
};
}
}