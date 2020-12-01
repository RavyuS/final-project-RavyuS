//
// Created by ravyu on 25/11/20.
//
#include "core/game_engine/triggers/room_visibility.h"
#include "core/game_objects/room.h"

namespace adventure {
namespace core {
namespace triggers {
RoomVisibility::RoomVisibility(const std::string room_id, bool visible) :
    room_id_(room_id), visible_(visible) {}

void RoomVisibility::Execute(core::GameState &gs) {
  core::Room &rm = gs.rc_.GetRoomByID(room_id_);
  rm.visible_ = visible_;
}
}
}
}