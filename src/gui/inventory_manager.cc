//
// Created by ravyu on 28/11/20.
//

#include "gui/inventory_manager.h"
#include "core/game_objects/item.h"
namespace adventure::gui{
InventoryManager::InventoryManager(ci::Rectf bbox, std::shared_ptr<const core::GameState> gs):bbox_(bbox),gs_(gs) {

}
InventoryManager::~InventoryManager() {
  gs_.reset();
}

void InventoryManager::draw() {
  glm::vec2 string_vec (bbox_.getCenter().x, bbox_.getUpperLeft().y+title_offset_.y/2);
  ci::gl::drawStringCentered("Inventory:", string_vec, ci::Color("lightgray"), ci::Font("roboto", 35));
  string_vec.y += 50;
  for(core::Item *itm: gs_->player_inventory_){
    ci::gl::drawStringCentered(itm->name_,string_vec,ci::Color("grey"), ci::Font("roboto", 20));
    string_vec.y +=30;
  }
  ci::gl::color(ci::Color("grey"));
  ci::gl::drawStrokedRect(bbox_);
}

}
