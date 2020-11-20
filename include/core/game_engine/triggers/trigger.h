//
// Created by ravyu on 19/11/20.
//
#pragma once
#ifndef FINAL_PROJECT_RAVYUS_TRIGGER_H
#define FINAL_PROJECT_RAVYUS_TRIGGER_H
#include "core/game_engine/game_state.h"
#endif  // FINAL_PROJECT_RAVYUS_TRIGGER_H
namespace adventure{
namespace triggers{
struct Trigger{

  virtual void Execute(engine::GameState& gs);
};
}
}