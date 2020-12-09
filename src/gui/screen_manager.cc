//
// Created by ravyu on 28/11/20.
//

#include "gui/screen_manager.h"
#include "cinder/gl/Texture.h"
#include "core/game_engine/actions.h"
namespace adventure{
namespace gui{
ScreenManager::ScreenManager(ci::Rectf bbox, std::shared_ptr<const core::GameState> gs):gs_(gs),bbox_(bbox) {
  current_screen = Screen::ROOM;
}

void ScreenManager::draw() {

  if(current_screen == Screen::ROOM){
    draw_room();
  }
  else if(current_screen == ITEM_ACTION){
    draw_item_menu();
  }
  else if(current_screen == ITEM_INTERACT){
    focus_itm_->Draw(bbox_);
  }
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(bbox_);

}

void ScreenManager::update() {
  screen_objects_.clear();
  if(current_screen == Screen::ROOM){
    update_room();
  }
  if(current_screen == ITEM_ACTION){
    update_item_menu();
  }
}

core::actions::Action* ScreenManager::HandleMouseEvent(ci::app::MouseEvent& e) {
  if(current_screen == ITEM_INTERACT){
    glm::vec2 pos (e.getPos());
    return focus_itm_->UpdateOnClick(pos);
  }
  for(auto it = screen_objects_.cbegin(); it != screen_objects_.cend(); it++){
    if(it->second.contains(e.getPos())){
      if(current_screen == Screen::ROOM){
        current_screen = Screen::ITEM_ACTION;
        focus_itm_ = gs_->ic_.GetItemByID(it->first);
      }
      else if (current_screen == Screen::ITEM_ACTION){
        current_screen = Screen::ROOM;
        return handle_item_action(it->first);
      }

    }
  }

  return new core::actions::NoAction();
}
void ScreenManager::draw_room() {
  core::Room* cur_rm = gs_->current_room_;
  ci::gl::Texture2dRef bg = LoadTexture("rooms/"+cur_rm->img_fp_);
  ci::gl::draw(bg,bbox_);
//  int count = bg.use_count();
  bg.reset();
  for(auto it = screen_objects_.cbegin(); it != screen_objects_.cend(); it++){
    core::Item *item = gs_->ic_.GetItemByID(it->first);
    ci::gl::Texture2dRef obj = LoadTexture("items/"+item->img_fp_);
    ci::gl::draw(obj,it->second);
    obj.reset();
  }

}
void ScreenManager::draw_item_menu() {
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStringCentered("Viewing "+focus_itm_->name_,screen_objects_["item"].getCenter(),ci::Color("black"),ci::Font("roboto", 30));
  ci::gl::drawStrokedRect(screen_objects_["item"]);
  for(auto it = screen_objects_.cbegin(); it != screen_objects_.cend(); it++) {
    if (it->first != "item") {
      ci::gl::drawStringCentered(menu_string_map_[it->first],
                                 it->second.getCenter(),
                                 ci::Color("black"),
                                 ci::Font("roboto", 15));
//      ci::gl::color(ci::Color("black"));
      ci::gl::drawStrokedRect(it->second);
    }
  }

}

void ScreenManager::update_room() {
  core::Room *cur_rm = gs_->current_room_;
  for (auto it = cur_rm->room_items_.cbegin(); it != cur_rm->room_items_.cend(); it++){
    core::Item *itm = gs_->ic_.GetItemByID(it->first);
    if(itm->visible_) {
      ci::gl::Texture2dRef img = LoadTexture("items/" + itm->img_fp_);
      glm::vec2 top_left = it->second + bbox_.getUpperLeft();
      screen_objects_[itm->id_] = ci::Rectf(top_left, top_left + glm::vec2(img->getSize()));
      img.reset();
    }
  }
}

void ScreenManager::update_item_menu() {
  screen_objects_["item"] = ci::Rectf(128,50,738,150);

  const float option_width_half = 200;
  ci::Rectf def(0,0,0,0);
  int count_options = 0;
  if(focus_itm_->can_equip_){
    screen_objects_["equip"] = def;
    menu_string_map_["equip"] = "Equip item";
    count_options++;
  }
  if(focus_itm_->simple_trigger_){
    screen_objects_["simple"] = def;
    menu_string_map_["simple"] = focus_itm_->trigger_button_msg_;
    count_options++;
  }
  if(focus_itm_->unlockable_ &&focus_itm_->locked_ && focus_itm_->CanUnlock(gs_->player_inventory_)){
    screen_objects_["unlock"] = def;
    menu_string_map_["unlock"] = "Unlock with " + gs_->ic_.GetItemByID(focus_itm_->unlock_item_id_)->name_;
    count_options++;
  }
  if(focus_itm_->interactive_){
    screen_objects_["interactive"] = def;
    menu_string_map_["interactive"] = "Interact with item";
    count_options++;
  }
  float gap = 20;
  float option_height = (480 - ((float)count_options*gap))/(float) count_options; // We have a gap of 20 pixels between each option
  if(option_height>50) option_height = 50;
  glm::vec2 starting_top_left (438-option_width_half,200);
  glm::vec2 starting_bot_right (438+option_width_half,200+option_height);
  for(auto it = screen_objects_.begin(); it != screen_objects_.end(); it++){
    if(it->first != "item") {
      it->second = ci::Rectf(starting_top_left, starting_bot_right);
      starting_top_left.y += option_height + gap;
      starting_bot_right.y += option_height + gap;
    }
  }

}

ci::gl::Texture2dRef ScreenManager::LoadTexture(string fp) {
  return ci::gl::Texture::create(ci::loadImage(ci::app::loadAsset(fp)));
}
core::actions::Action* ScreenManager::handle_item_action(const string &action) {
  if(action == "equip"){
    return new core::actions::Equip(focus_itm_->id_);
  }
  else if(action == "interactive"){
    current_screen = ITEM_INTERACT;
    return new core::actions::NoAction();
  }
  else if(action == "unlock"){
    return new core::actions::Unlock(focus_itm_->id_);
  }
}
ScreenManager::~ScreenManager() {
  gs_.reset();
  focus_itm_ = nullptr;
  screen_objects_.clear();
  menu_string_map_.clear();
}

}
}