//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_ITEM_VISIBILITY_H
#define FINAL_PROJECT_RAVYUS_ITEM_VISIBILITY_H
#include "trigger.h"

namespace adventure{
namespace triggers{
struct ItemVisibility : public Trigger{
  ItemVisibility(const std::string& item_id, bool visibility);
  std::string item_id_;
  bool visibility_;
  void Execute(engine::GameState &gs) override;
};
}
}
#endif  // FINAL_PROJECT_RAVYUS_ITEM_VISIBILITY_H
