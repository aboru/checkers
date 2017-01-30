[![Build Status](https://travis-ci.org/aboru/checkers.svg?branch=0.2.0)](https://travis-ci.org/aboru/checkers)

# Checkers

A game of checkers for two players for a linux desktop. This application will
allow two players to share a console to play a game following the American rules
for checkers. The game is played by interacting with a terminal to input commands
and view the game state.

### Goals

The project goals are:

* to create a playable game of checkers
* to learn openGL
* to write AI systems
* to practice good coding standards
* to keep a grasp of c++

### Status

> version - 0.2.0 : pre-alpha

### Compatibility

This game is designed on and for Arch Linux, other flavors of linux will probably
work but are not explicitly tested at this point. OSX and Windows are unsupported
and changes would be needed to make them work.

### Dependencies

#### Build

* G++ or Clang++ (for compilation)
* CMake >= 3.6.1
* make

#### Testing

* [Catch](https://github.com/philsquared/Catch) - bundled

#### Run

### How To Run

To run the project, run the following commands in a terminal window from the
root directory:

> $ cmake  
> $ make test // to run unit tests  
> $ ./checkers

### How To Contribute

To contribute to the project, please make a pull request and these will be
evaluated on a case by case basis.

### Changlog

> 0.1.0

* players are represented with state
* positions are represented with state
* coordinates are used for access
* the board initializes to default setup

### Licensing

Copyright 2016 Anders Borg [aboru]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
