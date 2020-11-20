//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_ROOM_VISIBILITY_H
#define FINAL_PROJECT_RAVYUS_ROOM_VISIBILITY_H
#include "trigger.h"

namespace adventure{
namespace triggers{
struct RoomVisibility : public Trigger{
  std::string room_ID;
  bool hide;
  void Execute(engine::GameState &gs) override;
};
}
}
#endif  // FINAL_PROJECT_RAVYUS_ROOM_VISIBILITY_H