#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace NebulaLN {
    class NebulaL {
        
        public: 
            void processEvents() {
                std::string Uii;
                std::vector<std::string> PrintLn; 
                for (int i = 1; i <= 8; i++) {
                    std::cout << "ln" << i << ' ';
                    std::getline(std::cin, Uii);

                    if (Uii == "PrintLn();") {
                        std::cout << "ln" << i << ".Pr" << ' ';
                        std::getline(std::cin, Uii);
                        PrintLn.push_back("$ln" + std::to_string(i) + Uii);

                    } else if (Uii == "LnSl") {
                        // un Ln = un slot de memoire
                    }
                }
        }

    };
} // namespace NebulaLN
