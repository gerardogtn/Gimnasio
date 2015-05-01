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
    os << "La maquina " << machine.machineID << " llamada: " << machine.machineName;
    os << "sirve para ejercitar: " << machine.getTipo();
    
    return os;//stub
}



// REQUIRES: tipoString represents a MaquinaTipo.
// MODIFIES: None.
//  EFFECTS: Returns the enum representation of the given string.
// TODO: Throw new illegal argument exception if tipoString is not valid.
Maquina::MaquinaTipo Maquina::getTipo(string tipoString){
    MaquinaTipo output;
    
    if (tipoString == "pecho") {
        output = MaquinaTipo::PECHO;
    } else if (tipoString == "espalda"){
        output = MaquinaTipo::ESPALDA;
    }else if (tipoString == "brazo"){
        output = MaquinaTipo::BRAZO;
    }else if (tipoString == "pierna"){
        output = MaquinaTipo::PIERNA;
    }else if (tipoString == "abdomen"){
        output = MaquinaTipo::ABDOMEN;
    }
    
    return output;
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
            
        default:
            break;
    }
    
    return output;
}










