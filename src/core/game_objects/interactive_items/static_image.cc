//
// Created by ravyu on 26/11/20.
//

#include "core/game_objects/interactive_items/static_image.h"
#include "core/game_engine/actions/no_action.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
namespace adventure{
namespace core{
StaticImage::StaticImage(const string &id, const string &img_fp): Item(id) {
  display_img_fp_ = img_fp;
  interactive_ = true;
}
void StaticImage::Draw(ci::Rectf &boundaries) {
  ci::gl::Texture2dRef image = ci::gl::Texture::create(ci::loadImage(ci::app::loadAsset("items/"+display_img_fp_)));
  float width_offset = image->getWidth()/2;
  float height_offset = image->getHeight()/2;
  glm::vec2 top_left = boundaries.getCenter();
  top_left.x -= width_offset;
  top_left.y -= height_offset;
  ci::gl::draw(image,ci::Rectf(top_left,top_left+glm::vec2(image->getSize())));

}
actions::Action * StaticImage::UpdateOnClick(glm::vec2 &click_coords) {
  return new actions::NoAction();
};
}
}