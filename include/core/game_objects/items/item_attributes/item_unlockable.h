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

  bool locked = true;
  std::string unlock_item;
  virtual bool CanUnlock(std::vector<std::string> player_inventory);
  virtual void Unlock();

};
}
}