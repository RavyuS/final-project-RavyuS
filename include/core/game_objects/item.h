//
// Created by ravyu on 19/11/20.
//
#pragma once
#include <string>
#include <vector>
#include <map>
#include "cinder/gl/gl.h"


namespace adventure{
using std::string;

namespace core{

//Handle errors related to circular dependancies
namespace triggers {
class Trigger;
}
namespace actions{
class Action;
}

typedef std::map<string, std::vector<triggers::Trigger*>> TriggerMap;

class Item{
public:
    Item(const string& id);
    /**
     * Basic Item properties
     */
    string name_;
    string id_;
    string img_fp_;

    TriggerMap trigger_map_; //Item may contain multiple sets of triggers depending on attributes
    bool visible_;

    void SetBasicProperties(string name, string img_fp, TriggerMap trigger_map, bool hidden);

    void AddTriggerSet(const string& label, std::vector<triggers::Trigger*> &triggers);
    /**
     * Item attributes here. Attributes are by default false unless explicitly declared otherwise;
     */

    bool can_equip_ = false;
    bool unlockable_ = false;
    bool interactive_ = false;
    bool simple_trigger_ = false; //when you just want the item to trigger something on a button press;

    /**
     * Properties for each attribute declared here.
     * Should only be initialized and accessed if that attribute is true;
     */

     // Unlockable item properties.
     void SetUnlockable(string unlock_item_id, string post_unlock_msg);
     bool locked_ = true;
     string unlock_item_id_, post_unlock_msg_;
     bool CanUnlock(std::vector<Item*> player_inventory);


     // Interactive item properties.
     virtual void Draw(ci::Rectf &boundaries) =0;
     virtual core::actions::Action * UpdateOnClick(glm::vec2 &click_coords) =0;

     //Simple Trigger item properties
     string trigger_button_msg_, post_trigger_msg_;



};
}
}