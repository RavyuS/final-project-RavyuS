cmake_minimum_required(VERSION 3.17)
project(final_project_RavyuS)

set(CMAKE_CXX_STANDARD 17)
# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -g3")

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if(MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic)
endif()

include(FetchContent)

if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.3
)

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif()

get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE)
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

file(GLOB_RECURSE core_sources src/core/*.cc)

file(GLOB_RECURSE gui_sources src/gui/*.cc)

file(GLOB_RECURSE test_sources test/*.cc)
#list(APPEND core_sources
#        src/core/game_engine/game_engine.cc
#        src/core/game_engine/game_state.cc
#        src/core/game_engine/item_container.cc
#        src/core/game_engine/json_loader.cc
#        src/core/game_engine/room_container.cc
#        src/core/game_engine/actions/equip.cc
#        src/core/game_engine/actions/move_to.cc
#        src/core/game_engine/triggers/item_visibility.cc
#        src/core/game_engine/triggers/room_visibility.cc
#        src/core/game_objects/item.cc
#        src/core/game_objects/room.cc
#        src/core/game_objects/interactive_items/static_image.cc
#        src/core/game_objects/interactive_items/keypad.cc)
#add_executable(adventure apps/main.cc ${core_sources})
#target_include_directories(adventure PRIVATE include)
#target_link_libraries(adventure nlohmann_json::nlohmann_json)

ci_make_app(
        APP_NAME adventure
        CINDER_PATH ${CINDER_PATH}
        INCLUDES include
        SOURCES apps/main.cc ${core_sources}
        LIBRARIES nlohmann_json::nlohmann_json
)

ci_make_app(
        APP_NAME adventure-gui
        CINDER_PATH ${CINDER_PATH}
        INCLUDES include
        SOURCES apps/adventure.cc ${core_sources} ${gui_sources}
        LIBRARIES nlohmann_json::nlohmann_json
)

ci_make_app(
        APP_NAME adventure-test
        CINDER_PATH ${CINDER_PATH}
        SOURCES ${test_sources} ${core_sources}
        INCLUDES include
        LIBRARIES catch2 nlohmann_json::nlohmann_json
)
if(MSVC)
    set_property(TARGET naive-bayes-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif()