//
// Created by ravyu on 28/11/20.
//
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "core/game_engine/game_engine.h"
#include "screen_manager.h"

namespace adventure{
namespace gui{
 class AdventureApp: public ci::app::App {
  public:
   AdventureApp();

   void draw() override;

   void setup() override;

   void update() override;

   void mouseDown(ci::app::MouseEvent e) override;

   void keyDown(ci::app::KeyEvent e) override;

   const glm::vec2 kWindowSize = glm::vec2 (1280,720);
   const ci::Rectf screenBox = ci::Rectf (glm::vec2(20,20),glm::vec2(895,700));
   const ci::Rectf invBox = ci::Rectf (glm::vec2(910,20),glm::vec2(1260,470));
   const ci::Rectf navBox = ci::Rectf(glm::vec2(910,490),glm::vec2(1260,700));



  private:
   core::GameEngine ge_;
   ScreenManager *sm_;




};
}
}



