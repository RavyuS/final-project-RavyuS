//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_ROOM_VISIBILITY_H
#define FINAL_PROJECT_RAVYUS_ROOM_VISIBILITY_H
#include "trigger.h"

namespace adventure{
namespace triggers{
struct RoomVisibility : public Trigger{
  RoomVisibility(const std::string room_id, bool visible);
  std::string room_id_;
  bool visible_;
  void Execute(engine::GameState &gs) override;
};
}
}
#endif  // FINAL_PROJECT_RAVYUS_ROOM_VISIBILITY_H