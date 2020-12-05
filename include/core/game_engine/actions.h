//
// Created by ravyu on 19/11/20.
//

#pragma once

#include <core/game_engine/game_state.h>
namespace adventure{
namespace core{
namespace actions {
class Action {
 public:
  virtual void Execute(std::shared_ptr<core::GameState> gs) =0 ;
};

class Equip : public Action{
 public:
  Equip(std::string item_ID);
  void Execute(std::shared_ptr<core::GameState> gs) override;

 private:
  std::string item_id_;
};

class MoveTo : public Action {
 public:
  MoveTo(std::string dest_ID);
  void Execute(std::shared_ptr<core::GameState> gs) override;

 private:
  std::string dest_ID_;
};

class  NoAction: public Action {
 public:
  NoAction();
  void Execute(std::shared_ptr<core::GameState> gs) override;


};

class Unlock : public Action {
 public:
  Unlock(const string& item_id);
  void Execute(std::shared_ptr<core::GameState> gs) override;

 private:
  string item_id_;
};

class UnlockKeypad : public Action {
 public:
  UnlockKeypad(const string& item_id);
  void Execute(std::shared_ptr<core::GameState> gs) override;

 private:
  string item_id_;
};

} //namespace actions
} //namespace core
} //namespace adventure