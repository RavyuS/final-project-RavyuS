//
// Created by ravyu on 24/11/20.
//
#pragma once
#include "../item.h"
namespace adventure{
namespace core{
class Keypad : public Item {
 public:
  Keypad(const string& id, int unlock_code);
  void Draw();
  void UpdateOnClick(glm::vec2 click_coords);
 private:
  int unlock_code_;
};
}
}
