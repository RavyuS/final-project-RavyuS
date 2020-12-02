//
// Created by ravyu on 25/11/20.
//
#include <core/game_engine/triggers/trigger.h>
#include "core/game_objects/item.h"
#include "core/game_engine/actions/equip.h"


namespace adventure{
namespace core{
namespace actions{
Equip::Equip(std::string item_ID):item_id_(item_ID) {}
void Equip::Execute(core::GameState &gs) {
  core::Item *itm = gs.ic_.GetItemByID(item_id_);
  gs.player_inventory_.push_back(itm);
  gs.current_room_->room_items_.erase(item_id_);
  for (triggers::Trigger *tg : itm->trigger_map_["equip"]){
    tg->Execute(gs);
  }
}
}
}}