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

#include <string>

#include "players/player.hpp"

namespace checkers {

    player::player( int p_id ) : _id( p_id ) {}

    int player::id() {
        return this->_id;
    }

    std::string player::name() {
        if ( this->_id == 1 ) {
            return "player one";
        }
        if ( this->_id == 2 ) {
            return "player two";
        }
        return "undefined player";
    }

    std::string player::to_string() {
        return this->name();
    }

}
