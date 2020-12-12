//
// Created by ravyu on 28/11/20.
//
#pragma once
#include "cinder/gl/gl.h"
#include "core/game_engine/game_state.h"
#include "cinder/app/App.h"
namespace adventure{
namespace gui{
/**
 * The Inventory Manager class renders the player's current inventory on the top right
 * corner of the screen. There is no interactive element, thus no need for event handlers.
 */
class InventoryManager {
 public:
  /**
   * Initializes Inventory Manager instance.
   * @param bbox Boundaries within which the Inventory Manager will render its elements
   * @param gs A shared pointer to the constant GameState object within which the App is running in.
   */
  InventoryManager(ci::Rectf bbox, std::shared_ptr<const core::GameState> gs);

  /**
   * Explicit destructor to release shared ownership of the GameState shared pointer
   */
  ~InventoryManager();

  /**
   * Renders the player's inventory, listing all the items in the inventory from top to bottom.
   */
  void draw();

  ci::Rectf bbox_; //Navigation menu boundaries

 private:
  std::shared_ptr<const core::GameState> gs_; // Pointer to the internal GameState. Constant to prevent illegal access
  glm::vec2 title_offset_ = glm::vec2 (0,40); // Offset starting coordinates for elements to leave space for title.
};

}
}

