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
