//
// Created by ravyu on 19/11/20.
//
#pragma once

#include <core/game_objects/item.h>

namespace adventure{
namespace core{
class ItemContainer{
 public:
  /**
   * Returns the Item object containing specified id
   * @param id
   * @return Room object
   */

  Item *GetItemByID(const std::string& id) const;

  /**
   * Returns vector of Items of specified name. Since names are not unique, multiple rooms may be returned.
   * @param name
   * @return
   */
  std::vector<Item*> GetItemByName(const std::string& name) const;

  /**
   * Add item to this instance of Item Container. All items should ideally be loaded at the very start of the game.
   * @param item
   */
  void AddItem(Item *item);

  /**
   * Clears up memory used by Room objects in the heap.
   */
  void Clear();

 private:
  std::vector<Item*> items_;
};
}
}