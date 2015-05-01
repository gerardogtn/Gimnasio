//
//  Maquina.h
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __Gimnasio__Maquina__
#define __Gimnasio__Maquina__

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Maquina{
    friend ostream & operator<<(ostream & os, const Maquina & machine);
    
private:
    string machineName = "Maquina sin nombre.";
    int machineID;
    static int machineCount;
    enum class Tipo {PECHO, ESPALDA, HOMBRO, BICEP, TRICEP, PANTORRILLA, QUADRICEPS};
    Tipo machineType;
    
    Tipo getTipo(string tipoString);
    
public:
    Maquina(){
        machineID = ++machineCount;
    };
    
    Maquina(string nombreMaq, string tipoMaq) : machineName(nombreMaq){
        machineType = getTipo(tipoMaq);
        machineID   = ++machineCount;
    };
    
};




#endif /* defined(__Gimnasio__Maquina__) */
