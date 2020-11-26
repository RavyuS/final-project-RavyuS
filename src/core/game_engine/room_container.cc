//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/room_container.h"

namespace adventure{
namespace engine{
objects::Room RoomContainer::GetRoomByID(const std::string &id) {
  for (objects::Room &rm : rooms_){
    if(rm.id_ == id) return rm;
  }
}
std::vector<objects::Room> RoomContainer::GetRoomByName(const std::string &name) {
  std::vector<objects::Room> rooms;
  for(objects::Room &rm : rooms_){
    if(rm.name_ == name) rooms.push_back(rm);
  }
  return rooms;
}

void RoomContainer::AddRoom(objects::Room &rm) {
  rooms_.push_back(rm);
}
}
}