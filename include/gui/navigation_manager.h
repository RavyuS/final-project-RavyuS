//
// Created by ravyu on 28/11/20.
//
#pragma once
#include "cinder/gl/gl.h"
#include "core/game_engine/game_state.h"
#include "cinder/app/App.h"
#include "core/game_engine/actions.h"
#include "screen_manager.h"

namespace adventure{
namespace gui{
/**
 * The NavigationManager is a UI element that displays the Rooms the player can travel to based on the current position.
 * It handles the creation and rendering of the Rooms list and the mouse input
 */
class NavigationManager {
 public:
  /**
   * Initializes Navigation Manager instance.
   * @param bbox Boundaries within which the Navigation Manager will render its elements
   * @param gs A shared pointer to the constant GameState object within which the App is running in.
   */
  NavigationManager(ci::Rectf bbox, std::shared_ptr<const core::GameState> gs);

  /**
   * Explicit destructor to release shared ownership of the GameState shared pointer
   */
  ~NavigationManager();

  /**
   * Returns the appropriate action object based on the position of the mouseclick. If a Room's text-box is selected,
   * a MoveTo action to that room is generated.
   * @param e used to derive mouse coordinates
   * @return MoveTo action if a Room is selected, NoAction otherwise
   */
  core::actions::Action* HandleMouseEvent(ci::app::MouseEvent &e);

  /**
   * Renders the navigation menu, listing all the rooms visible and adjacent to the current Room. Note that this is only
   * rendered if the ScreenManager is NOT in Item Action/Interaction mode.
   */
  void draw();

  /**
   * Used to update the Manager's member variables
   * @param cur_scr The current mode the ScreenManager is in right now. This is used to determine whether the menu will be rendered in draw()
   */
  void update(const ScreenManager::Screen &cur_scr);

  ci::Rectf bbox_; //Navigation menu boundaries

 private:
  core::Room *cur_rm_; // Pointer to the room the player is in
  std::map<core::Room* ,ci::Rectf> room_objs_; // Map of adjacent rooms and their menu box boundary coordinates.
  std::shared_ptr<const core::GameState> gs_; // Pointer to the internal GameState. Constant to prevent illegal access
  glm::vec2 title_offset_ = glm::vec2 (0,120); // Position coordinates for the Menu title.

  /**
   * Determines the size of individual room text boxes based on the number of room visible and adjacent to the current room
   * @param numRooms
   * @return
   */
  ci::Area GetIndividualBoxSize(int numRooms);
};
}
}