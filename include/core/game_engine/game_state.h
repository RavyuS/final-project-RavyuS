//
// Created by ravyu on 19/11/20.
//
#pragma once
#include "core/game_objects/room.h"
#include "core/game_objects/item.h"
#include "item_container.h"
#include "room_container.h"

namespace adventure{
namespace core{
/**
 * The GameState class stores a particular instance's world state. This includes all the rooms and items of the game world,
 * both of which are stored in their respective container classes.
 */
class GameState{
 public:
  Room* current_room_; //Pointer to the room the player is currently in.
  std::vector<Item*> player_inventory_; // Vector of Items the player has in inventory.
  RoomContainer rc_; // Contains all the rooms in this game instance
  ItemContainer ic_; // Contains all the items in this game instance


  GameState() = default;

  /**
   * Explicit destructor for GameState. Handles pointer deallocation and clears up memory from Room and Item containers
   */
  ~GameState();
};
}
}