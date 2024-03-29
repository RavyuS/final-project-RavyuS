//
// Created by ravyu on 28/11/20.
//

#include "gui/navigation_manager.h"
#include "core/game_engine/actions.h"

namespace adventure{
namespace gui{
NavigationManager::NavigationManager(ci::Rectf bbox, std::shared_ptr<const core::GameState> gs):gs_(gs), bbox_(bbox) {

  cur_rm_ = gs_->current_room_;
  update(ScreenManager::ROOM);
}

core::actions::Action * NavigationManager::HandleMouseEvent(ci::app::MouseEvent &e) {
  for(auto it = room_objs_.begin(); it!=room_objs_.end();it++){
    if(it->second.contains(e.getPos())){
      return new core::actions::MoveTo(it->first->id_);
    }
  }
  return new core::actions::NoAction();
}

void NavigationManager::draw() {
  glm::vec2 title_vec (bbox_.getCenter().x,bbox_.getUpperLeft().y+title_offset_.y/2);
  ci::gl::drawStringCentered("Go to:",title_vec,ci::Color("lightgray"),ci::Font("roboto", 35));

  for(auto it = room_objs_.begin(); it!=room_objs_.end();it++){
//    ci::gl::color(ci::Color("darkgreen"));
    ci::gl::color(ci::Color("darkred"));
    ci::gl::drawSolidRoundedRect(it->second,10);
    ci::gl::color(ci::Color("darkgoldenrod"));
    ci::gl::drawStrokedRoundedRect(it->second,10);
    ci::gl::drawStringCentered(it->first->name_,it->second.getCenter()+glm::vec2 (0,-7),ci::Color("white"),ci::Font("roboto", 20));

  }
  ci::gl::color(ci::Color("gray"));
  ci::gl::drawStrokedRoundedRect(bbox_,10);
}

void NavigationManager::update(const ScreenManager::Screen &cur_scr) {
  room_objs_.clear();
  if(cur_scr != ScreenManager::ROOM) return;
//  else if (cur_rm_ == gs_->current_room_) return;
  else{
    cur_rm_ = gs_->current_room_;
    ci::Rectf def(0,0,0,0);
    int visible_rm_count = 0;
    for(string rm_id : cur_rm_->adjacent_rooms_){
      core::Room *rm = gs_->rc_.GetRoomByID(rm_id);
      if(rm->visible_){
        room_objs_[rm] = def;
        visible_rm_count ++;
      }
    }
    float box_height = (bbox_.getHeight()-title_offset_.y)/(float)visible_rm_count;
    if(box_height>30) box_height=30;
    glm::vec2 top_left = bbox_.getUpperLeft()+title_offset_;
    top_left.y += 50;
    int x_offset = 50;
    top_left.x += x_offset;
    for(auto it = room_objs_.begin(); it!=room_objs_.end();it++){
      it->second = ci::Rectf (top_left,top_left+glm::vec2(bbox_.getWidth()-(float)(x_offset*2),box_height));
      top_left.y += box_height+20;
    }
  }
}
ci::Area NavigationManager::GetIndividualBoxSize(int numRooms) {
  return ci::Area();
}
NavigationManager::~NavigationManager() {

  gs_.reset();
  cur_rm_ = nullptr;
  room_objs_.clear();
}
}
}