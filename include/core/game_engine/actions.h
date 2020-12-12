//
// Created by ravyu on 19/11/20.
//

#pragma once

#include <core/game_engine/game_state.h>
namespace adventure{
namespace core{
namespace actions {

/**
 * Actions are objects that are passed to GameEngine's HandleAction method to modify the game world as the Game Progresses.
 * They are defined by the Action interface, which specifies the "Execute" method requirement.
 */
class Action {
 public:
  /**
   * The Execute method is invoked by the GameEngine upon receiving the action through it's HandleAction method. The
   * engine's GameState pointer is passed, which is then modified to change the game world.
   * @param gs GameState pointer through which the Engine's GameState instance is accessed and modified
   */
  virtual void Execute(std::shared_ptr<core::GameState> gs) =0 ;
};

/**
 * Equip the item specified to user inventory.
 */
class Equip : public Action{
 public:
  /**
   * Creates the Equip action object.
   * @param item_ID The ID of the item that will be added to
   */
  Equip(std::string item_ID);

  /**
   * Item is added to player's inventory and removed from the Room's object list.
   * @param gs
   */
  void Execute(std::shared_ptr<core::GameState> gs) override;

 private:
  std::string item_id_;
};

/**
 * Moves player to the specified room
 */
class MoveTo : public Action {
 public:
  /**
   * Creates the MoveTo action object
   * @param dest_ID ID of the room that the player will move to
   */
  MoveTo(std::string dest_ID);

  /**
   * Current Room is changed to the specified room.
   * @param gs
   */
  void Execute(std::shared_ptr<core::GameState> gs) override;

 private:
  std::string dest_ID_;
};

/**
 * A filler object where nothing happens
 */
class  NoAction: public Action {
 public:
  NoAction();
  void Execute(std::shared_ptr<core::GameState> gs) override;


};

/**
 * Unlocks the item specified in item_id
 */
class Unlock : public Action {
 public:
  /**
   * Creates an Unlock action object.
   * @param item_id ID of item to be unlocked.
   */
  Unlock(const string& item_id);

  /**
   * Sets the item status to unlocked and executes the unlock triggers of the item
   * @param gs
   */
  void Execute(std::shared_ptr<core::GameState> gs) override;

 private:
  string item_id_;
};

/**
 * Similar to Unlock, except the unlock condition is based on correct keypad entry as opposed to possession of the
 * correct item.
 */
class UnlockKeypad : public Action {
 public:
  UnlockKeypad(const string& item_id);
  void Execute(std::shared_ptr<core::GameState> gs) override;

 private:
  string item_id_;
};

} //namespace actions
} //namespace core
} //namespace adventure