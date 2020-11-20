//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_ITEM_VISIBILITY_H
#define FINAL_PROJECT_RAVYUS_ITEM_VISIBILITY_H
#include "trigger.h"

namespace adventure{
namespace triggers{
struct ItemVisibility : public Trigger{
  std::string item_ID;
  bool hide;
  void Execute(engine::GameState &gs) override;
};
}
}
#endif  // FINAL_PROJECT_RAVYUS_ITEM_VISIBILITY_H
