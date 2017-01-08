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

#include "catch.hpp"
#include "board/board.hpp"

SCENARIO( "boards are initialized with the proper setup", "[board]" ) {

    GIVEN( "a new board" ) {
        board board;

        WHEN( "player one looks at the top rows" ) {
            THEN( "his chips are located on the top 3 rows, separated by empty marks" ) {
                for ( int i = 0; i < 3; i++ ) {
                    for ( int j = 0; j < board.width(); j++ ) {
                        if ( i % 2 != j % 2 ) {
                            REQUIRE( board.at( i, j ) == 1 );
                        } else {
                            REQUIRE( board.at( i, j ) == 0 );
                        }
                    }
                }
            }
        }

        WHEN( "player one looks at the middle rows" ) {
            THEN( "all spaces in the middle two rows are empty" ) {
                for ( int i = 3; i < 4; i++ ) {
                    for ( int j = 0; j < board.width(); j++ ) {
                        REQUIRE( board.at( i, j ) == 0 );
                    }
                }
            }
        }

        WHEN( "looking at the bottom three rows" ) {
            THEN( "player two has his chips there in starting order" ) {
                for ( int i = 5; i < board.height(); i++ ) {
                    for ( int j = 0; j < board.width(); j++ ) {
                        if ( i % 2 != j % 2 ) {
                            REQUIRE( board.at( i, j ) == 2 );
                        } else {
                            REQUIRE( board.at( i, j ) == 0 );
                        }
                    }
                }
            }
        }

        WHEN( "accessing the size of the board" ) {
            THEN( "the dimensions match the actual state" ) {
                REQUIRE( board.width () == 8 );
                REQUIRE( board.height() == 8 );
            }
        }
    }

}
