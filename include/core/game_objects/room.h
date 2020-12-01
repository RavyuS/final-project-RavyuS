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
class Room {
 public:
  Room() = default;
  Room(const string &id);
  Room(const string &name, const string &id,
       std::map<string, glm::vec2> &room_items, const string &img_fp);
  string name_, id_;
  std::map<string, glm::vec2> room_items_;
  std::vector<string> adjacent_rooms_;
  string img_fp_;
  bool visible_;
};
}
}