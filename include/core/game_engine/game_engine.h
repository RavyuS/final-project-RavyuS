//
// Created by ravyu on 19/11/20.
//
#pragma once
#include <string>

#include "actions.h"
#include "game_state.h"
namespace adventure{
namespace core{
class GameEngine{
 public:
  GameEngine(const std::string& item_fp, const std::string& room_fp);

  ~GameEngine();

  void HandleAction(actions::Action& action);

  std::shared_ptr<GameState> GetGameState();



 private:
  std::shared_ptr<GameState> gs_;
};
}
}