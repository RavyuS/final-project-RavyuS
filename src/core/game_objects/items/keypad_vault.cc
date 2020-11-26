//
// Created by ravyu on 24/11/20.
//

#include "core/game_objects/items/keypad_vault.h"
namespace adventure{
    namespace objects{
    KeypadVault::KeypadVault(const string &id):Item(id) {
      interactive_ = true;
    }
    void KeypadVault::Draw() {}
    void KeypadVault::UpdateOnClick(glm::vec2 click_coords) {}
    }
}