//
// Created by ravyu on 25/11/20.
//

#include "core/game_objects/room.h"

namespace adventure {
namespace core {
Room::Room(const string& id):id_(id){}
void Room::SetBasicProperties(const string &name,
                              const string &img_fp,
                              std::map<string, glm::vec2> &room_items,
                              std::vector<string> adjacent_rooms,
                              bool visible) {
  name_ =name;
  img_fp_ = img_fp;
  room_items_ = room_items;
  adjacent_rooms_ = adjacent_rooms;
  visible_ = visible;

};


}
}