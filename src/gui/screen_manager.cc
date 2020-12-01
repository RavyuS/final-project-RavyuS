//
// Created by ravyu on 28/11/20.
//

#include "gui/screen_manager.h"
#include "cinder/gl/Texture.h"
#include "core/game_engine/actions/no_action.h"
namespace adventure{
namespace gui{
ScreenManager::ScreenManager(ci::Rectf bbox, core::GameState *gs):gs_(gs),bbox_(bbox) {
  current_screen = Screen::ROOM;
}

void ScreenManager::draw() {

  if(current_screen == Screen::ROOM){
    draw_room();
  }
  else if(current_screen == ITEM_ACTION){
    draw_item_menu();
  }

//  ci::gl::color(ci::Color("black"));
//  ci::gl::drawStrokedRect(bbox_);
}

void ScreenManager::update() {
  screen_objects.clear();
  if(current_screen == Screen::ROOM){
    core::Room *cur_rm = gs_->current_room_;
    for (auto it = cur_rm->room_items_.cbegin(); it != cur_rm->room_items_.cend(); it++){
      core::Item itm = gs_->ic_.GetItemByID(it->first);
      ci::gl::Texture2dRef img = LoadTexture("items/"+itm.img_fp_);
      glm::vec2 top_left = it->second + bbox_.getUpperLeft();
      screen_objects[itm.id_] = ci::Rectf(top_left,top_left+glm::vec2 (img->getSize()));
      img.reset();
    }
  }
  if(current_screen == ITEM_ACTION){
    screen_objects["hi"] = ci::Rectf (glm::vec2(100,150),glm::vec2(675,200));
  }
}

core::actions::Action* ScreenManager::HandleMouseEvent(ci::app::MouseEvent& e) {
  for(auto it = screen_objects.cbegin(); it != screen_objects.cend();it++){
    if(it->second.contains(e.getPos())){
      if(current_screen == Screen::ROOM){
        current_screen = Screen::ITEM_ACTION;
        focus_itm = &gs_->ic_.GetItemByID(it->first);
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
  for(auto it = screen_objects.cbegin(); it != screen_objects.cend();it++){
    core::Item item = gs_->ic_.GetItemByID(it->first);
    ci::gl::Texture2dRef obj = LoadTexture("items/"+item.img_fp_);
    ci::gl::draw(obj,it->second);
    obj.reset();
  }

}
void ScreenManager::draw_item_menu() {
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(bbox_);
  for(auto it = screen_objects.cbegin(); it != screen_objects.cend();it++){
    ci::gl::drawStringCentered("hi",it->second.getCenter(),ci::Color("white"));
  }

}

ci::gl::Texture2dRef ScreenManager::LoadTexture(string fp) {
  return ci::gl::Texture::create(ci::loadImage(ci::app::loadAsset(fp)));
}
}
}