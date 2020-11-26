//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/triggers/item_visibility.h"

namespace adventure{
namespace triggers{
ItemVisibility::ItemVisibility(const std::string& item_id, bool visibility):
item_id_(item_id),visibility_(visibility){}
void ItemVisibility::Execute(engine::GameState &gs) {
  objects::Item itm = gs.ic_.GetItemByID(item_id_);
  itm.visible_ = visibility_;
}
}
}