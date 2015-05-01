//
//  Usuario.cpp
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Usuario.h"

int Usuario::userCount = 0; 

// REQUIRES:
// MODIFIES:
//  EFFECTS:

// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Overloads stream output operator.
std::ostream & operator<<(std::ostream & os, Usuario & user){
    cout << "El usuario " << user.userID << " se llama: " << setw(20) << user.nombre << setw(20) << user.apellido;
    
    return os; 
}
