//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/game_state.h"
namespace adventure{
namespace core{
GameState::GameState(){}
GameState::~GameState() {
current_room_ = nullptr;
for(Item *itm : player_inventory_) itm = nullptr;
rc_.Clear();
ic_.Clear();
}
}
}