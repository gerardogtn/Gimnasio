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
    os  << setw(25) << gym.gymName << ": " << endl;
    os << "--------------------------------------------------" << endl;
    
    
    os << "El gimnasio cuenta con " << gym.userCount << setw(12) << "usuarios." << endl;
    os << "El gimnasio cuenta con " << gym.machineCount <<  setw(12) <<"maquinas." << endl;
    
    os << endl;
    
    
    return os;
}