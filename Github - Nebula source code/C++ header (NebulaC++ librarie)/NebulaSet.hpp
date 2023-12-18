#pragma once
#include "string"

namespace Nebula
{
    class NebulaSettings {
        private:
        struct BuildNebulaSettings {
            /*Nebula*/
            std::string Head;
            std::string Version;
            std::string HeadersPath;
            /*Nebula -Slot*/
            std::string NebulaSlotVersion;
            std::string SlotPath;
            int MaxSlot;
            /*Iostream*/
            std::string InputPath;
            std::string OutputPath;
            /*System*/
            std::string NebulaNodePath;
            bool NebulaNode;
        };
        public:
            void CreatSettings(std::string head, std::string version, std::string headerPath, 
                std::string NebulaslotVersion, std::string slotPath, int maxSlot,
                std::string inputPath, std::string outputPath, std::string NodePath, bool NodeUse) {
                    BuildNebulaSettings set;
                    set.Head = head;
                    set.Version = version;
                    set.HeadersPath = headerPath;
                    set.NebulaSlotVersion = NebulaslotVersion;
                    set.SlotPath = slotPath;
                    set.MaxSlot = maxSlot;
                    set.InputPath = inputPath;
                    set.OutputPath = outputPath;
                    set.NebulaNodePath = NodePath;
                    set.NebulaNode = NodeUse;
            }
    };
} // namespace Nebula
