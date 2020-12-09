//
// Created by ravyu on 28/11/20.
//

#include "gui/adventure_app.h"
#include "gui/screen_manager.h"
namespace adventure{
namespace gui{
std::string room_fp = "../../../assets/rooms.json";
std::string item_fp = "../../../assets/items.json";
AdventureApp::AdventureApp() {
  ge_ = new core::GameEngine(item_fp,room_fp);
  sm_ = new ScreenManager(screenBox,ge_->GetGameState());
  nm_ = new NavigationManager(navBox,ge_->GetGameState());
  ci::app::setWindowSize(kWindowSize);
}
void AdventureApp::draw() {

  ci::Color8u background_color(255, 246, 148); // light yellow
  ci::gl::clear(background_color);
  ci::gl::color(1,1,1,1);
  sm_->draw();
  nm_->draw();

}

void AdventureApp::update() {
  sm_->update();
  nm_->update(sm_->current_screen);
}

void AdventureApp::mouseDown(ci::app::MouseEvent e) {
  core::actions::Action *ac;
  if(screenBox.contains(e.getPos())){
     ac = sm_->HandleMouseEvent(e);
    ge_->HandleAction(*ac);
  }
  else if (navBox.contains(e.getPos())){
    ac = nm_->HandleMouseEvent(e);
    ge_->HandleAction(*ac);
  }
  delete ac;
  ac = nullptr;
}
void AdventureApp::keyDown(ci::app::KeyEvent e) {
  AppBase::keyDown(e);
  if(e.getCode() == e.KEY_ESCAPE) {
    if (sm_->current_screen == sm_->ITEM_ACTION) sm_->current_screen = sm_->ROOM;
    else if(sm_->current_screen == sm_->ITEM_INTERACT) sm_->current_screen = sm_->ITEM_ACTION;
  }
  else if (e.getCode() == e.KEY_BACKSPACE){
   quit();
  }
}

void AdventureApp::cleanup() {
  delete sm_;
  delete nm_;
  delete ge_;

}
}
}