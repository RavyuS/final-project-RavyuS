//
// Created by ravyu on 26/11/20.
//
#pragma once
#include "../item.h"

namespace adventure{
namespace core{
class StaticImage : public Item{
 public:
  StaticImage(const string& id, const string& display_img_fp);
  void Draw();
  void UpdateOnClick(glm::vec2 click_coords);
 private:
  string display_img_fp_;
};

}
}
