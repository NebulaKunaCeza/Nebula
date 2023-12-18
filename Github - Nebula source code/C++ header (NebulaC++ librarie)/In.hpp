/*In.hpp*/
#pragma once 

#include <iostream>
#include <string>

namespace Nebula {
    class Uii {
    public:
        // Demande et retourne un entier saisi par l'utilisateur
        int GetInteger() {
            int userInteger;
            std::cin >> userInteger;
            return userInteger;
        }

        // Demande et retourne un nombre à virgule flottante saisi par l'utilisateur
        double GetDouble() {
            double userDouble;
            std::cin >> userDouble;
            return userDouble;
        }

        // Demande et retourne un nombre à virgule flottante (float) saisi par l'utilisateur
        float GetFloat() {
            float userFloat;
            std::cin >> userFloat;
            return userFloat;
        }

        // Demande et retourne une valeur booléenne saisie par l'utilisateur
        bool GetBoolean() {
            bool userBool;
            std::cin >> userBool;
            return userBool;
        }

        // Demande et retourne un caractère saisi par l'utilisateur
        char GetChar() {
            char userChar;
            std::cin >> userChar;
            return userChar;
        }

        // Demande et retourne une chaîne de caractères saisie par l'utilisateur
        std::string GetString() {
            std::string userString;
            std::getline(std::cin, userString);
            return userString;
        }
    };
} // namespace NebulaLN
