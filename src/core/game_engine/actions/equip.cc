//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/actions/equip.h"
#include "core/game_engine/room_container.h"

namespace adventure{
namespace actions{
Equip::Equip(std::string& item_ID):item_id_(item_ID) {}
void Equip::Execute(engine::GameState &gs) {
  gs.player_inventory_.push_back(gs.ic_.GetItemByID(item_id_));
  gs.current_room_.room_items_.erase(item_id_);
}
}
}