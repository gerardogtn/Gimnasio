//
//  Rutina.cpp
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Rutina.h"

void Rutina::addEquipment(Maquina machine)
{
    equipo.push_back(machine);
}

ostream & operator<<(ostream & os, const Rutina & rutina)
{
    os << "Esta rutina es de tipo " << rutina.tipo << std::endl;
    
    rutina.printEquipment();
    
    return os;
}

void Rutina::printEquipment() const
{
    std::cout << "Esta rutina usa las máquinas: " << std::endl;
    
    for (auto i: equipo)
    {
        std::cout << i << std::endl;
    }
    
    std::cout << std::endl;
}

vector<Maquina> Rutina::getEquipo()
{
    return equipo;
}