#pragma once
/*Nebula*/
#include "Nebula.hpp"
/*JSON*/
#include "json.hpp"
/*std*/
#include "string"

namespace Nebula {
    using json = nlohmann::json;

    class JSONNebula {
        Out Out;
        Uii input;
        Filesystem File;

    public:
        void ReadJSONFile(const std::string& filePath) {
            std::string JSON_File = File.readFile(filePath);

            try {
                auto nebulaObject = json::parse(JSON_File);

                if (nebulaObject.find("*Nebula*") != nebulaObject.end()) {
                    // *Nebula* key is present
                    auto& nebula = nebulaObject["*Nebula*"];

                    for (int i = 1; i <= 8; ++i) {
                        std::string slotName = "Slot" + std::to_string(i);

                        if (nebula.find(slotName) != nebula.end()) {
                            auto& currentSlot = nebula[slotName];

                            auto data = currentSlot["Data"];
                            auto uxx = currentSlot["Uxx"];

                            // Now you can use 'data' and 'uxx' as needed
                            std::string PrintData = slotName + " Data : " + data.dump();
                            std::string PrintUxx = slotName + " Uxx : " + uxx.dump();
                            Out.Println(PrintData);
                            Out.Println(PrintUxx);
                        } else {
                            Out.Println("Slot " + slotName + " is not present.");
                        }
                    }
                } else {
                    Out.PrintERR("Can't find the main *Nebula*.");
                }
            } catch (const std::exception& e) {
                // Handle JSON parsing errors
                Out.PrintERR("Error parsing JSON: " + std::string(e.what()));
            }
        }
        void CreateNebulaJSONFile(std::string path) {
            std::string SlotConfig = R"(
{
    "*Nebula*" : {
        "Slot1" : {
            "Data" : "Hello World",
            "Uxx" : 1.00
        },
        "Slot2" : {
            "Data" : null,
            "Uxx" : 0.00
        },
        "Prog" : {
            "Out.Println" : "Hello World",
            "Out.return" : 0
        }
    }
}
            )";
            File.createFile(path);
            File.writeFile(path, SlotConfig);
        }
        void InterpretJSONFile(std::string Path) {
            std::string JSON_File = File.readFile(Path);

            try {
                auto nebulaObject = json::parse(JSON_File);

                if (nebulaObject.find("*Nebula*") != nebulaObject.end()) {
                    auto& nebula = nebulaObject["*Nebula*"];

                    if (nebula.find("Prog") != nebula.end()) {
                        auto progValue = nebula["Prog"];
                        std::string progString = progValue.dump();
                        if (nebula.find("Out") != nebula.end() && nebula["Out"].find("Println") != nebula["Out"].end()) {
                            std::string outPrintlnValue = nebula["Out"]["Println"];
                            Out.Println(outPrintlnValue);
                            } else if (nebula.find("Out") != nebula.end() && nebula["Out"].find("return") != nebula["Out"].end()) {
                                // Vérifie que la valeur associée à "Out.return" est un nombre
                                if (nebula["Out"]["return"].is_number()) {
                                    // Stocke la valeur de "Out.return"
                                    double outReturnValue = nebula["Out"]["return"];
                                    std::string OutReturnValue = std::to_string(outReturnValue);
                                    Out.Println(OutReturnValue);
                                } else {
                                    Out.PrintERR("Value associated with 'Out.return' is not a number.");
                                }
                            }
                    } else {
                        Out.PrintERR("Key 'Prog' not found in Nebula.");
                    }
                } else {
                    Out.PrintERR("Can't find the main *Nebula*.");
                }
            } catch (const std::exception& e) {
                // Gérer les erreurs de parsing JSON
                Out.PrintERR("Error parsing JSON: " + std::string(e.what()));
            }
        }
    };
} // namespace Nebula

/* Dev's notes:
    Lors de la création de NebulaJSON, une idée m'est venue : créer un interpréteur pour interpréter du code NebulaC++ dans un fichier JSON. 
    Alors que je réfléchissais à structurer le code de l'interpréteur, j'ai vite compris que toutes les options de NebulaC++ ne pourraient pas être 
    disponibles. Premièrement, l'interpréteur serait beaucoup trop lourd, et deuxièmement, il serait presque impossible d'intégrer des notions 
    telles que 'Input.GetString()'. J'ai donc préféré choisir l'option de limiter la puissance de NebulaJSON.

    Voici la syntaxe globale de NebulaJSON :
    - "Out.Println" : null // Affiche une valeur nulle à l'output. La valeur peut être changée comme bon vous semble.
    - "Out.return" : 45 // Retourne la valeur 45.

    "Slot1" : {
        "Data" : "Hello World", // Le Data n'a pas de type défini, mais il est conseillé de le définir sur string.
        "Uxx" : 1.00 // Notez qu'il est fortement conseillé de définir Uxx en double.
    } // Ce code définit le Slot1 avec la valeur Data en "Hello World" et la valeur du Uxx sur 1.00.
*/
