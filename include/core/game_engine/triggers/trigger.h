//
// Created by ravyu on 19/11/20.
//

#pragma once
#include <core/game_engine/game_state.h>

namespace adventure{
namespace core {
namespace triggers {
class Trigger {
 public:
  virtual void Execute(core::GameState &gs) =0;
};
}
}
}