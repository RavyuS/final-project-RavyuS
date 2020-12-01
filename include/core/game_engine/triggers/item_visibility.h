//
// Created by ravyu on 19/11/20.
//

#pragma once
#include "trigger.h"

namespace adventure {
namespace core {
namespace triggers {
class ItemVisibility : public Trigger {
  std::string item_id_;
  bool visibility_;
  void Execute(core::GameState &gs) override;
 public:
  ItemVisibility(const std::string &item_id, bool visibility);
};
}
}
}
