//
//  Maquina.cpp
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Maquina.h"

int Maquina::machineCount = 0;


// REQUIRES: None.
// MODIFIES: os.
//  EFFECTS: Overloads the output stream operator.
ostream & operator<<(ostream & os, const Maquina & machine){
    os << machine.machineName << ". " << endl;
    os << "              sirve para ejercitar: " << machine.getTipo();
    
    return os;
}



// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the enum representation of the given string.
void Maquina::setTipo(string tipoString){
    MaquinaTipo output;
    
    if (tipoString == "pecho" || tipoString == "Pecho") {
        output = MaquinaTipo::PECHO;
    } else if (tipoString == "espalda" || tipoString == "Espalda"){
        output = MaquinaTipo::ESPALDA;
    } else if (tipoString == "brazo" || tipoString == "Brazo"){
        output = MaquinaTipo::BRAZO;
    } else if (tipoString == "pierna" || tipoString == "Pierna"){
        output = MaquinaTipo::PIERNA;
    } else if (tipoString == "abdomen" || tipoString == "Abdomen"){
        output = MaquinaTipo::ABDOMEN;
    } else{
        cout << "El tipo de maquina no ha sido reconocido, la maquina se ha asignado con un tipo: 'no especificado'" << endl;
        output = MaquinaTipo::NONE;
    }
    
    this->machineType = output;
}

// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the string representation of enum MaquinaTipo.
string Maquina::getTipo() const{
    MaquinaTipo tipoMaq = this->machineType; 
    string output;
    
    switch (tipoMaq) {
        case MaquinaTipo::PECHO:
            output = "pecho";
            break;
        case MaquinaTipo::ESPALDA:
            output = "espalda";
            break;
        case MaquinaTipo::BRAZO:
            output = "brazo";
            break;
        case MaquinaTipo::PIERNA:
            output = "pierna";
            break;
        case MaquinaTipo::ABDOMEN:
            output = "abdomen";
            break;
        case MaquinaTipo::NONE:
            output = "no especificado";
            break;
            
        default:
            break;
    }
    
    return output;
}


bool Maquina::operator<(const Maquina machine) const{
    return this->machineName < machine.machineName;
}


bool Maquina::operator==(const Maquina machine) const{
    bool output;
    output = this->machineName == machine.machineName;
    output = output && this->machineType == machine.machineType;
    
    return output;
}




