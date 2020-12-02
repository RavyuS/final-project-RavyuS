//
// Created by ravyu on 1/12/20.
//
#include <core/game_engine/triggers/trigger.h>
#include "core/game_engine/actions/unlock_keypad.h"
namespace adventure{
namespace core{
namespace actions{

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