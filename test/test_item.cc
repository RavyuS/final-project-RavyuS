//
// Created by ravyu on 9/12/20.
//


#include "core/game_objects/basic_item.h"
#include "core/game_engine/triggers.h"
#include <catch2/catch.hpp>
using namespace adventure::core;
TEST_CASE("Item tests"){
  SECTION("Initialization"){
     BasicItem it("test");
     TriggerMap test_tm;
     it.SetBasicProperties("Test Name", "test.png", test_tm, true);
     REQUIRE(it.id_ == "test");
     REQUIRE(it.name_ == "Test Name");
     REQUIRE(it.img_fp_ == "test.png");
     REQUIRE(it.visible_ == true);
  }
  SECTION("Trigger Map tests"){
    BasicItem it("test");
    TriggerMap test_tm;
    it.SetBasicProperties("Test Name", "test.png", test_tm, true);
    std::vector<triggers::Trigger*> test_1  { new triggers::RoomVisibility("blank_rm",true)};
    std::vector<triggers::Trigger*> test_2  { new triggers::ItemVisibility("blank_itm",false), new triggers::RoomVisibility("second_blank_rm",false)};
    it.AddTriggerSet("test_1",test_1);
    it.AddTriggerSet("test_2", test_2);
    REQUIRE(it.trigger_map_["test_1"].size() == 1);
    REQUIRE(it.trigger_map_["test_2"].size() == 2);
  }

  SECTION("Item unlockability tests"){
    BasicItem it("test");
    TriggerMap test_tm;
    it.SetBasicProperties("Test Name", "test.png", test_tm, true);
    it.SetUnlockable("test_key","test_message");
    REQUIRE(it.unlockable_);
    std::vector<Item*> test_player_inventory {new BasicItem("test_key")};
    std::vector<Item*> test_player_inventory_false {new BasicItem("test_false_key")};
    REQUIRE(it.CanUnlock(test_player_inventory));
    REQUIRE_FALSE(it.CanUnlock(test_player_inventory_false));
  }
}