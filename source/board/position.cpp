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

#include "board/position.hpp"
#include "players/player.hpp"
#include "utilities/coordinate.hpp"

namespace checkers {

    position::position() :
        _owner( 0 ),
        _is_king( false ),
        _coordinate( coordinate() ) {}

    position::position( int player ) :
        _owner( player ),
        _is_king( false ),
        _coordinate( coordinate() ) {}

    position::position( int player, bool is_king ) :
        _owner( player ),
        _is_king( is_king ),
        _coordinate( coordinate() ) {}

    position::position( coordinate coordinate ) :
        _owner( 0 ),
        _is_king( false ),
        _coordinate( coordinate ) {}

    position::position( coordinate coordinate, int player ) :
        _owner( player ),
        _is_king( false ),
        _coordinate( coordinate ) {}

    position::position( coordinate coordinate, int player, bool is_king ) :
        _owner( player ),
        _is_king( is_king ),
        _coordinate( coordinate ) {}

    void position::owner( int owner ) {
        this->_owner = owner;
    }

    void position::owner( player owner ) {
        this->owner( owner.id() );
    }

    void position::location( coordinate location ) {
        this->_coordinate = location;
    }

    void position::make_king() {
        this->make_king( true );
    }

    void position::unmake_king() {
        this->make_king( false );
    }

    void position::make_king( bool is_king ) {
        this->_is_king = is_king;
    }

    bool position::is_owner( int value ) {
        return this->_owner == value;
    }

    bool position::is_owner( player value ) {
        return this->is_owner( value.id() );
    }

    bool position::has_owner() {
        return this->_owner > 0;
    }

    bool position::is_empty() {
        return !this->has_owner();
    }

    bool position::is_playable() {
        return this->_coordinate.x() % 2 != this->_coordinate.y() % 2;
    }

    bool position::is_enemy( int current_player ) {
        return this->_owner == ( current_player % 2 ) + 1;
    }

    bool position::is_enemy( player current_player ) {
        return this->is_enemy( current_player.id() );
    }

    bool position::is_king() {
        return this->_is_king;
    }

    bool position::is_not_king() {
        return !this->is_king();
    }

    bool position::is_location( coordinate location ) {
        return this->_coordinate.x() == location.x() && this->_coordinate.y() == location.y();
    }

    int position::value() {
        int value = 0;

        if ( this->is_owner( 1 ) ) value  = 1;
        if ( this->is_owner( 2 ) ) value  = 2;
        if ( this->is_king() )     value += 2;

        return value;
    }

    coordinate position::location() {
        return this->_coordinate;
    }

    std::string position::to_string() {
        std::ostringstream stream;
        int result = 0;

        if ( this->is_owner( 1 ) ) result  = 1;
        if ( this->is_owner( 2 ) ) result  = 2;
        if ( this->is_king() )     result += 2;

        stream << " ";
        stream << result;

        return stream.str();
    }

}
