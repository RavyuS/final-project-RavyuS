//
// Created by ravyu on 1/12/20.
//
#include <core/game_engine/actions.h>
#include "item.h"
namespace adventure{
namespace core{
class BasicItem: public Item{
 public:
  /**
   * Creates an instance of a BasicItem, an implementation of the Item interface with no interactive features.
   * @param id String ID of the item.
   */
  BasicItem(const string& id);

  /**
   * Empty Draw and UpdateOnClick function override as placeholders.
   *
   */
  void Draw(ci::Rectf &boundaries) override;
  core::actions::Action * UpdateOnClick(glm::vec2 &click_coords) override;
};
}
}
