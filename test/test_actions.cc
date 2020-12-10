//
// Created by ravyu on 9/12/20.
//
#include "core/game_engine/actions.h"
#include "core/game_engine/game_engine.h"
#include <catch2/catch.hpp>
using namespace adventure::core;
TEST_CASE("Action tests"){
  std::string room_fp = "../../../assets/rooms.json";
  std::string item_fp = "../../../assets/items.json";
  SECTION("MoveTo tests"){
    GameEngine *test_ge = new GameEngine(item_fp, room_fp);
    REQUIRE(test_ge->GetGameState()->current_room_->id_ == "living_room");
    actions::Action *test_move = new actions::MoveTo("bathroom");
    test_ge->HandleAction(*test_move);
    REQUIRE(test_ge->GetGameState()->current_room_->id_ == "bathroom");
    actions::Action *test_illegal_move = new actions::MoveTo("attic");
    REQUIRE_THROWS_AS(test_ge->HandleAction(*test_illegal_move),std::invalid_argument);

  }

  SECTION("Equip tests"){
    GameEngine test_ge(item_fp, room_fp);
    REQUIRE(test_ge.GetGameState()->player_inventory_.size() == 0);
    test_ge.HandleAction(* new actions::MoveTo("bathroom"));
    test_ge.HandleAction(*new actions::Equip("usb_key"));
    REQUIRE(test_ge.GetGameState()->player_inventory_[0]->id_ == "usb_key");
    REQUIRE(test_ge.GetGameState()->player_inventory_.size() == 1);
    REQUIRE_THROWS_AS(test_ge.HandleAction(*new actions::Equip("note_usb")),std::invalid_argument);
  }

  SECTION("Unlock tests"){
    SECTION("Unlock requirement met") {
      GameEngine test_ge(item_fp, room_fp);
      test_ge.HandleAction(*new actions::Equip("usb_key"));
      test_ge.HandleAction(*new actions::MoveTo("study"));
      REQUIRE(test_ge.GetGameState()->ic_.GetItemByID("computer")->locked_);
      test_ge.HandleAction(*new actions::Unlock("computer"));
      REQUIRE_FALSE(test_ge.GetGameState()->ic_.GetItemByID("computer")->locked_);
    }
    SECTION("Unlock requirements not met"){
      GameEngine test_ge(item_fp, room_fp);
      test_ge.HandleAction(*new actions::MoveTo("study"));
      REQUIRE(test_ge.GetGameState()->ic_.GetItemByID("computer")->locked_);
      REQUIRE_THROWS_AS(test_ge.HandleAction(*new actions::Unlock("computer")),std::invalid_argument);
    }
  }

}