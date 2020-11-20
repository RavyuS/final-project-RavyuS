//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_GAME_ENGINE_H
#define FINAL_PROJECT_RAVYUS_GAME_ENGINE_H

#endif  // FINAL_PROJECT_RAVYUS_GAME_ENGINE_H
#include <string>

#include "core/game_engine/actions/action.h"
#include "game_state.h"
namespace adventure{
namespace engine{
class GameEngine{
 public:
  GameEngine(std::string json_fp);
  ~GameEngine();

  void HandleAction(actions::Action action);

  GameState gs_;


 private:
  void LoadRooms();
  void LoadItems();


};
}
}