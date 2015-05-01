//
//  Gimnasio.cpp
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Gimnasio.h"


int Gimnasio::userCount = 0;
int Gimnasio::machineCount = 0;


// REQUIRES:
// MODIFIES:
//  EFFECTS:

// REQUIRES: None.
// MODIFIES: os.
//  EFFECTS: Overloads stream output operator.
ostream & operator<<(ostream & os, const Gimnasio & gym){
    os << "--------------------------------------------------" << endl;
    os << setw(25) << gym.gymName << ": " << endl;
    os << "--------------------------------------------------" << endl;
    
    
    os << "El gimnasio cuenta con " << gym.userCount << setw(12) << left << " usuarios." << endl;
    os << "El gimnasio cuenta con " << gym.machineCount <<  setw(12)<< left << " maquinas." << endl;
    
    os << endl;
    
    
    return os;
}

// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Prints to console the users of this gym.
void Gimnasio::printUsers() const{
    cout << "--------------------------------------------------" << endl;
    cout << "Los usuarios de "  << gymName << " son: " << endl;
    cout << "--------------------------------------------------" << endl;
    
    if (usuarios.empty()) {
        cout << "No existen usuarios" << endl;
        cout << endl; 
        return;
    }
    
    
    for (auto u :usuarios) {
        cout << u << endl;
    }
    
    cout << endl;
}




// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Prints to console the machines in this gym.
void Gimnasio::printMachines() const{
    cout << "--------------------------------------------------" << endl;
    cout << "Las maquinas de "  << gymName << " son: " << endl;
    cout << "--------------------------------------------------" << endl;
    
    if (maquinas.empty()) {
        cout << "No existen maquinas" << endl;
        cout << endl;
        return;
    }
    
    
    for (auto m : maquinas) {
        cout << "Existen " << m.second << " maquinas de nombre: ";
        cout << m.first << endl; 
    }
    
    cout << endl;
}




// REQUIRES: None
// MODIFIES: usuarios
//  EFFECTS: Adds user to usuarios.
void Gimnasio::addUser(const Usuario user){
    usuarios.push_back(user);
    userCount++; 
}


// REQUIRES: None.
// MODIFIES: usuarios.
//  EFFECTS: Creates a new usuario and adds it to users. 
void Gimnasio::addUser(const string userName, const string userLastName){
    addUser(Usuario(userName, userLastName)); 
}

// REQUIRES:
// MODIFIES:
//  EFFECTS:
void Gimnasio::addMachine(const Maquina machine){
    maquinas[machine]++;
    machineCount++;
}











