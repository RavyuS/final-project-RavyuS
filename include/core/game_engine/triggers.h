//
// Created by ravyu on 19/11/20.
//

#pragma once
#include <core/game_engine/game_state.h>

namespace adventure{
namespace core {
namespace triggers {
class Trigger {
 public:
  virtual void Execute(core::GameState &gs) =0;
};

class RoomVisibility : public Trigger {
 public:
  RoomVisibility(const std::string room_id, bool visible);
  std::string room_id_;
  bool visible_;
  void Execute(core::GameState &gs) override;
};

class ItemVisibility : public Trigger {
  std::string item_id_;
  bool visibility_;

 public:
  ItemVisibility(const std::string &item_id, bool visibility);
  void Execute(core::GameState &gs) override;
};
}
}
}