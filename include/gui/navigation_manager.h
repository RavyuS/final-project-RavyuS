//
// Created by ravyu on 28/11/20.
//
#pragma once
#include "cinder/gl/gl.h"
#include "core/game_engine/game_state.h"
#include "cinder/app/App.h"
#include "core/game_engine/actions.h"
#include "screen_manager.h"

namespace adventure{
namespace gui{
class NavigationManager {
 public:
  NavigationManager(ci::Rectf bbox, core::GameState *gs);

  core::actions::Action* HandleMouseEvent(ci::app::MouseEvent &e);

  void draw();

  void update(ScreenManager::Screen cur_scr);

  ci::Rectf bbox_;

 private:
  core::Room *cur_rm_;
  std::map<core::Room* ,ci::Rectf> room_objs_;
  core::GameState *gs_;
  glm::vec2 title_offset_ = glm::vec2 (0,120);
  ci::Area GetIndividualBoxSize(int numRooms);
};
}
}


