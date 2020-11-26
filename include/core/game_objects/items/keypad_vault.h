//
// Created by ravyu on 24/11/20.
//

#include "../item.h"
namespace adventure{
namespace objects{
class KeypadVault : public Item {
 public:
  KeypadVault(const string& id);
  void Draw();
  void UpdateOnClick(glm::vec2 click_coords);
};
}
}
