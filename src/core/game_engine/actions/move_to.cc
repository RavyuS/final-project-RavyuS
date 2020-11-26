//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/actions/move_to.h"
#include "core/game_engine/room_container.h"
namespace adventure{
namespace actions{
MoveTo::MoveTo(std::string dest_ID): dest_ID_(dest_ID) {}

void MoveTo::Execute(engine::GameState &gs) {
  gs.current_room_ = gs.rc_.GetRoomByID(dest_ID_);
}
}
}