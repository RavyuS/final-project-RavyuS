//
// Created by ravyu on 24/11/20.
//

#include "core/game_objects/basic_item.h"
#include "core/game_engine/triggers/trigger.h"

namespace adventure{
namespace core{
BasicItem::BasicItem(const string &id) : Item(id){};

Item::Item(const string &id):id_(id) {}
void Item::SetBasicProperties(string name, string img_fp, TriggerMap trigger_map, bool hidden) {
  name_ = name;
  img_fp_ = img_fp;
  trigger_map_ = trigger_map;
  visible_ = hidden;
}

void Item::AddTriggerSet(const string &label, std::vector<triggers::Trigger*> &triggers) {
  trigger_map_.insert(std::pair<string,std::vector<triggers::Trigger*>>(label,triggers));
}

void Item::SetUnlockable(string unlock_item_id, string post_unlock_msg) {
  unlockable_ = true;
  unlock_item_id_ = unlock_item_id;
  post_unlock_msg_ = post_unlock_msg;
}
bool Item::CanUnlock(std::vector<Item*> player_inventory) {

  for (Item *itm : player_inventory){
    if (itm->id_ == unlock_item_id_) return true;
  }
  return false;
}
/**
 * Basic Item shouldn't have Interactive-related functions declared.
 */
void BasicItem::Draw(ci::Rectf &boundaries) {};
actions::Action * BasicItem::UpdateOnClick(glm::vec2 &click_coords) {}
}
}