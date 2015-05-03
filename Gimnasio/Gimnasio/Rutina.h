//
//  Rutina.h
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __Gimnasio__Rutina__
#define __Gimnasio__Rutina__

#include <stdio.h>
#include <vector>
#include "Maquina.h"

class Rutina{
    friend ostream & operator<<(ostream & os, const Rutina & rutina);
    
private:
    int routineID;
    static int routineCount;
    vector<Maquina> equipo;
    Maquina::MaquinaTipo rutineType;
    
public:
    Rutina() {
        routineID = ++routineCount;
    };
    Rutina(string t){
        setTipo(t);
        routineID = ++routineCount;
    };
    
    int getRutinaID() const{
        return routineID;
    }
    
    void setTipo(string tipoString);
    string getTipo() const;
    
    void addEquipment(const Maquina & machine);
    void addEquipment(const int equipmentID);
    void printEquipment() const;
    vector<Maquina> getEquipment() const;
    

    
};

#endif /* defined(__Gimnasio__Rutina__) */
