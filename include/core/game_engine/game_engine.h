//
// Created by ravyu on 19/11/20.
//
#pragma once
#include <string>

#include "core/game_engine/actions/action.h"
#include "game_state.h"
namespace adventure{
namespace core{
class GameEngine{
 public:
  GameEngine(const std::string& item_fp, const std::string& room_fp);


  void HandleAction(actions::Action& action);

  GameState* GetGameState();



 private:
  GameState gs_;
};
}
}