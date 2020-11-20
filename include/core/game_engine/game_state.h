//
// Created by ravyu on 19/11/20.
//
#pragma once

#include "room_container.h"
#include "item_container.h"
#include "core/game_objects/items/item.h"
#include "core/game_objects/room.h"

namespace adventure{
namespace engine{
class GameState{
  GameState();
  ~GameState();

 public:
  objects::Room current_room_;
  std::vector<objects::Item> player_inventory_;
  RoomContainer rc_;
  ItemContainer ic_;

};
}
}