#pragma once
/*Nebula*/
#include "Out.hpp"
/*std*/
#include <string>

namespace Nebula {
    class NebulaSlot {
        Out Out;

    private:
        struct Slot {
            int ID;
            std::string Data;
            double Uxx; /* 0.00 pour 0 */
        };

        // Tableau de 8 Slots
        Slot slots[8];

    public:
        // Méthode pour définir les valeurs d'un Slot
        void setSlot(int index, int id, const std::string& data, double uxx) {
            if (index >= 0 && index < 8) {
                slots[index].ID = id;
                slots[index].Data = data;
                slots[index].Uxx = uxx;
            }
        }

        // Méthodes pour obtenir les valeurs d'un Slot
        int getID(int index) const {
            return (index >= 0 && index < 8) ? slots[index].ID : -1;
        }

        const std::string& getData(int index) const {
            static const std::string emptyString = "";
            return (index >= 0 && index < 8) ? slots[index].Data : emptyString;
        }

        double getUxx(int index) const {
            return (index >= 0 && index < 8) ? slots[index].Uxx : 0.0;
        }

        // Méthode pour imprimer les informations de tous les Slot
        void PrintAllSlot() {
            Out.Println("All Slot :");
            for (int i = 0; i < 8; ++i) {
                Out.Print("Slot " + std::to_string(i + 1) + ": ");
                Out.Print("ID: " + std::to_string(getID(i)) + ", ");
                Out.Print("Data: " + getData(i) + ", ");
                Out.Print("Uxx: " + std::to_string(getUxx(i)));
                Out.Println("---");
            }
        }

        // Méthode pour imprimer les informations d'un seul Slot
        void PrintSingleSlot(int index) {
            if (index >= 0 && index < 8) {
                Out.Println("Slot " + std::to_string(index + 1) + ": ");
                Out.Print("ID: " + std::to_string(getID(index)) + ", ");
                Out.Print("Data: " + getData(index) + ", ");
                Out.Print("Uxx: " + std::to_string(getUxx(index)));
                Out.Println("");
            } else {
                Out.PrintERR("Invalid index");
            }
        }
    };
} // namespace Nebula
