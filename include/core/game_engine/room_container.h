//
// Created by ravyu on 19/11/20.
//
#pragma once
#ifndef FINAL_PROJECT_RAVYUS_ROOM_CONTAINER_H
#define FINAL_PROJECT_RAVYUS_ROOM_CONTAINER_H

#endif  // FINAL_PROJECT_RAVYUS_ROOM_CONTAINER_H

#include "core/game_objects/room.h"
namespace adventure{
namespace engine{
class RoomContainer{
 public:

  /**
   * Returns the room object containing specified id
   * @param id
   * @return Room object
   */
  objects::Room GetRoomByID(const std::string& id);

  /**
   * Returns vector of rooms of specified name. Since names are not unique, multiple rooms may be returned.
   * @param name
   * @return
   */
  std::vector<objects::Room> GetRoomByName(const std::string& name);

  /**
   * Add room to this instance of Room Container. All rooms should ideally be loaded at the very start of the game.
   * @param rm
   */
  void AddRoom(objects::Room rm);

 private:
  std::vector<objects::Room> rooms_;


};
}
}