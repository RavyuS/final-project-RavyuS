//
// Created by ravyu on 26/11/20.
//
#pragma once
#include <core/game_engine/actions.h>
#include "../item.h"

namespace adventure{
namespace core{
/**
 * A Static Image is a derived interactive Item that displays a static image texture upon entering interactive mode.
 *
 */
class StaticImage : public Item{
 public:
  /**
   * Initializes a StaticImage item
   * @param id ID of the StaticImage item. Must be unique among other Items
   * @param display_img_fp the filepath of the image texture that will be displayed in interactive mode
   */
  StaticImage(const string& id, const string& display_img_fp);

  /**
   * Renders the static image to the user.
   * @param boundaries
   */
  void Draw(ci::Rectf &boundaries);

  /**
   * A placeholder definition. Item does not handle any user inputs
   * @param click_coords
   * @return a NoAction Object
   */
  core::actions::Action * UpdateOnClick(glm::vec2 &click_coords);
 private:
  string display_img_fp_;
};

}
}

