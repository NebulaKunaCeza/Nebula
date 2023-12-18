/*Out.hpp*/
#pragma once
/*std*/
#include <string>
#include <iostream>

namespace Nebula {
    class Out {
        public:
            void Println(std::string Object) {
                std::cout << '$' << ' ' << Object << std::endl;
            }
            void Print(std::string Object) {
                std::cout << '$' << ' ' << Object;
            }
            void PrintERR(std::string Object) {
                std::cerr << '$' <<  ' ' << Object << std::endl;
            }
    };
} // namespace Nebula
