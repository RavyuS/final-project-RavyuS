//
// Created by ravyu on 1/12/20.
//
#include <core/game_engine/triggers/trigger.h>
#include "core/game_engine/actions/unlock.h"
namespace adventure{
namespace core{
namespace actions{

Unlock::Unlock(const string &item_id):item_id_(item_id){};

void Unlock::Execute(core::GameState &gs) {
  core::Item* itm = gs.ic_.GetItemByID(item_id_);
  itm->locked_ = false;
  for (triggers::Trigger *tg : itm->trigger_map_["unlock"]){
    tg->Execute(gs);
  }
}
}
}
}