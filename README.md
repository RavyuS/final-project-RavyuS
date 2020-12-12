# Adventure Game CS126 final project

- [Adventure Game CS126 final project](#adventure-game-cs126-final-project)
  - [Overview](#overview)
  - [Build Instructions](#build-instructions)
    - [Dependencies](#dependencies)
    - [Setup](#setup)
  - [Gameplay Guide](#gameplay-guide)
    - [Screen](#screen)
      - [Item Types](#item-types)
        - [Keypad](#keypad)
        - [Image](#image)
    - [Navigation Menu](#navigation-menu)

## Overview
A point-and-click adventure game built on Cinder. Inspired by historic point-and-click's like Ace Attorney, Myst, Secret of Monkey Island.

## Build Instructions

### Dependencies
Running the Adventure Game will require:

- Cinder >=0.9.2
- CMake >=3.14
- Any C++ compiler with C++17 support

### Setup
1. Install Cinder and navigate to the install directory
    - For Linux users, this should be in `<user>/home/Cinder`
2. Create a "my-proj" folder
3. Inside the newly created folder, clone the repository with `git clone https://github.com/uiuc-fa20-cs126/final-project-RavyuS`
4. Build and run the project from CLion

## Gameplay Guide
The game interface is split into different parts:

### Screen
The Screen occupies the left half of the screen, and is where the player interacts with the current Room.

Most rooms should have items that can be interacted with by **`left-clicking`** on them. This brings up the item menu. Some items are interactive, and clicking on the interact option brings up the item's interface. Different item types are explained below.

The player can go back to the previous screen anytime by pressing the **`Escape`** key.

#### Item Types
##### Keypad
Displays a keypad that the user can type into. Click on the * or # key to clear the current input.

##### Image
Displays a more detailed image of the item for inspection. No interactive elements.

### Navigation Menu 
The Navigation Menu occupies the bottom right portion of the screen. When viewing a Room, a list of adjacent rooms will appear here.
**`Clicking`** on any of the Room boxes will bring you to that room.