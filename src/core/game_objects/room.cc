//
// Created by ravyu on 25/11/20.
//

#include "core/game_objects/room.h"

namespace adventure {
namespace core {
Room::Room(const string& id):id_(id){};
Room::Room(const string &name, const string &id, std::map<string, glm::vec2> &room_items, const string &img_fp):
name_(name),id_(id),room_items_(room_items),img_fp_(img_fp){}


}
}