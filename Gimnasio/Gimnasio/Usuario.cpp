//
//  Usuario.cpp
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Usuario.h"
#include <unistd.h>

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

// REQUIRES: None.
// MODIFIES: this->restedFactor.
//  EFFECTS: Simulates exercising in a machine by printing to console.
void Usuario::hacerEjercicio(const Maquina & machine){
    if  (restedFactor <= 2){
        cout << setw(10) << this->nombre << "esta demasiado cansado para hacer ejercicio" << endl;
        return;
    }
    
    cout << "-----------------------------------------------------------------" << endl;
    cout << setw(10) << this->nombre <<"esta usando la maquina de: "<< setw(3) << machine.getMachineName() << endl;
    cout << "-----------------------------------------------------------------" << endl;
    
    int repetitions = averageRepetition;
    int substraction = restedFactor - 1;
    srand((unsigned) time(nullptr));
    
    while (repetitions > 1) {
        cout << "Faltan " << setw(2)<< repetitions << " repeticiones por hacer " << endl;
        sleep(1);
        repetitions = repetitions - (rand()%substraction + 1);
        substraction = repetitions;
    }
    
    cout << "Ejercicio finalizado \n" << endl;
    decrementRestedFactor();
    
    
}

// REQUIRES: None.
// MODIFIES: this->restedFactor.
//  EFFECTS: Decrements the rested factor.
void Usuario::decrementRestedFactor(){
    int a = restedFactor - tiredDecrement;
    if (a < 2) {
        restedFactor = 2;
    } else {
        restedFactor = a;
    }
    
}




