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

#include <cstdlib>
#include "board/board.hpp"

board::board() {
    for ( int i = 0; i < 8; i++ ) {
        for ( int j = 0; j < 8; j++ ) {
            if ( i % 2 == j % 2 ) {
                this->state[i][j] = 0;
            } else if ( i < 3 ) {
                this->state[i][j] = 1;
            } else if ( i > 4 ) {
                this->state[i][j] = 2;
            } else {
                this->state[i][j] = 0;
            }
        }
    }
}

int board::at( int column, int row ) {
    return this->state[column][row];
}

int board::width() {
    return sizeof( this->state[0] ) / sizeof( int );
}

int board::height() {
    return sizeof( this->state ) / ( sizeof( int ) * this->width() );
}

std::string board::to_string() {
    std::string result = "";

    for ( int i = 0; i < this->height(); i++ ) {
        for ( int j = 0; j < this->width(); j++ ) {
            result += std::to_string( this->at( i, j ) ) + " ";
        }

        if ( i != this->height() - 1 ) result += "\n";
    }

    return result;
}
