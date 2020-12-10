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

//Handle errors related to circular dependencies
namespace triggers {
class Trigger;
}
namespace actions{
class Action;
}

typedef std::map<string, std::vector<triggers::Trigger*>> TriggerMap;

/**
 * The Item interface specifies the information an in-game item is to contain. Apart from the BasicItem class, all
 * derived classes should only differ by their definition of the Draw and UpdateOnClick functions (and consequentially have
 * their interactive attribute set to True at some point in the game). Any extra member variables declared in derived classes
 * should only be used in context of either of the aforementioned functions.
 *
 */
class Item{
public:
  /**
   * Initializes item object of a unique string ID
   * @param id a unique string ID. ID must be unique to the item.
   */
    Item(const string& id);

    /**
     * Explicit destructor for item. Handles deallocation of memory in TriggerMap.
     * Derived classes should extend this function rather than override it completely.
     */
    virtual ~Item();
    /**
     * Basic Item properties
     */
    string name_;
    string id_; // each item ID must be unique.
    string img_fp_; // filepath to the item's texture. Should be relative to "assets/items/"

    /**
     * The Trigger Map contains a map of trigger vectors, indexed by the event that triggers them. Ideally, for every
     * attribute an item has, there should be a trigger vector associated with it.
     *
     * Example: If unlockable_ is true, trigger_map_["unlockable"] should contain the corresponding Trigger vector.
     *
     */
    TriggerMap trigger_map_; //Item may contain multiple sets of triggers depending on attributes

    bool visible_; // determines if item is supposed to be visible to the user in the game world.

    /**
     * Set the basic item properties.
     * @param name Pretty string for item. This is the name that should be visible to the user
     * @param img_fp Filepath to the item's texture image.
     * @param trigger_map Map of Trigger vectors.
     * @param hidden boolean flag that
     */
    void SetBasicProperties(const string &name, const string &img_fp, TriggerMap &trigger_map, bool hidden);

    /**
     * Adds a trigger vector to Item's trigger map with the specified label as the index. If the label is already used,
     * the trigger vector will be overriden.
     * @param label string which the trigger vectors will be indexed to
     * @param triggers
     */
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
     /**
      * Helper function to set the item to unlockable along with the required information
      * @param unlock_item_id The ID of the item that needs to be present in the user's inventory for the unlock to occur
      * @param post_unlock_msg Message that will be displayed upon unlocking the item.
      */
     void SetUnlockable(string unlock_item_id, string post_unlock_msg);
     bool locked_ = true;
     string unlock_item_id_, post_unlock_msg_;

     /**
      * Checks if the user possesses the item needed to unlock this Item
      * @param player_inventory
      * @return true if the item can be unlocked.
      */
     bool CanUnlock(std::vector<Item*> player_inventory);


     // Interactive item properties.
     /**
      * Renders the Item's interactive features on a screen within the specified boundaries
      * @param boundaries
      */
     virtual void Draw(ci::Rectf &boundaries) =0;

     /**
      * handles user input during the interactive mode and returns a corresponding Action object
      * @param click_coords Coordinates of the mouse click
      * @return Action object containing the appropriate response.
      */
     virtual core::actions::Action * UpdateOnClick(glm::vec2 &click_coords) =0;

     //Simple Trigger item properties
     string trigger_button_msg_, post_trigger_msg_;



};
}
}