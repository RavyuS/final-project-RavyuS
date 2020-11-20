//
// Created by ravyu on 19/11/20.
//
#pragma once
#include <string>
#include <map>
#include "cinder/gl/gl.h"
namespace adventure{
namespace objects{
using std::string;
struct Room{
 public:
  string name, id;
  std::map<string,glm::vec2> room_items_;
  string img_fp;
};
}
}