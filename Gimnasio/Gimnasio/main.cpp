//
//  main.cpp
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>

#include "Gimnasio.h"

int getInt(int);

int main(int argc, const char * argv[]) {
    Gimnasio sportsWorld("Sports world");
    
    Usuario A;
    
    Usuario B("Juan", "Perez");
    
    Maquina AA;
    Maquina BB("chest-press", "pecho");
    Maquina CC("chest-press", "pecho");
    
    sportsWorld.addUser(A);
    sportsWorld.addUser(A);
    sportsWorld.addUser(B);
    sportsWorld.addUser("Andrea", "Rodriguez");
    sportsWorld.addUser("Ana", "Karenina");
    
    sportsWorld.addMachine(AA);
    sportsWorld.addMachine(BB);
    sportsWorld.addMachine(BB);
    sportsWorld.addMachine(CC);
    
    std::cout << sportsWorld;
    
    sportsWorld.printMachines();
    sportsWorld.printUsers();
    
    B.hacerEjercicio(BB); 
    
    // Menú de Opciones para el Usuario
    int option=1;
    while (option!=6)
    {
        std::cout <<"Bienvenido a Sports World \n";
        std::cout <<"1. Registrar Nuevo Usuario \n";
        std::cout <<"2. Registrar una Nueva Máquina \n";
        std::cout <<"3. Mostrar la Cantidad de Usuarios y de Máquinas del Gimnasio \n";
        std::cout <<"4. Mostrar las Máquinas Disponibles \n";
        std::cout <<"5. Mostrar los Usuarios del Gimnasio\n";
        std::cout <<"6. Salir \n";
        std::cin >> option;
        option = getInt(option);
        switch (option)
        {
            case 1:
            {
                std::string name;
                std::cout << "Ingresa el nombre del usuario a agregar"<<std::endl;
                std::cin.ignore();
                std::getline(std::cin,name);
                std::string last;
                std::cout << "Ingresa el apellido del usuario"<<std::endl;
                std::cin.ignore();
                std::getline(std::cin,last);
                
                sportsWorld.addUser(name,last);
            }
            break;
            case 2:
            {
                std::string name;
                std::cout << "Ingresa el nombre de la máquina a agregar"<<std::endl;
                std::cin.ignore();
                std::getline(std::cin,name);
                std::string type;
                std::cout << "Ingresa el tipo de máquina que es: pecho, espalda, brazo, pierna o abdomen"<<std::endl;
                std::cin.ignore();
                std::getline(std::cin,type);
                
                Maquina newMachine(name,type);
                
                sportsWorld.addMachine(newMachine);
            }
            break;
            case 3:
            {
                std::cout << sportsWorld;
            }
            break;
            case 4:
            {
                sportsWorld.printMachines();
            }
            break;
            case 5:
            {
                sportsWorld.printUsers();
            }
            break;
            case 0:
            break;
        }
    }
    
    return 0;
}

int getInt(int value)
{
    if ( std::cin && value > 0 && value <= 6)
    {
        return value;
    }
    else
    {
        std::cout << "Por favor ingrese un valor numérico válido" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> value;
        return getInt(value);
    }
}
