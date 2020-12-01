//
// Created by ravyu on 28/11/20.
//

#include "gui/adventure_app.h"
#include "gui/screen_manager.h"
namespace adventure{
namespace gui{
std::string room_fp = "../../../assets/rooms.json";
std::string item_fp = "../../../assets/items.json";
AdventureApp::AdventureApp():ge_(item_fp, room_fp) {
  sm_ = new ScreenManager(screenBox,ge_.GetGameState());
  ci::app::setWindowSize(kWindowSize);
}
void AdventureApp::draw() {

  ci::Color8u background_color(255, 246, 148); // light yellow
  ci::gl::clear(background_color);
  ci::gl::color(1,1,1,1);
  sm_->draw();

}

void AdventureApp::setup() {}

void AdventureApp::update() {
  sm_->update();
}

void AdventureApp::mouseDown(ci::app::MouseEvent e) {

  if(screenBox.contains(e.getPos())) sm_->HandleMouseEvent(e);
}
void AdventureApp::keyDown(ci::app::KeyEvent e) {
  AppBase::keyDown(e);
  if(e.getCode() == e.KEY_ESCAPE) {
    if (sm_->current_screen == sm_->ITEM_ACTION) sm_->current_screen = sm_->ROOM;
  }
}

}
}