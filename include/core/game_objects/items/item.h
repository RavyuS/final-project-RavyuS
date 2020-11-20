//
// Created by ravyu on 19/11/20.
//
#pragma once
#include <string>
#include <vector>
#include <map>
#include "core/game_engine/triggers/trigger.h"
namespace adventure{
namespace objects{
using std::string;
struct Item{
public:
    string name;
    string id;
    bool hidden;
    bool can_equip;
    string img_fp;
    std::map<string , std::vector<triggers::Trigger>> trigger_map_; //Item may contain multiple sets of triggers depending on attributes


};
}
}