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
#include "player.hpp"

SCENARIO("a player can write their own name", "[player]") {
  GIVEN("a player identified as '1'") {
    checkers::player player(1);

    WHEN("asked to print their name") {
      THEN("the player responds as 'player one'") {
        REQUIRE(player.nickname() == "player one");
      }
    }
  }

  GIVEN("a player named 'aboru'") {
    checkers::player player(1);
    player.name("aboru");

    WHEN("asked to print their name") {
      THEN("the player responds as 'aboru'") {
        REQUIRE(player.name() == "aboru");
        REQUIRE(player.nickname() == "aboru");
      }
    }
  }
}
