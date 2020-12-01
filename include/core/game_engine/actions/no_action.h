//
// Created by ravyu on 28/11/20.
//
#include "action.h"
#include "core/game_engine/game_state.h"
namespace adventure {
namespace core {
namespace actions {
class  NoAction: public Action {
 public:
  NoAction();
  void Execute(core::GameState &gs) override;


};
}
}
}

