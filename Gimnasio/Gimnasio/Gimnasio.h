//
//  Gimnasio.h
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __Gimnasio__Gimnasio__
#define __Gimnasio__Gimnasio__

#include <stdio.h>

#include <iostream>
#include <iomanip>

#include <map>
#include <list>
#include <string>

#include "Maquina.h"
#include "Usuario.h"

using namespace std;

class Gimnasio{
    friend ostream & operator<<(ostream & os, const Gimnasio & gym);
    
    
private:
    list<Usuario> usuarios;
    
    // Un mapa que almacena las maquinas y el numero de maquinas.
    map<Maquina, int> maquinas;
    
    string gymName = "Gimnasio sin nombre";
    static int machineCount;
    static int userCount;
    
public:
    Gimnasio(){};
    Gimnasio(string name) : gymName(name){};
    
    void addUser(const Usuario user);
    void addUser(const string userName, const string userLastName);
    void addMachine(const Maquina machine);
    
    // TODO: VERIFY THAT THIS IS NECESSARY.
    map<Maquina,int> getMachines();
    
    void printUsers() const;
    void printMachines() const;
    
    Usuario findUser(int);
    
};



#endif /* defined(__Gimnasio__Gimnasio__) */
