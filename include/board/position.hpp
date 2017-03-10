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

#ifndef L_POSITION_HPP
#define L_POSITION_HPP

#include <string>

#include "players/player.hpp"
#include "utilities/coordinate.hpp"

namespace checkers {

    class position {

    public:
        position();
        explicit position( int );
        position( int, bool );
        explicit position( coordinate );
        position( coordinate, int );
        position( coordinate, int, bool );

        void owner( int );
        void owner( player );
        void location( coordinate );
        void make_king();
        void make_king( bool );
        void unmake_king();

        bool is_owner( int );
        bool is_owner( player );
        bool has_owner();
        bool is_playable();
        bool is_empty();
        bool is_enemy( int );
        bool is_enemy( player );
        bool is_king();
        bool is_not_king();
        bool is_location( coordinate );

        int value();

        coordinate location();
        std::string to_string();

    private:
        int _owner;
        bool _is_king;
        coordinate _coordinate;

    };

}

#endif
