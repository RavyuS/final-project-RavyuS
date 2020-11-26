//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_PICKUP_ITEM_H
#define FINAL_PROJECT_RAVYUS_PICKUP_ITEM_H
#include "action.h"
#endif  // FINAL_PROJECT_RAVYUS_PICKUP_ITEM_H
namespace adventure{
namespace actions{
class Equip : public Action{
 public:
  Equip(std::string& item_ID);
  void Execute(engine::GameState& gs) override;

 private:
  std::string item_id_;
};
}
}