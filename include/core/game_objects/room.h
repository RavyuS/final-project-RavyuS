//
// Created by ravyu on 19/11/20.
//
#pragma once
#include <string>
#include <map>
#include "cinder/gl/gl.h"
namespace adventure {
namespace core {
using std::string;
/**
 * The Room container class contains information about the individual room's configuration
 */
class Room {
 public:
  Room() = default;

  /**
   * Overloaded constructor creates an instance with a unique ID
   * @param id A unique identifier for the instance. Every room in a Game World must have a unique ID.
   */
  Room(const string &id);


  string name_, id_;
  /**
   * The room_items_ map contains the items that this room instance will contain at game start. The string key
   * is the item's id while the value (type glm::vec2) indicates the top left coordinate from which the item will be
   * rendered relative to.
   */
  std::map<string, glm::vec2> room_items_;

  std::vector<string> adjacent_rooms_; //list of ids of rooms adjacent to this instance
  string img_fp_; // filepath to room texture (note: default texture size should be 875x680)
  bool visible_; // boolean flag that determines if the room should be accessible by the user (for example, via a navigation interface)
};
}
}