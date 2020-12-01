//
// Created by ravyu on 28/11/20.
//
#pragma once
#include "cinder/gl/gl.h"
#include "core/game_engine/game_state.h"
#include "cinder/app/App.h"
#include "core/game_engine/actions/action.h"


namespace adventure{
namespace gui{


class ScreenManager {

 public:
  enum Screen{
    ROOM,
    ITEM_ACTION,
    ITEM_INTERACT
  };
  ScreenManager(ci::Rectf bbox, core::GameState *gs);


  core::actions::Action* HandleMouseEvent(ci::app::MouseEvent &e);

  void draw();

  void update();

  Screen current_screen;
  ci::Rectf bbox_;

 private:

  core::GameState* gs_;
  core::Item* focus_itm;
  std::map<string,ci::Rectf> screen_objects;

  void draw_room();

  ci::gl::Texture2dRef LoadTexture(string fp);

  void draw_item_menu();
//
//  void draw_item_interact();
//
//  void draw_message();

//  std::stack<Screen> screen_stack_;


};
}
}

