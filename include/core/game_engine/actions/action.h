//
// Created by ravyu on 19/11/20.
//

#pragma once

#include <core/game_engine/game_state.h>
namespace adventure{
namespace core{
namespace actions {
class Action {
 public:
  virtual void Execute(core::GameState& gs) =0 ;
};
}

}}