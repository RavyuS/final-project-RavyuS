//
// Created by ravyu on 20/11/20.
//
#pragma once
#include <nlohmann/json.hpp>

#include "core/game_objects/item.h"
#include "core/game_objects/room.h"
#include "item_container.h"
#include "room_container.h"
namespace adventure{
namespace core{
/**
 * JSONLoader handles loading of Game Object configuration from json files. The two main types of game objects are Rooms
 * and items.
 * Uses nlohmann
 */
class JSONLoader{
using Json = nlohmann::json;

 public:
  /**
   * Creates an ItemContainer instance and loads items from the specified json filepath.
   * @param item_fp filepath to the json file containing the items specification
   * @return ItemContainer object with the loaded items stored inside.
   */
  static ItemContainer LoadItems(const std::string& item_fp);

  /**
   * Creates an RoomContainer instance and loads rooms from the specified json filepath.
   * @param room_fp filepath to the json file containing the rooms specification
   * @return RoomContainer object with the loaded rooms stored inside.
   */
  static RoomContainer LoadRooms(const std::string& room_fp);

 private:
  /**
   * Creates a new Room instance dynamically and loads the member variables from the json file
   * @param id The ID of this room instance
   * @param js the Json reader object currently pointing to the room to be loaded.
   * @return pointer to dynamic Room object
   */
  static Room* LoadRoom(const std::string id, Json& js);

  /**
   * Creates a new Item-derived instance dynamically and loads the member variables from the json file.
   * The derived class created is based on the value specified by the "type" key of the item's json specifications.
   * @param id The ID of this item instance
   * @param js the Json reader object currently pointing to the item to be loaded
   * @return pointer to dynamic Item object
   */
  static Item* LoadItem(const std::string id, Json& js);

  /**
   * Generates a TriggerMap based on the data currently being pointed to.
   * @param js the Json reader object currently pointing to the item's Trigger data.
   * @return TriggerMap consisting of item's Trigger configurations.
   */
  static TriggerMap GenerateTriggerMap( Json& js);

  /**
   * Reads trigger data being pointed by Json reader objected and creates a Trigger instance based on the configuration
   * @param js
   * @param t_vec The vector to which the newly initialized trigger will be added to
   */
  static void AddTriggerToVec(Json& js, std::vector<triggers::Trigger*> &t_vec);
};
}
}