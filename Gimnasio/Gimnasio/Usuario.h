//
//  Usuario.h
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __Gimnasio__Usuario__
#define __Gimnasio__Usuario__
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Usuario{
    friend std::ostream & operator<<(std::ostream & os, Usuario & user);
    
private:
    std::string nombre = "Sin nombre.";
    std::string apellido = "Sin apellido.";
    int userID;
    static int userCount;
    // list<Rutina> rutinas;
    
public:
    Usuario(){ userID = ++userCount; };
    Usuario(string name, string _apellido) : nombre(name), apellido(_apellido) {
        userID = ++userCount;
    };
    
    int getUserID(){
        return userID;
    }
    
};



#include <stdio.h>

#endif /* defined(__Gimnasio__Usuario__) */
