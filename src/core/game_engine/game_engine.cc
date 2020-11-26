//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/game_engine.h"
#include "core/game_engine/json_loader.h"

namespace adventure{
namespace engine{
GameEngine::GameEngine(const std::string &item_fp, const std::string &room_fp) {
gs_.ic_ = JSONLoader::LoadItems(item_fp);
gs_.rc_ = JSONLoader::LoadRooms(room_fp);
gs_.current_room_ = gs_.rc_.GetRoomByID("start");
}

void GameEngine::HandleAction(actions::Action &action) {
  action.Execute(gs_);
}

GameEngine::~GameEngine() {}
}
}