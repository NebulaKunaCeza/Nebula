#pragma once 
/*Nebula*/
#include "Nfile.hpp"
#include "In.hpp"
#include "Out.hpp"
/*std*/
#include "string"
/*JSON*/
#include "json.hpp"

namespace Nebula
{
    class NebulaSystem {
        Out Out;
        Uii Input;
        Filesystem File;
        private:
            std::string UserInput;
        public:
            void NewConsole() {
                std::system("start cmd");
            }
            void NewPythonConsole() {
                std::system("Python");
            }
            void NewNebulaConsole() {
                Out.Println("--- *Nebula* ---");
                while (true) {
                    Out.Print("");
                    UserInput = Input.GetString();
                    if (!UserInput.find("exit") != std::string::npos) {

                    } else if (UserInput.find("exit") != std::string::npos) {
                        NebulaConsoleLogique(UserInput);
                    }
                }
            }
            void NebulaConsoleLogique(std::string Object) {
                if (!Object.empty()) {
                    if (Object.find("Print") != std::string::npos) {
                        std::size_t printPos = Object.find("Print");
                        printPos += 5;
                        std::string infoAfterPrint = Object.substr(printPos);
                        Out.Println(infoAfterPrint);
                    } else if (Object.find("JSON>Access")) {
                        Out.Print("Open, write or create a NebulaJSON file ? \n'-O' -> Open\n'-W' -> Write\n'-C' -> Creat\n");
                        std::string UserChoose = Input.GetString();
                        if (UserChoose.find("-O") != std::string::npos) {
                            Out.Println("Read a file.");
                            Out.Print("File path : ");
                            std::string JSONFilePath = Input.GetString();
                            /*Reading the file*/

                            std::string JSON_File = File.readFile(JSONFilePath);
                            try {
                                auto nebulaObject = nlohmann::json::parse(JSON_File);

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
                        } else if (UserChoose.find("-W") != std::string::npos) {
                            Out.Println("Write in a file.");
                            Out.Print("File path : ");
                            std::string JSONFilePath = Input.GetString();
                            Out.Print("Write the JSON content (with '\\n')");
                            std::string ToWrite = Input.GetString();
                            File.writeFile(JSONFilePath, ToWrite);
                            /*Write a file*/
                        } else if (UserChoose.find("-C") != std::string::npos) {
                            Out.Println("Create NebulaJSON file.");
                            Out.Print("File path : ");
                            std::string JSONFilePath = Input.GetString();
                            /*creat a file*/

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
                            File.createFile(JSONFilePath);
                            File.writeFile(JSONFilePath, SlotConfig);

                        } else {
                            Out.PrintERR("Invalid command.");
                        }
                    }
                }
                    
            }
    };
} // namespace Nebua
