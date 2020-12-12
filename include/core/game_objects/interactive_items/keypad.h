//
// Created by ravyu on 24/11/20.
//
#pragma once
#include "../item.h"
#include "cinder/gl/gl.h"
#include "core/game_engine/actions.h"
namespace adventure::core{
/**
 * The Keypad is an interactive Item type where the user can input a number. Matching the number trigger's the Item's
 * "keypad_unlock" trigger vectors.
 */
class Keypad : public Item {
 public:
  /**
   * Initializes instance of Keypad item
   * @param id ID of the keypad item. Must be unique among other Items
   * @param unlock_code the number required to achieve an "unlocked_keypad" state.
   */
  Keypad(const string& id, int unlock_code);

  /**
   * Explicit destructor for keypad to handle clearing of texture memory
   */
  ~Keypad() override;

  /**
   * Renders the keypad interface
   * @param boundaries specified boundaries within which the keypad is rendered.
   */
  void Draw(ci::Rectf &boundaries) override;

  /**
   * Handles keypad inputs by user. Input number is updated until correct number is achieved.
   * @param click_coords
   * @return Returns no action
   */
  actions::Action* UpdateOnClick(glm::vec2 &click_coords) override;
 private:
  int unlock_code_;// The code user is required to input to reach a "SUCCESS" state
  std::map<char,ci::Rectf> keys_; // Boundary boxes for individual keys in the keypad
  ci::gl::Texture2dRef keypad_texture;
  glm::vec2 keypad_top_left_; // Top left coordinates of the keyboard
  string input_; // updated string of user's input

  /**
   * Loads the boundary boxes for all the keys of the keypad. These boundary boxes are used to determine
   * what key is being pressed by the user's mouse click.
   * @param boundaries Boundaries within which the keypad will occupy
   */
  void LoadKeys(ci::Rectf &boundaries);

  /**
   * Generates the boundaries for a single key.
   * @param top_left The starting top left coordinate from which the individual key boundaries will be offset from
   * @return A 42x43 sized cinder::Rectf object
   */
  ci::Rectf GenerateKeyBox(glm::vec2 top_left);


};
}
