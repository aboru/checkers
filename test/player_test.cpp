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

#include "catch.hpp"
#include "players/player.hpp"

SCENARIO( "players have identity in the game", "[players]" ) {

    GIVEN( "a players one and two each with their id's" ) {
        checkers::player player1( 1 );
        checkers::player player2( 2 );

        REQUIRE( player1.id() == 1 );
        REQUIRE( player2.id() == 2 );

        WHEN( "player one is named" ) {
            std::string name = player1.name();

            THEN( "the name is 'player one'" ) {
                REQUIRE( name == "player one" );
            }
        }

        WHEN( "player two is named" ) {
            std::string name = player2.name();

            THEN( "the name is 'player two'" ) {
                REQUIRE( name == "player two" );
            }
        }
    }

}
