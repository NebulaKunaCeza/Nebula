
#pragma once
#include "Nebula.hpp"
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
            std::string Main = R"(
#include "Header/Nebula.hpp"
#include "string"

Nebula::Out Out;
Nebula::Uii Input;
Nebula::Filesystem File;
Nebula::NebulaSystem System;

int main() {
    /*Code*/
    return 0;
}
)";
            std::string NfileCode = R"(
#pragma once

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

        void writeFile(const std::string& filePath, const std::string& content) {
            std::ofstream file(filePath);
            if (file.is_open()) {
                file << content;
                file.close();
            } else {
                Out.Println("Error writing to the file.");
            }
        }

        void listFilesInDirectory(const std::string& directoryPath) {
            for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
                Out.Println(entry.path().string());
            }
        }

        void createDirectory(const std::string& directoryPath) {
            if (!std::filesystem::create_directory(directoryPath)) {
                Out.Println("Error creating the directory.");
            }
        }

        void deleteFile(const std::string& filePath) {
            if (!std::filesystem::remove(filePath)) {
                Out.Println("Error deleting the file.");
            }
        }

        void deleteDirectory(const std::string& directoryPath) {
            if (!std::filesystem::remove_all(directoryPath)) {
                Out.Println("Error deleting the directory.");
            }
        }

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
}
)";
            std::string OutCode = R"(
#pragma once
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
}
)";
            std::string InCode = R"(
#pragma once 

#include <iostream>
#include <string>

namespace Nebula {
    class Uii {
    public:
        int GetInteger() {
            int userInteger;
            std::cin >> userInteger;
            return userInteger;
        }

        double GetDouble() {
            double userDouble;
            std::cin >> userDouble;
            return userDouble;
        }

        float GetFloat() {
            float userFloat;
            std::cin >> userFloat;
            return userFloat;
        }

        bool GetBoolean() {
            bool userBool;
            std::cin >> userBool;
            return userBool;
        }

        char GetChar() {
            char userChar;
            std::cin >> userChar;
            return userChar;
        }

        std::string GetString() {
            std::string userString;
            std::getline(std::cin, userString);
            return userString;
        }
    };
}
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
                "./Header"
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
#include "Nfile.hpp"
#include "In.hpp"
#include "Out.hpp"
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
            }
    };
}
)";
        public:
            void CreateNebulaEnvironement() {
                File.createDirectory("./NebulaProject");
                
                File.createDirectory("./NebulaProject/.Nebula");
                File.createDirectory("./NebulaProject/.vscode");
                File.createFile("./NebulaProject/.vscode/settings.json");
                File.writeFile("./NebulaProject/.vscode/settings.json", settingsJSON);
                File.createFile("./NebulaProject/.vscode/tasks.json");
                File.writeFile("./NebulaProject/.vscode/tasks.json",TasksJSON);
                File.createFile("./NebulaProject/.Nebula/Settings.nse");
                File.createFile("./NebulaProject/.Nebula/Task.nts");
                File.createDirectory("./NebulaProject/Header");
                File.createDirectory("./NebulaProject/Slot");
                CreatSettings();
                CreatTask(); 
                File.createFile("./NebulaProject/Header/Out.hpp");
                File.writeFile("./NebulaProject/Header/Out.hpp", OutCode);
                File.createFile("./NebulaProject/Header/In.hpp");
                File.writeFile("./NebulaProject/Header/In.hpp", InCode);
                File.createFile("./NebulaProject/Header/Nfile.hpp");
                File.writeFile("./NebulaProject/Header/Nfile.hpp",NfileCode);
                File.createFile("./NebulaProject/Header/Nebula.hpp");
                File.writeFile("./NebulaProject/Header/Nebula.hpp",Nebulahead);
                File.createFile("./NebulaProject/Main.cpp");
                File.writeFile("./NebulaProject/Main.cpp", Main);
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
                std::system("code ./NebulaProject/");
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
