//
// Created by ravyu on 19/11/20.
//

#ifndef FINAL_PROJECT_RAVYUS_ITEM_UNLOCKABLE_H
#define FINAL_PROJECT_RAVYUS_ITEM_UNLOCKABLE_H

#endif  // FINAL_PROJECT_RAVYUS_ITEM_UNLOCKABLE_H
#include <string>
#include <vector>
namespace adventure{
namespace objects{
struct Unlockable{
 public:
  bool locked = true;
  std::string unlock_item_ID_;
  std::string unlock_msg_;
  bool CanUnlock(std::vector<std::string> player_inventory);
  void Unlock();

};
}
}