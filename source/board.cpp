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
#include "board.hpp"

Board::Board()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            BoardNode node;

            if (i % 2 == j % 2) {
                if (i < 3) {
                    node.setOwner(1);
                } else if (i > 4) {
                    node.setOwner(2);
                } else {
                    node.setOwner(8);
                }
            } else {
                node.setOwner(0);
            }

            this->nodes[i][j] = node;
        }
    }
}

BoardNode Board::get(int row, int column)
{
    return this->nodes[row][column];
}

bool Board::shouldEnd()
{
    return true;
}

std::string Board::toString()
{
    std::string result = "";

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            result += std::to_string(this->nodes[i][j].getOwner());
            result += " ";
        }
        result += "\n";
    }

    return result;
}

int BoardNode::getOwner()
{
    return this->owner;
}

void BoardNode::setOwner(int owner)
{
    this->owner = owner;
}
