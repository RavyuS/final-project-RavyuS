//
// Created by ravyu on 28/11/20.
//
#pragma once
#include "cinder/gl/gl.h"
#include "core/game_engine/game_state.h"
#include "cinder/app/App.h"
#include "core/game_engine/actions.h"


namespace adventure{
namespace gui{

/**
 * The Screen Manager is in charge of rendering the Game World (Rooms and Item menus) and handling user inputs.
 *
 */
class ScreenManager {

 public:
  /**
   * The Screen window exists in one of 3 modes at any point in time.
   */
  enum Screen{
    ROOM, // Player is viewing a Room. The room along with visible items it contains will be rendered.
    ITEM_ACTION, // Player is viewing the possible actions of an item that was just clicked. A menu with possible actions will be rendered.
    ITEM_INTERACT // Player is interacting with the item. The interactive item's draw() method will handle the rendering.
  };

  /**
   * Initializes Screen Manager instance. The starting screen will be the current Room.
   * @param bbox Boundaries within which the Screen Manager will render its elements.
   * @param gs A shared pointer to the constant GameState object within which the App is running in.
   */
  ScreenManager(ci::Rectf bbox, std::shared_ptr<const core::GameState> gs);

  /**
   * Explicit destructor to release shared ownership of the GameState shared pointer
   */
  ~ScreenManager();

  /**
   * Returns the appropriate action object based on the position of the mouseclick and the current Screen mode.
   * @param e
   * @return Appropriate Action-derived object.
   */
  core::actions::Action* HandleMouseEvent(ci::app::MouseEvent &e);

  /**
   * Renders the Screen interface based on the current Screen mode.
   */
  void draw();

  /**
   * Updates member variables based on current Screen mode
   */
  void update();

  Screen current_screen; // the Screen mode player is currently in
  ci::Rectf bbox_;

 private:

  std::shared_ptr<const core::GameState> gs_;
  core::Item* focus_itm_; // the item the player is currently viewing. It is set in the ROOM mode upon clicking on an item
  std::map<string,ci::Rectf> screen_objects_; // The clickable object boundaries to be defined on screen
  std::map<string,string> menu_string_map_; // The item's menu elements and the string text to be displayed in each element box.

  /**
   * Renders Room mode elements
   */
  void draw_room();

  /**
   * Renders Item Action mode elements
   */
  void draw_item_menu();

  /**
   * Updates member variables when in Room mode
   */
  void update_room();

  /**
   * Updates member variables when in item mode
   */
  void update_item_menu();

  /**
   * Helper function that loads image files into Cinder 2D textures from the relative filepath provided.
   * Note that the texture object generated must be manually released from memory at the end of lifetime (user defined).
   * This can be done by invoking the texture's reset() function
   * @param fp relative file path of the texture image (starting from "assets" folder)
   * @return Cinder Texture object
   */
  ci::gl::Texture2dRef LoadTexture(string fp);

  /**
   * Invoked in Item Action mode. Determines the appriopriate action based on user input and returns the corresponding
   * action object
   * @param action the action string should correspond to a key in the screen_objects_ map.
   * @return Appropriate Action-derived object.
   */
  core::actions::Action* handle_item_action(const string& action);



};
}
}

