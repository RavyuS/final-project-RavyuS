//
// Created by ravyu on 25/11/20.
//
#include <core/game_engine/triggers.h>
#include "core/game_objects/item.h"
#include "core/game_engine/actions.h"


namespace adventure{
namespace core{
namespace actions {

Equip::Equip(std::string item_ID) : item_id_(item_ID) {}
void Equip::Execute(std::shared_ptr<core::GameState> gs) {
  core::Item *itm = gs->ic_.GetItemByID(item_id_);
  if(itm->can_equip_) {
    gs->player_inventory_.push_back(itm);
    gs->current_room_->room_items_.erase(item_id_);
    for (triggers::Trigger *tg : itm->trigger_map_["equip"]) {
      tg->Execute(gs);
    }
  }
  else throw std::invalid_argument("Item cannot be picked up");
}

MoveTo::MoveTo(std::string dest_ID) : dest_ID_(dest_ID) {}

void MoveTo::Execute(std::shared_ptr<core::GameState> gs) {
  Room *dest_rm = gs->rc_.GetRoomByID(dest_ID_);
  gs->current_room_ = dest_rm;
}


NoAction::NoAction() {}
void NoAction::Execute(std::shared_ptr<core::GameState> gs) {};


Unlock::Unlock(const string &item_id):item_id_(item_id){};

void Unlock::Execute(std::shared_ptr<core::GameState> gs) {
  core::Item* itm = gs->ic_.GetItemByID(item_id_);
  if(itm->CanUnlock(gs->player_inventory_)) {
    itm->locked_ = false;
    for (triggers::Trigger *tg : itm->trigger_map_["unlock"]) {
      tg->Execute(gs);
    }
  }
  else throw std::invalid_argument("Unlock item not in player inventory. Interface must handle this.");
}

UnlockKeypad::UnlockKeypad(const string &item_id):item_id_(item_id) {};

void UnlockKeypad::Execute(std::shared_ptr<core::GameState> gs) {
  core::Item* itm = gs->ic_.GetItemByID(item_id_);
  itm->locked_ = false;
  for (triggers::Trigger *tg : itm->trigger_map_["keypad_unlock"]){
    tg->Execute(gs);
  }
}
}
}
}