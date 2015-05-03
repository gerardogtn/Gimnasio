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
    os << "-----------------------------------------------------------------" << endl;
    os << setw(25) << gym.gymName << ": " << endl;
    os << "-----------------------------------------------------------------" << endl;
    
    
    os << "El gimnasio cuenta con " << gym.userCount << setw(12) << left << " usuarios." << endl;
    os << "El gimnasio cuenta con " << gym.machineCount <<  setw(12)<< left << " maquinas." << endl;
    
    os << endl;
    
    
    return os;
}

// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Prints to console the users of this gym.
void Gimnasio::printUsers() const{
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Los usuarios de "  << gymName << " son: " << endl;
    cout << "-----------------------------------------------------------------" << endl;
    
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
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Las maquinas de "  << gymName << " son: " << endl;
    cout << "-----------------------------------------------------------------" << endl;
    
    if (maquinas.empty()) {
        cout << "No existen maquinas" << endl;
        cout << endl;
        return;
    }
    
    
    for (auto m : maquinas) {
        cout << "Existe(n) " << setw(3) << m.second;
        cout << " con numero de identificacion " << setw(3) << m.first.getMachineID();
        cout << " maquina(s) de nombre: ";
        cout << m.first << endl; 
    }
    
    cout << endl;
}




// REQUIRES: None
// MODIFIES: usuarios
//  EFFECTS: Adds user to usuarios.
void Gimnasio::addUser(const Usuario user){
    for(auto u :usuarios){
        if  (u.getUserID() == user.getUserID()){
            return; 
        }
    }
    
    
    usuarios.push_back(user);
    userCount++; 
}


// REQUIRES: None.
// MODIFIES: usuarios.
//  EFFECTS: Creates a new usuario and adds it to users. 
void Gimnasio::addUser(const string userName, const string userLastName){
    addUser(Usuario(userName, userLastName)); 
}

// REQUIRES: None.
// MODIFIES: this->maquinas.
//  EFFECTS: Adds a new machine to maquinas map. If machine already exists, increase its machine count.
void Gimnasio::addMachine(const Maquina machine){
    maquinas[machine]++;
    machineCount++;
}

// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the position of a user in this->usuarios. If not found, returns -1.
int Gimnasio::findUser(const int userID) const {
    int i = 0;
    
    if (usuarios.size() <= 0){
        cout << "No hay usuarios registrados" <<endl;
    }
    
    for(auto u: usuarios){
        
        if (u.getUserID() == userID){
            return i;
        }
        
        i++;
    }
    
    return -1;
}



// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the position of a user in this->maquinas. If not found, returns -1.
int Gimnasio::findMachine(const int machineID) const{
    int i = 0;
    
    if (maquinas.empty()){
        cout << "No hay maquinas registradas" <<endl;
    }
    
    for(auto m : maquinas){
        
        if (get<0>(m).getMachineID() == machineID){
            return i;
        }
        
        i++;
    }
    
    return -1;
}







