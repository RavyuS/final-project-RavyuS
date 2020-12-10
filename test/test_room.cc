//
// Created by ravyu on 9/12/20.
//
#include "core/game_objects/room.h"
#include <catch2/catch.hpp>
using namespace adventure::core;

TEST_CASE("Room tests"){
  SECTION("Initialization tests"){
    Room test ("test");
    REQUIRE(test.id_ == "test");
    glm::vec2 test_vec(0,0);
    std::map<string,glm::vec2> rm_itms;
    rm_itms["test_itm"] = test_vec;
    std::vector<string> adj_rooms {"test_adj"};
    test.SetBasicProperties("Test Name", "test.png", rm_itms,adj_rooms,true);
    REQUIRE(test.visible_);
    REQUIRE(test.name_ == "Test Name");
    REQUIRE(test.img_fp_ == "test.png");
    REQUIRE(test.adjacent_rooms_[0] == "test_adj");
    REQUIRE(test.room_items_["test_itm"] == test_vec);

  }
}
