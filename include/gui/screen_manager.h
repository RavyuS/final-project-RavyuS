//
// Created by ravyu on 28/11/20.
//
#pragma once
#include "cinder/gl/gl.h"
#include "core/game_engine/game_state.h"
#include "cinder/app/App.h"
#include "core/game_engine/actions.h"


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
  core::Item* focus_itm_;
  std::map<string,ci::Rectf> screen_objects_;
  std::map<string,string> menu_string_map_;

  void draw_room();

  void draw_item_menu();

  void update_item_menu();

  ci::gl::Texture2dRef LoadTexture(string fp);

  core::actions::Action* handle_item_action(const string& action);
//
//  void draw_item_interact();
//
//  void draw_message();

//  std::stack<Screen> screen_stack_;


};
}
}

