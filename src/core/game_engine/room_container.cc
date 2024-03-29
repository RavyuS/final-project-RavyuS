//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/room_container.h"

namespace adventure{
namespace core{
Room * RoomContainer::GetRoomByID(const std::string &id) const{
  for (core::Room *rm : rooms_){
    if(rm->id_ == id) return rm;
  }
  throw std::invalid_argument("Room ID does not exist");
}
std::vector<Room *> RoomContainer::GetRoomByName(const std::string &name) const{
  std::vector<core::Room*> rooms;
  for(core::Room *rm : rooms_){
    if(rm->name_ == name) rooms.push_back(rm);
  }
  return rooms;
}

void RoomContainer::AddRoom(Room *rm) {
  rooms_.push_back(rm);
}
void RoomContainer::Clear() {
for(Room *rm:rooms_){
  delete rm;
  rm = nullptr;
}
rooms_.clear();
}

}
}