//
// Created by ravyu on 19/11/20.
//
#pragma once
#include "action.h"

namespace adventure{
namespace core{
namespace actions{
class Equip : public Action{
 public:
  Equip(std::string item_ID);
  void Execute(core::GameState& gs) override;

 private:
  std::string item_id_;
};
}
}}