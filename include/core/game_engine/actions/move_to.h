//
// Created by ravyu on 19/11/20.
//
#pragma once
#include <string>
#include "action.h"

namespace adventure {
namespace core {
namespace actions {
class MoveTo : public Action {
 public:
  MoveTo(std::string dest_ID);
  void Execute(core::GameState &gs) override;

 private:
  std::string dest_ID_;
};
}
}
}