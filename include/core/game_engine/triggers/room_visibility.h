//
// Created by ravyu on 19/11/20.
//

#pragma once
#include "trigger.h"

namespace adventure {
namespace core {
namespace triggers {
class RoomVisibility : public Trigger {
 public:
  RoomVisibility(const std::string room_id, bool visible);
  std::string room_id_;
  bool visible_;
  void Execute(core::GameState &gs) override;
};
}
}
}