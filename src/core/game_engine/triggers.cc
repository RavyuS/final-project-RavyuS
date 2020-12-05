//
// Created by ravyu on 25/11/20.
//
#include "core/game_engine/triggers.h"
#include "core/game_objects/room.h"

namespace adventure {
namespace core {
namespace triggers {

RoomVisibility::RoomVisibility(const std::string room_id, bool visible) :
    room_id_(room_id), visible_(visible) {}

void RoomVisibility::Execute(std::shared_ptr<GameState> gs) {
  core::Room &rm = gs->rc_.GetRoomByID(room_id_);
  rm.visible_ = visible_;
}

ItemVisibility::ItemVisibility(const std::string &item_id, bool visibility) :
    item_id_(item_id), visibility_(visibility) {}
void ItemVisibility::Execute(std::shared_ptr<GameState> gs) {
  Item *itm = gs->ic_.GetItemByID(item_id_);
  itm->visible_ = visibility_;
}
}
}
}