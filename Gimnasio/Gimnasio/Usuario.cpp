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
    cout << setw(10) << this->nombre <<"esta usando la maquina de: ";
    cout << setw(3) << machine.getMachineName() << endl;
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

// REQUIRES: None.
// MODIFIES: this->rutinas.
//  EFFECTS: Adds a Rutina to rutinas.
void Usuario::addRutina(const Rutina & routine) {
    rutinas.push_back(routine);
}



// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Prints to console all the routines for a user.
void Usuario::printRutinas() const{
    
    if (rutinas.empty()) {
        cout << "No existe ninguna rutina para el usuario: "<< setw(20) << nombre;
        cout << setw(20) << apellido << ":(" << endl;
        return;
    }
    
    int j = 1;
    
    cout << "Estas son las rutinas del usuario " << nombre << " " << apellido << ":" << endl;
    
    for (auto i : rutinas){
        cout << "Rutina " << setw(2) << j << ": " << endl;
        cout << i << endl;
        j++;
    }
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the position of a rutina in this->rutinas. If not found, returns -1.
int  Usuario::findRutina(const int routineID) const{
    int i = 0;
    
    if (rutinas.empty())
    {
        cout << "No hay rutinas registradas" <<endl;
    }
    
    for(auto r: rutinas)
    {
        if (r.getRutinaID() == routineID) {
            return i;
        }
        
        i++;
    }
    
    
    return -1;
}





