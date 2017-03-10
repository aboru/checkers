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

#ifndef L_FILE_WRITER_HPP
#define L_FILE_WRITER_HPP

#include "board/board.hpp"

#include <string>

namespace checkers {

    class file_writer {

    public:
        file_writer();
        file_writer( std::string );

        void write( board );

    private:
        std::string _filename;

    };

}

#endif
