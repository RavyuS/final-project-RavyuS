//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_MOVE_TO_H
#define FINAL_PROJECT_RAVYUS_MOVE_TO_H

#endif  // FINAL_PROJECT_RAVYUS_MOVE_TO_H
#include "action.h"

namespace adventure{
namespace actions{
class MoveTo: public Action{
 public:
  MoveTo(std::string dest_ID);
  void Execute(engine::GameState& gs) override;

 private:
  std::string dest_ID_;
};
}
}