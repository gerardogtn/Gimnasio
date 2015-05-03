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
    
public:
    enum class MaquinaTipo {NONE, PECHO, ESPALDA, BRAZO, PIERNA, ABDOMEN};
    
private:
    string machineName = "Maquina sin nombre";
    int machineID;
    static int machineCount;
    
    MaquinaTipo machineType = MaquinaTipo::NONE;
    
public:
    Maquina(){
        machineID = ++machineCount;
    };
    
    Maquina(string nombreMaq, string tipoMaq) : machineName(nombreMaq){
        setTipo(tipoMaq);
        machineID   = ++machineCount;
    };
    
    string getMachineName() const{
        return machineName;
    };
    
    int getMachineID() const{
        return machineID;
    }
    
    
    void setTipo(const string tipoString);
    string getTipo() const;
    
    bool operator<(const Maquina machine) const;
    bool operator==(const Maquina machine) const; 
    
};




#endif /* defined(__Gimnasio__Maquina__) */
