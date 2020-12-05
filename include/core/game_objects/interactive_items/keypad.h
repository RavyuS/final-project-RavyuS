//
// Created by ravyu on 24/11/20.
//
#pragma once
#include "../item.h"
#include "cinder/gl/gl.h"
#include "core/game_engine/actions.h"
namespace adventure::core{
class Keypad : public Item {
 public:
  Keypad(const string& id, int unlock_code);
  void Draw(ci::Rectf &boundaries);
  actions::Action* UpdateOnClick(glm::vec2 &click_coords);
 private:
  int unlock_code_;
  std::map<char,ci::Rectf> keys_;
  ci::gl::Texture2dRef keypad_texture;
  glm::vec2 keypad_top_left_;
  string input_;

  void LoadKeys(ci::Rectf &boundaries);
  ci::Rectf GenerateKeyBox(glm::vec2 top_left);

};
}
