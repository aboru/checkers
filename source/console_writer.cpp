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

#include <iostream>
#include <string>
#include "writer.hpp"

void ConsoleWriter::write(int value)
{
    this->write(std::to_string(value));
}

void ConsoleWriter::writeLine(int value) {
    this->writeLine(std::to_string(value));
}

void ConsoleWriter::write(std::string message)
{
    std::cout << message;
}

void ConsoleWriter::writeLine(std::string message)
{
    this->write(message);
    this->write("\n");
}

void ConsoleWriter::flush()
{
    std::cout.flush();
}

void ConsoleWriter::close()
{
    // does not close standard out.
}
