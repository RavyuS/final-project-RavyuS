//
// Created by ravyu on 24/11/20.
//

#include "core/game_objects/interactive_items/keypad.h"
namespace adventure{
    namespace core{
    Keypad::Keypad(const string &id, int unlock_code) :Item(id) {
      interactive_ = true;
      unlock_code_ = unlock_code;
    }
    void Keypad::Draw() {}
    void Keypad::UpdateOnClick(glm::vec2 click_coords) {}
    }
}