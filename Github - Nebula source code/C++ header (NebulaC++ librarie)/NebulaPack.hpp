#pragma once
/*Nebula*/ 
#include "Nebula.hpp"
/*std*/
#include "string"

namespace Nebula
{
    class NPack {
        Out Out;
        Uii Input;
        Filesystem File;
        NebulaSystem System;
        private:
            std::string settings = "*Nebula*\n[Version 1.00]\nSettings{\n    Nebula version : 1.00\n    Task Path : ./NebulaProject/.Nebula/Task.nts\n    Header Path : ./NebulaProject/Header\n    Slot Path : ./NebuaProject/Slot\n}";
            std::string task = "*Nebula*\nTask{\n    C++ : G++\n    C : GCC\n    Nebula : NWys\n    Slot : NSWys\n}";
            std::string Main = R"(/*Nebula*/
#include "Header/Nebula.hpp"
/*std*/
#include "string"

Nebula::Out Out;
Nebula::Uii Input;
Nebula::Filesystem File;
Nebula::NebulaSystem System;

int main() {
    /*Code*/
    return 0;
}
/* thanks to : 
    - Wyslte : Global code, creator of the project
    - SPL : Python part
    - [No Name]
*/
            )";
            std::string NfileCode = R"(#pragma once

#include "Out.hpp"
#include "In.hpp"
#include <fstream>
#include <filesystem>

namespace Nebula
{
    class Filesystem {
        Out Out;
        Uii Input;
    public:
        // Function to read the content of a file
        std::string readFile(const std::string& filePath) {
            std::ifstream file(filePath);
            if (file.is_open()) {
                std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                return content;
            } else {
                Out.Println("Error opening the file.");
                return "";
            }
        }

        // Function to write to a file
        void writeFile(const std::string& filePath, const std::string& content) {
            std::ofstream file(filePath);
            if (file.is_open()) {
                file << content;
                file.close();
            } else {
                Out.Println("Error writing to the file.");
            }
        }

        // Function to open a directory and list its contents
        void listFilesInDirectory(const std::string& directoryPath) {
            for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
                Out.Println(entry.path().string());
            }
        }

        // Function to create a directory
        void createDirectory(const std::string& directoryPath) {
            if (!std::filesystem::create_directory(directoryPath)) {
                Out.Println("Error creating the directory.");
            }
        }

        // Function to delete a file
        void deleteFile(const std::string& filePath) {
            if (!std::filesystem::remove(filePath)) {
                Out.Println("Error deleting the file.");
            }
        }

        // Function to delete a directory (and its contents)
        void deleteDirectory(const std::string& directoryPath) {
            if (!std::filesystem::remove_all(directoryPath)) {
                Out.Println("Error deleting the directory.");
            }
        }

        // Function to create a file
        void createFile(const std::string& filePath, const std::string& content = "") {
            std::ofstream file(filePath);
            if (file.is_open()) {
                if (!content.empty()) {
                    file << content;
                }
                file.close();
            } else {
                Out.Println("Error creating the file.");
            }
        }
    };
} // namespace Nebula
)";
            std::string OutCode = R"(/*Out.hpp*/
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
            )";
            std::string InCode = R"(
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

            )";
std::string TasksJSON = R"(
{
    "version": "2.0",
    "tasks": [
        {
            "type": "shell",
            "label": "g++ build active file",
            "command": "/usr/bin/g++",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}",
                "-I",
                "./Header"  // Path to the include directory
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
)";
std::string settingsJSON = R"(
{
    "files.associations": {
        "atomic": "cpp",
        "bit": "cpp",
        "cctype": "cpp",
        "charconv": "cpp",
        "clocale": "cpp",
        "cmath": "cpp",
        "compare": "cpp",
        "concepts": "cpp",
        "cstddef": "cpp",
        "cstdint": "cpp",
        "cstdio": "cpp",
        "cstdlib": "cpp",
        "cstring": "cpp",
        "ctime": "cpp",
        "cwchar": "cpp",
        "exception": "cpp",
        "format": "cpp",
        "initializer_list": "cpp",
        "ios": "cpp",
        "iosfwd": "cpp",
        "iostream": "cpp",
        "istream": "cpp",
        "iterator": "cpp",
        "limits": "cpp",
        "locale": "cpp",
        "memory": "cpp",
        "new": "cpp",
        "ostream": "cpp",
        "stdexcept": "cpp",
        "streambuf": "cpp",
        "string": "cpp",
        "system_error": "cpp",
        "tuple": "cpp",
        "type_traits": "cpp",
        "typeinfo": "cpp",
        "utility": "cpp",
        "xfacet": "cpp",
        "xiosbase": "cpp",
        "xlocale": "cpp",
        "xlocbuf": "cpp",
        "xlocinfo": "cpp",
        "xlocmes": "cpp",
        "xlocmon": "cpp",
        "xlocnum": "cpp",
        "xloctime": "cpp",
        "xmemory": "cpp",
        "xstring": "cpp",
        "xtr1common": "cpp",
        "xutility": "cpp",
        "vector": "cpp",
        "filesystem": "cpp",
        "algorithm": "cpp",
        "chrono": "cpp",
        "forward_list": "cpp",
        "fstream": "cpp",
        "iomanip": "cpp",
        "optional": "cpp",
        "ratio": "cpp",
        "sstream": "cpp"
    }
}
)";
std::string Nebulahead = R"(
#pragma once 
/*Nebula*/
#include "Nfile.hpp"
#include "In.hpp"
#include "Out.hpp"
/*std*/
#include "string"
namespace Nebula
{
    class NebulaSystem {
        Out Out;
        Uii Input;
        Filesystem File;
        public:
            void NewConsole() {
                std::system("start cmd");
                /*
                while (true) {
                    Out.Print("Nebula$ ");
                    std::string inp = Input.GetString();
                    if (inp == "exit") {
                        std::system("pause");
                        break;
                    } else {
                        continue;
                    }
                }
                */
            }
    };
} // namespace Nebua
)";
        public:
            void CreateNebulaEnvironement() {
                File.createDirectory("./NebulaProject");
                
                File.createDirectory("./NebulaProject/.Nebula");
                /*.vscode*/
                File.createDirectory("./NebulaProject/.vscode");
                /*settings*/
                File.createFile("./NebulaProject/.vscode/settings.json");
                File.writeFile("./NebulaProject/.vscode/settings.json", settingsJSON);
                /*task*/
                File.createFile("./NebulaProject/.vscode/tasks.json");
                File.writeFile("./NebulaProject/.vscode/tasks.json",TasksJSON);
                /*Nebula*/
                File.createFile("./NebulaProject/.Nebula/Settings.nse");
                File.createFile("./NebulaProject/.Nebula/Task.nts");
                File.createDirectory("./NebulaProject/Header");
                File.createDirectory("./NebulaProject/Slot");
                CreatSettings();
                CreatTask(); 
                /*Out.hpp*/
                File.createFile("./NebulaProject/Header/Out.hpp");
                File.writeFile("./NebulaProject/Header/Out.hpp", OutCode);
                /*In.hpp*/
                File.createFile("./NebulaProject/Header/In.hpp");
                File.writeFile("./NebulaProject/Header/In.hpp", InCode);
                /*Nfile.hpp*/
                File.createFile("./NebulaProject/Header/Nfile.hpp");
                File.writeFile("./NebulaProject/Header/Nfile.hpp",NfileCode);
                /*Nebula.hpp*/
                File.createFile("./NebulaProject/Header/Nebula.hpp");
                File.writeFile("./NebulaProject/Header/Nebula.hpp",Nebulahead);
                /*Main.cpp*/
                File.createFile("./NebulaProject/Main.cpp");
                File.writeFile("./NebulaProject/Main.cpp", Main);
                /*End*/
                Out.Println("Success. All File created in ./NebulaProject : ");
                File.listFilesInDirectory("./NebulaProject");
                Out.Println("File in ./.Nebula : ");
                File.listFilesInDirectory("./NebulaProject/.Nebula");
                Out.Println("Enjoy !");
                std::system("pause");
                System.NewConsole();
                #ifdef _WIN32
                std::system("code ./NebulaProject/");
                #elif defined(__linux__) || defined(__APPLE__)
                std::system("code ./NebulaProject/");  // Exécute la commande 'ls' sur Linux/macOS
                #endif 
                System.NewPythonConsole();
            }
            void CreatSettings() {
                File.writeFile("./NebulaProject/.Nebula/Settings.nse", settings);
            }
            void CreatTask() {
                File.writeFile("./NebulaProject/.Nebula/Task.nts",task);
            }   
    };
} 
