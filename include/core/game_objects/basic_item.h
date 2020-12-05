//
// Created by ravyu on 1/12/20.
//
#include <core/game_engine/actions.h>
#include "item.h"
namespace adventure{
namespace core{
class BasicItem: public Item{
 public:
  BasicItem(const string& id);
  void Draw(ci::Rectf &boundaries) override;
  core::actions::Action * UpdateOnClick(glm::vec2 &click_coords) override;
};
}
}
