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
#include "utilities/coordinate.hpp"

SCENARIO( "coordinates have x and y coordinates", "[coordinates]" ) {

    GIVEN( "default coordinate point" ) {
        checkers::coordinate coordinate;

        WHEN( "the default coordinates are requested" ) {
            int x = coordinate.x();
            int y = coordinate.y();

            THEN( "the values of the coordinates are (0,0)" ) {
                REQUIRE( x == 0 );
                REQUIRE( y == 0 );
            }

            THEN( "the value of to_string is '0 0'") {
                REQUIRE( coordinate.to_string() == "0 0" );
                REQUIRE( coordinate.to_pretty_string() == "(0,0)" );
                REQUIRE( coordinate.to_normal_string() == "1 1" );
                REQUIRE( coordinate.to_normal_pretty_string() == "(1,1)" );
            }
        }
    }

}
