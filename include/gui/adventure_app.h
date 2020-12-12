//
// Created by ravyu on 28/11/20.
//
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "core/game_engine/game_engine.h"
#include "screen_manager.h"
#include "navigation_manager.h"
#include "inventory_manager.h"

namespace adventure{
namespace gui{
/**
 * The main cinder app.
 * Defines the boundaries within which the user interface elements exist in.
 * Handles user interaction and pass
 */
 class AdventureApp: public ci::app::App {
  public:
   /**
    * Initializes the Cinder App along with the user interface managers and the Game Engine.
    */
   AdventureApp();

   /**
    * Override for cinder's draw function
    */
   void draw() override;

    /**
     * Override for cinder's update function
     */
   void update() override;

   /**
    * Override for Cinder's mouseDown function. Any mouseDown event will generate an Action object that will
    * be passed to the App's Game Engine to handle.
    * @param e
    */
   void mouseDown(ci::app::MouseEvent e) override;

  /**
   *  Override for Cinder's keyDown function
   * @param e
   */
   void keyDown(ci::app::KeyEvent e) override;

   /**
    * Override for Cinder's cleanup function. Frees up memory occupied by the Game Engine and the UI elements
    */
   void cleanup() override;

   // Window boundaries for the different UI elements
   const glm::vec2 kWindowSize = glm::vec2 (1280,720); //main window size
   const ci::Rectf screenBox = ci::Rectf (glm::vec2(20,20),glm::vec2(895,700));
   const ci::Rectf invBox = ci::Rectf (glm::vec2(910,20),glm::vec2(1260,360));
   const ci::Rectf navBox = ci::Rectf(glm::vec2(910,380),glm::vec2(1260,700));



  private:
   core::GameEngine* ge_;
   ScreenManager *sm_;
   NavigationManager *nm_;
   InventoryManager *im_;


};
}
}



