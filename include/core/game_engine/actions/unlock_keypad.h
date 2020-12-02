//
// Created by ravyu on 1/12/20.
//

#include "action.h"
namespace adventure {
namespace core {
namespace actions {
class UnlockKeypad : public Action {
 public:
  UnlockKeypad(const string& item_id);
  void Execute(core::GameState &gs) override;

 private:
  string item_id_;
};
}
}

}