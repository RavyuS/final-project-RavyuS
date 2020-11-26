//
// Created by ravyu on 25/11/20.
//
#include "core/game_engine/triggers/room_visibility.h"
#include "core/game_objects/room.h"

namespace adventure{
namespace triggers{
RoomVisibility::RoomVisibility(const std::string room_id, bool visible):
room_id_(room_id), visible_(visible){}

void RoomVisibility::Execute(engine::GameState &gs) {
  objects::Room rm = gs.rc_.GetRoomByID(room_id_);
  rm.visible_ = visible_;
}
}
}
