//
// Created by ravyu on 25/11/20.
//
#include <core/game_engine/triggers/trigger.h>
#include "core/game_objects/item.h"
#include "core/game_engine/actions.h"


namespace adventure{
namespace core{
namespace actions {

Equip::Equip(std::string item_ID) : item_id_(item_ID) {}
void Equip::Execute(core::GameState &gs) {
  core::Item *itm = gs.ic_.GetItemByID(item_id_);
  gs.player_inventory_.push_back(itm);
  gs.current_room_->room_items_.erase(item_id_);
  for (triggers::Trigger *tg : itm->trigger_map_["equip"]) {
    tg->Execute(gs);
  }
}

MoveTo::MoveTo(std::string dest_ID) : dest_ID_(dest_ID) {}

void MoveTo::Execute(core::GameState &gs) {
  gs.current_room_ = &gs.rc_.GetRoomByID(dest_ID_);
}


NoAction::NoAction() {}
void NoAction::Execute(core::GameState &gs) {};


Unlock::Unlock(const string &item_id):item_id_(item_id){};

void Unlock::Execute(core::GameState &gs) {
  core::Item* itm = gs.ic_.GetItemByID(item_id_);
  itm->locked_ = false;
  for (triggers::Trigger *tg : itm->trigger_map_["unlock"]){
    tg->Execute(gs);
  }
}

UnlockKeypad::UnlockKeypad(const string &item_id):item_id_(item_id) {};

void UnlockKeypad::Execute(core::GameState &gs) {
  core::Item* itm = gs.ic_.GetItemByID(item_id_);
  itm->locked_ = false;
  for (triggers::Trigger *tg : itm->trigger_map_["keypad_unlock"]){
    tg->Execute(gs);
  }
}
}
}
}