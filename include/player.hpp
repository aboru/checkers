/*
    Copyright 2016 aboru

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef L_CHECKERS_PLAYER_HPP
#define L_CHECKERS_PLAYER_HPP

#include <string>

namespace checkers {
  class player {
    int _id;
    std::string _name;
    
  public:
    player(int id): _id(id) {
      // empty body because *reasons*
    }

    std::string name();
    std::string nickname();

    void name(std::string);
  };
}

#endif
