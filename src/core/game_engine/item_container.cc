//
// Created by ravyu on 25/11/20.
//
#include "core/game_objects/item.h"
#include "core/game_engine/item_container.h"

namespace adventure{
namespace core{
Item* ItemContainer::GetItemByID(const std::string &id) {
  for(core::Item *itm : items_){
    if(itm->id_ == id) return itm;
  }
}
std::vector<Item*> ItemContainer::GetItemByName(const std::string &name) {
  std::vector<core::Item*> itms;
  for(core::Item *itm : items_){
    if(itm->name_ == name) itms.push_back(itm);
  }
  return itms;
}
void ItemContainer::AddItem(Item* item) {
  items_.push_back(item);
}
}
}