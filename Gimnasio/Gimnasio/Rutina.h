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
    
    public:
    Rutina(string t) : tipo(t) { }
    Rutina() {}
    void addEquipment(Maquina);
    friend ostream & operator<<(ostream & os, const Rutina & rutina);
    void printEquipment() const;
    vector<Maquina> getEquipo();
    
    private:
    std::string tipo;
    vector<Maquina> equipo;
};

#endif /* defined(__Gimnasio__Rutina__) */
