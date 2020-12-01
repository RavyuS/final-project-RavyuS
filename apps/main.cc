//
// Created by ravyu on 19/11/20.
//
#include <string>
#include "core/game_engine/game_engine.h"
#include "core/game_engine/actions/move_to.h"
#include "core/game_engine/actions/equip.h"
using namespace adventure;
int main() {
  std::string room_fp = "../../../assets/rooms.json";
  std::string item_fp = "../../../assets/items.json";
  core::GameEngine *ge = new core::GameEngine(item_fp, room_fp);
//  core::ItemContainer ic = core::JSONLoader::LoadItems(item_fp);
//  core::RoomContainer rc = core::JSONLoader::LoadRooms(room_fp);
  core::actions::MoveTo mv ("bathroom");
  ge->HandleAction(mv);
  core::actions::Equip eq ("usb_key");
  ge->HandleAction(eq);
  return 0;
}
