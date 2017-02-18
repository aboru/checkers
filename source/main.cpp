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
#include <iostream>
#include <string>

#include "config.hpp"
#include "board/board.hpp"

int main(int argument_count, char **arguments) {
    for (int i = 0; i < argument_count; i++) {
        std::string argument = std::string(arguments[i]);

        if (argument == "-v" || argument == "--version") {
            std::cout << "aboru checkers" << std::endl;
            std::cout << "version: @" << VERSION << std::endl;
            return EXIT_SUCCESS;
        }
    }

    checkers::board board;

    std::cout << board.to_string();

    return EXIT_SUCCESS;
}
