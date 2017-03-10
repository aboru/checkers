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

#include "io/file-writer.hpp"
#include "board/board.hpp"
#include "utilities/coordinate.hpp"

#include <string>
#include <iostream>
#include <fstream>

namespace checkers {

    file_writer::file_writer() : _filename( "save.chk" ) {}

    file_writer::file_writer( std::string filename ) : _filename( filename ) {}

    void file_writer::write( board board ) {
        std::ofstream file;

        file.open( this->_filename.c_str() );
        file << "version: 0.1.0" << std::endl;

        for ( int i = 0; i < 8; i++ ) {
            for ( int j = 0; j < 8; j++ ) {
                coordinate slot( i, j );
                file << board.value_at( slot );
            }
            file << std::endl;
        }

        file.close();
    }

}
