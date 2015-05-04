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
#include <vector>

#include "Maquina.h"
#include "Usuario.h"

using namespace std;

class Gimnasio{
    friend ostream & operator<<(ostream & os, const Gimnasio & gym);
    
    
private:
    vector<Usuario> usuarios;
    // Un mapa que almacena las maquinas y el numero de maquinas.
    map<Maquina, int> maquinas;
    
    string gymName = "Gimnasio sin nombre";
    static int machineCount;
    static int userCount;
    
public:
    Gimnasio(){};
    Gimnasio(string name) : gymName(name){};
    
    vector<Usuario> * getUsuarios() {
        return &usuarios;
    }
    
    vector<Maquina> getMaquinas() const {
        vector<Maquina> output;
        
        for (auto m : maquinas){
            output.push_back(m.first);
        }

        return output;
    }
    
    
    void addUser(const Usuario user);
    void addUser(const string userName, const string userLastName);
    void addMachine(const Maquina machine);
    
    void printUsers() const;
    void printMachines() const;
    
    int findUser(const int userID) const;
    int findMachine(const int machineID) const;
    Usuario * getUserAt(const int position);
    
};



#endif /* defined(__Gimnasio__Gimnasio__) */
