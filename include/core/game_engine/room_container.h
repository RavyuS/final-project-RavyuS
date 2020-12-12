//
// Created by ravyu on 19/11/20.
//
#pragma once
#include "core/game_objects/room.h"
namespace adventure{
namespace core{
class RoomContainer{
 public:

  /**
   * Returns the room object containing specified id
   * @param id
   * @return Room object
   */
  Room * GetRoomByID(const std::string& id) const;

  /**
   * Returns vector of rooms of specified name. Since names are not unique, multiple rooms may be returned.
   * @param name
   * @return
   */
  std::vector<Room *> GetRoomByName(const std::string& name)const;

  /**
   * Add room to this instance of Room Container. All rooms should ideally be loaded at the very start of the game.
   * @param rm
   */
  void AddRoom(Room *rm);

  /**
   * Clears up memory used by Room objects in the heap.
   */
  void Clear();



 private:
  std::vector<Room*> rooms_;


};
}
}