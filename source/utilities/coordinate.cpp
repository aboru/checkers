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
#include <sstream>

#include "utilities/coordinate.hpp"

namespace checkers {

    coordinate coordinate::normal_coordinate( int x, int y ) {
        try {
            return coordinate( x - 1, y - 1 );
        } catch ( int error ) {
            throw 2;
        }
    }

    coordinate::coordinate() {
        this->_x = 0;
        this->_y = 0;
    }

    coordinate::coordinate( int x, int y ) {
        if ( x < 0 || x > 7 ) throw 1;
        if ( y < 0 || y > 7 ) throw 1;

        this->_x = x;
        this->_y = y;
    }

    int coordinate::x() {
        return this->_x;
    }

    int coordinate::y() {
        return this->_y;
    }

    int coordinate::normal_x() {
        return this->_x + 1;
    }

    int coordinate::normal_y() {
        return this->_y + 1;
    }

    void coordinate::x( int x ) {
        if ( x < 0 || x > 7 ) throw 1;

        this->_x = x;
    }

    void coordinate::y( int y ) {
        if ( y < 0 || y > 7 ) throw 1;

        this->_y = y;
    }

    void coordinate::normalize_x( int x ) {
        if ( x < 1 || x > 8 ) throw 2;

        this->_x = x - 1;
    }

    void coordinate::normalize_y( int y ) {
        if ( y < 1 || y > 8 ) throw 2;

        this->_y = y - 1;
    }

    std::string coordinate::to_string() {
        std::ostringstream stream;
        stream << this->x();
        stream << " ";
        stream << this->y();
        return stream.str();
    }

    std::string coordinate::to_pretty_string() {
        std::ostringstream stream;
        stream << "(";
        stream << this->x();
        stream << ",";
        stream << this->y();
        stream << ")";
        return stream.str();
    }

    std::string coordinate::to_normal_string() {
        std::ostringstream stream;
        stream << this->normal_x();
        stream << " ";
        stream << this->normal_y();
        return stream.str();
    }

    std::string coordinate::to_normal_pretty_string() {
        std::ostringstream stream;
        stream << "(";
        stream << this->normal_x();
        stream << ",";
        stream << this->normal_y();
        stream << ")";
        return stream.str();
    }

}
