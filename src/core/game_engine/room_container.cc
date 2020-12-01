//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/room_container.h"

namespace adventure{
namespace core{
core::Room& RoomContainer::GetRoomByID(const std::string &id) {
  for (core::Room &rm : rooms_){
    if(rm.id_ == id) return rm;
  }
}
std::vector<core::Room> RoomContainer::GetRoomByName(const std::string &name) {
  std::vector<core::Room> rooms;
  for(core::Room &rm : rooms_){
    if(rm.name_ == name) rooms.push_back(rm);
  }
  return rooms;
}

void RoomContainer::AddRoom(core::Room &rm) {
  rooms_.push_back(rm);
}

}
}