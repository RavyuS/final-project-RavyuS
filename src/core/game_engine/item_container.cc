//
// Created by ravyu on 25/11/20.
//

#include "core/game_engine/item_container.h"

namespace adventure{
namespace engine{
objects::Item ItemContainer::GetItemByID(const std::string &id) {
  for(objects::Item &itm : items_){
    if(itm.id_ == id) return itm;
  }
}
std::vector<objects::Item> ItemContainer::GetItemByName(const std::string &name) {
  std::vector<objects::Item> itms;
  for(objects::Item &itm : items_){
    if(itm.name_ == name) itms.push_back(itm);
  }
  return itms;
}
void ItemContainer::AddItem(objects::Item &item) {
  items_.push_back(item);
}
}
}