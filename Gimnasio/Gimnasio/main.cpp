//
//  main.cpp
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>

#include "Gimnasio.h"

int main(int argc, const char * argv[]) {
    Gimnasio sportsWorld("Sports world");
    
    Usuario A;
    Usuario B("Juan", "Perez");
    
    sportsWorld.addUser(A);
    sportsWorld.addUser(B);
    sportsWorld.addUser("Andrea", "Rodriguez");
    sportsWorld.addUser("Ana", "Karenina");
    
    std::cout << sportsWorld << std::endl;
    
    //sportsWorld.printMachines();
    sportsWorld.printUsers();
    return 0;
}
