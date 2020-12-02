//
// Created by ravyu on 24/11/20.
//

#include "core/game_objects/interactive_items/keypad.h"
#include "core/game_engine/actions/unlock_keypad.h"
#include "core/game_engine/actions/no_action.h"
#include "cinder/app/App.h"
namespace adventure::core{
    Keypad::Keypad(const string &id, int unlock_code) : Item(id) {
      interactive_ = true;
      unlock_code_ = unlock_code;
      keypad_texture = ci::gl::Texture2d::create(ci::loadImage(ci::app::loadAsset("items/keypad.png")));
      input_ = "";
    }
    void Keypad::Draw(ci::Rectf &boundaries) {
      if(keys_.empty()) LoadKeys(boundaries);
      ci::gl::draw(keypad_texture,keypad_top_left_);

    }
    actions::Action*  Keypad::UpdateOnClick(glm::vec2 &click_coords) {

      for(auto it = keys_.cbegin(); it!= keys_.cend(); it++){
        if(it->second.contains(click_coords)){
          if(it->first == '*' || it->first == '#') input_ = "";
          else{
            input_.push_back(it->first);
          }
        }
      }
      if(input_ == std::to_string(unlock_code_)){
        input_ = "SUCCESS";
        return new actions::UnlockKeypad(id_);
      }
      else return new actions::NoAction();
    }
    void Keypad::LoadKeys(ci::Rectf &boundaries) {
      keypad_top_left_ = glm::vec2(boundaries.getCenter().x-200,250);

      keys_['1'] = GenerateKeyBox(keypad_top_left_+glm::vec2(124,96));
      keys_['4'] = GenerateKeyBox(keypad_top_left_+glm::vec2(124,150));
      keys_['7'] = GenerateKeyBox(keypad_top_left_+glm::vec2(124,204));
      keys_['*'] = GenerateKeyBox(keypad_top_left_+glm::vec2(124,262));
      keys_['2'] = GenerateKeyBox(keypad_top_left_+glm::vec2(180,96));
      keys_['5'] = GenerateKeyBox(keypad_top_left_+glm::vec2(180,150));
      keys_['8'] = GenerateKeyBox(keypad_top_left_+glm::vec2(180,204));
      keys_['0'] = GenerateKeyBox(keypad_top_left_+glm::vec2(180,262));
      keys_['3'] = GenerateKeyBox(keypad_top_left_+glm::vec2(236,96));
      keys_['6'] = GenerateKeyBox(keypad_top_left_+glm::vec2(236,150));
      keys_['9'] = GenerateKeyBox(keypad_top_left_+glm::vec2(236,204));
      keys_['#'] = GenerateKeyBox(keypad_top_left_+glm::vec2(236,262));
    }
ci::Rectf Keypad::GenerateKeyBox(glm::vec2 top_left) {
  glm::vec2 key_size (42,43);

  return cinder::Rectf(top_left,top_left+key_size);
}
}
