//
// Created by ravyu on 19/11/20.
//
#pragma once

#include <core/game_objects/item.h>


namespace adventure{
namespace engine{
class ItemContainer{
 public:
  /**
   * Returns the Item object containing specified id
   * @param id
   * @return Room object
   */

  objects::Item GetItemByID(const std::string& id);

  /**
   * Returns vector of Items of specified name. Since names are not unique, multiple rooms may be returned.
   * @param name
   * @return
   */
  std::vector<objects::Item> GetItemByName(const std::string& name);

  /**
   * Add item to this instance of Item Container. All items should ideally be loaded at the very start of the game.
   * @param item
   */
  void AddItem(objects::Item &item);

 private:
  std::vector<objects::Item> items_;
};
}
}