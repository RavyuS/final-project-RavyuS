//
// Created by ravyu on 26/11/20.
//

#include "core/game_objects/interactive_items/static_image.h"
namespace adventure{
namespace core{
StaticImage::StaticImage(const string &id, const string &img_fp):Item(id) {
  display_img_fp_ = img_fp;
  interactive_ = true;
}
void StaticImage::Draw() {

}

}
}