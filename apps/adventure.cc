//
// Created by ravyu on 28/11/20.
//

#include "gui/adventure_app.h"

using adventure::gui::AdventureApp;

void prepareSettings(AdventureApp::Settings* settings){
  settings->setResizable(false);
}

CINDER_APP(AdventureApp,ci::app::RendererGl,prepareSettings);