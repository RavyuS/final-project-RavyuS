//
// Created by ravyu on 19/11/20.
//
#pragma once

#include <core/game_objects/item.h>
#include "core/game_objects/item.h"
#include "core/game_objects/room.h"
#include "item_container.h"
#include "room_container.h"

namespace adventure{
namespace engine{
class GameState{
  ~GameState();

 public:
  objects::Room current_room_;
  std::vector<objects::Item> player_inventory_;
  RoomContainer rc_;
  ItemContainer ic_;

  GameState();
};
}
}