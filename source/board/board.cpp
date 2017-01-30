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

#include <sstream>
#include <string>

#include "board/board.hpp"
#include "board/position.hpp"
#include "utilities/coordinate.hpp"

namespace checkers {

    board::board() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                position slot(coordinate(i, j));

                if (slot.is_playable()) {
                    if (slot.location().x() < 3)
                        slot.owner(1);
                    if (slot.location().x() > 4)
                        slot.owner(2);
                }

                this->state[slot.location().y()][slot.location().x()] = slot;
            }
        }
    }

    std::string board::to_string() {
        std::ostringstream stream;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                coordinate slot(i, j);
                stream << this->state[slot.y()][slot.x()].to_string();
            }
            stream << "\n";
        }

        return stream.str();
    }

}
