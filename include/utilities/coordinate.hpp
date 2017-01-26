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

#ifndef L_COORDINATE_HPP
#define L_COORDINATE_HPP

#include <string>

namespace checkers {

    class coordinate {

    public:
        coordinate();
        coordinate( int, int );

        static coordinate normal_coordinate( int, int );

        int x();
        int y();
        int normal_x();
        int normal_y();
        void x( int );
        void y( int );
        void normalize_x( int );
        void normalize_y( int );

        std::string to_string();
        std::string to_pretty_string();
        std::string to_normal_string();
        std::string to_normal_pretty_string();

    private:
        int _x;
        int _y;

    };

}

#endif
