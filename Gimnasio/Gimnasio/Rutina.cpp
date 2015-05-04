//
//  Rutina.cpp
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Rutina.h"


int Rutina::routineCount = 0;

// REQUIRES: None.
// MODIFIES: this->equipo.
//  EFFECTS: If the machinetype and rutine type is the same, adds machine to equipo. Otherwise,
//           notifies the user by printing to console and does nothing.
void Rutina::addEquipment(const Maquina & machine){
    
    if (machine.getTipo() == this->getTipo()) {
        equipo.push_back(machine);
        return;
    }
    
    cout << "No se puede agregar la maquina, pues el tipo de ejercicio realizado en la maquina" << endl;
    cout << "no coincide con el tipo de ejercicio de esta rutina" << endl;
    
}

// REQUIRES: None.
// MODIFIES: os.
//  EFFECTS: Returns the type of this rutine and all the equipment used in this rutine.
// Overloads stream output operator.
ostream & operator<<(ostream & os, const Rutina & rutina)
{
    os << "------------------------------------------------------" << endl;
    os << "Rutina numero: " << setw(2) << rutina.routineID << "de tipo: " << rutina.getTipo() << endl;
    os << "------------------------------------------------------" << endl;
    os << "Las maquinas utilizadas en esta rutina son:  " << std::endl;
    
    rutina.printEquipment();
    
    return os;
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Prints to console the machines in this routine. If there are no machines, notifies the user.
void Rutina::printEquipment() const{
    
    if (equipo.empty()) {
        cout << "          Esta rutina no tiene maquinas todavia" << endl;
        return; 
    }
    
    for (auto e: equipo)
    {
        std::cout << "          " << e << std::endl;
    }
    
    std::cout << std::endl;
}

vector<Maquina> Rutina::getEquipment() const {
    return equipo;
}

// REQUIRES: None.
// MODIFIES: this->rutineType.
//  EFFECTS: sets the type of machine to the string that represents the type. If string is invalid, set
// the machine to NONE type.
void Rutina::setTipo(string tipoString){
    Maquina::MaquinaTipo output;
    
    if (tipoString == "pecho" || tipoString == "Pecho") {
        output = Maquina::MaquinaTipo::PECHO;
    } else if (tipoString == "espalda" || tipoString == "Espalda"){
        output = Maquina::MaquinaTipo::ESPALDA;
    } else if (tipoString == "brazo" || tipoString == "Brazo"){
        output = Maquina::MaquinaTipo::BRAZO;
    } else if (tipoString == "pierna" || tipoString == "Pierna"){
        output = Maquina::MaquinaTipo::PIERNA;
    } else if (tipoString == "abdomen" || tipoString == "Abdomen"){
        output = Maquina::MaquinaTipo::ABDOMEN;
    } else{
        cout << "El tipo de rutina no ha sido reconocido, la rutina se ha asignado con un tipo: 'no especificado'" << endl;
        output = Maquina::MaquinaTipo::NONE;
    }
    rutineType = output;
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the string representation of enum MaquinaTipo.
string Rutina::getTipo() const {
    Maquina::MaquinaTipo tipoMaq = this->rutineType;
    string output;
    
    switch (tipoMaq) {
        case Maquina::MaquinaTipo::PECHO:
            output = "pecho";
            break;
        case Maquina::MaquinaTipo::ESPALDA:
            output = "espalda";
            break;
        case Maquina::MaquinaTipo::BRAZO:
            output = "brazo";
            break;
        case Maquina::MaquinaTipo::PIERNA:
            output = "pierna";
            break;
        case Maquina::MaquinaTipo::ABDOMEN:
            output = "abdomen";
            break;
        case Maquina::MaquinaTipo::NONE:
            output = "no especificado";
            break;
            
        default:
            break;
    }
    
    return output;
}

void removeEquipment(const int equipmentID){
    
    
}