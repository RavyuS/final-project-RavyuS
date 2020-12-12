//
// Created by ravyu on 19/11/20.
//

#pragma once
#include <core/game_engine/game_state.h>

namespace adventure{
namespace core {
namespace triggers {

/**
 * Triggers are a set of container classes that can change gamestate upon execution. They are triggered based on events
 * specified by the item's trigger map through the GameEngine. The Trigger interface specifies the Execute function.
 *
 * The execution of a trigger is handled externally, typically by Actions (refer to Action.h).
 */
class Trigger {
 public:
  /**
   * Specification for Trigger-derived classes.
   * The Execute function is invoked when the corresponding event on an Item's TriggerMap occurs.
   * @param gs GameState pointer that allows modification of game world upon execution of trigger.
   */
  virtual void Execute(std::shared_ptr<GameState> gs) =0;
};

/**
 * Room Visibility sets the room's "visibile" member to the specified boolean value.
 */
class RoomVisibility : public Trigger {
 public:

  /**
   * Creates a RoomVisibility instance
   * @param room_id ID of the room that will have its visibility changed.
   * @param visible desired visibility value (boolean). If false, room should not be accessible by the player anymore.
   */
  RoomVisibility(const std::string room_id, bool visible);
  std::string room_id_;
  bool visible_;

  /**
   * Sets the room's visible boolean member to the specified boolean value.
   * @param gs
   */
  void Execute(std::shared_ptr<GameState> gs) override;
};

/**
 * ItemVisibility sets the item's "visible" member variable to the specified boolean value
 */
class ItemVisibility : public Trigger {
  std::string item_id_;
  bool visibility_;

 public:
  /**
   * Creates a ItemVisibility instance
   * @param item_id ID of the item that will have its visibility changed.
   * @param visible desired visibility value (boolean). If false, item should not be visible to the player in the room that it is placed in.
   */
  ItemVisibility(const std::string &item_id, bool visibility);

  /**
   * Sets the item's visible boolean member to the specified boolean value.
   * @param gs
   */
  void Execute(std::shared_ptr<GameState> gs) override;
};
}
}
}