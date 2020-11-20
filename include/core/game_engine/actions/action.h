//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_EVENT_H
#define FINAL_PROJECT_RAVYUS_EVENT_H

#endif  // FINAL_PROJECT_RAVYUS_EVENT_H
#include "core/game_engine/game_state.h"
namespace adventure{

namespace actions {
class Action {
  virtual void Execute(engine::GameState& gs);
};
}

}