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

#ifndef CHECKERS_WRITER_HPP
#define CHECKERS_WRITER_HPP

#include <string>

class Writer
{
  public:
    virtual void write(int)     = 0;
    virtual void writeLine(int) = 0;
    virtual void write(std::string message)     = 0;
    virtual void writeLine(std::string message) = 0;
    virtual void flush() = 0;
    virtual void close() = 0;
};

class ConsoleWriter : public Writer
{
  public:
    void write(int);
    void writeLine(int);
    void write(std::string message);
    void writeLine(std::string message);
    void flush();
    void close();
};

#endif
