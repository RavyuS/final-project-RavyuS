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
typedef std::map<string, std::vector<triggers::Trigger>> TriggerMap;
struct Item{
public:
    Item(const string& id);
    /**
     * Basic Item properties
     */
    string name_;
    string id_;
    string img_fp_;
    TriggerMap trigger_map_; //Item may contain multiple sets of triggers depending on attributes
    bool hidden_;

    /**
     * Item attributes here. Attributes are by default false unless explicitly declared otherwise;
     */

    bool can_equip_ = false;
    bool unlockable_ = false;
    bool item_interactive_ = false;
    bool simple_trigger_ = false; //when you just want the item to trigger something on a button press;

    /**
     * Properties for each attribute declared here.
     * Should only be initialized and accessed if that attribute is true;
     */

     // Unlockable item properties.
     bool locked_ = true;
     string unlock_item_ID_, post_unlock_msg_;
     bool CanUnlock(std::vector<string> player_inventory);
     void Unlock();

     // Interactive item properties.
     virtual void draw();

     //Simple Trigger item properties
     string trigger_button_msg_, post_trigger_msg_;
     void simple_trigger();


};
}
}