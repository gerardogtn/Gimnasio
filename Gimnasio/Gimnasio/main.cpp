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
    Usuario C("Alex", "Terrazas", 10, 4);
    
    Maquina AA;
    Maquina BB("chest-press", "pecho");
    Maquina CC("chest-press", "pecho");
    Maquina DD("leg-press","pierna");
    
    sportsWorld.addUser(A);
    sportsWorld.addUser(A);
    sportsWorld.addUser(B);
    sportsWorld.addUser("Andrea", "Rodriguez");
    sportsWorld.addUser("Ana", "Karenina");
    
    sportsWorld.addMachine(AA);
    sportsWorld.addMachine(BB);
    sportsWorld.addMachine(BB);
    sportsWorld.addMachine(CC);
    sportsWorld.addMachine(DD);
    
    std::cout << sportsWorld;
    
    sportsWorld.printMachines();
    sportsWorld.printUsers();
    
    //B.hacerEjercicio(BB);
    
    // Menú de Opciones para el Usuario
    int option=1;
    while (option!=9)
    {
        std::cout << "Bienvenido a Sports World."                                     << std::endl;
        std::cout << "1. Registrar Nuevo Usuario."                                    << std::endl;
        std::cout << "2. Registrar una Nueva Máquina."                                << std::endl;
        std::cout << "3. Mostrar la Cantidad de Usuarios y de Máquinas del Gimnasio." << std::endl;
        std::cout << "4. Mostrar las Máquinas Disponibles."                           << std::endl;
        std::cout << "5. Mostrar los Usuarios del Gimnasio."                          << std::endl;
        std::cout << "6. Crear una nueva rutina a un usuario."                        << std::endl;
        std::cout << "7. Adicionar una maquina a una rutina existente. "              << std::endl;
        std::cout << "8. Mostrar las rutinas de un usuario."                          << std::endl;
        std::cout << "9. Salir \n"                                                     << std::endl;
        std::cin >> option;
        option = getInt(option);
        switch (option)
        {
            case 1:{
                
                /* REGISTRAR USUARIO */
                std::string name;
                std::cout << "Ingresa el nombre del usuario a agregar"<<std::endl;
                std::cin.ignore();
                std::getline(std::cin,name);
                std::string last;
                std::cout << "Ingresa el apellido del usuario"<<std::endl;
                std::getline(std::cin,last);
                
                sportsWorld.addUser(name,last);
                }
                
                break;
                
                
            case 2:{
                /* REGISTRAR MAQUINA */
                std::string name;
                std::cout << "Ingresa el nombre de la máquina a agregar"<<std::endl;
                std::cin.ignore();
                std::getline(std::cin,name);
                std::string type;
                std::cout << "Ingresa el tipo de máquina que es: pecho, espalda, brazo, pierna o abdomen"<<std::endl;
                std::getline(std::cin,type);
                
                Maquina newMachine(name,type);
                
                sportsWorld.addMachine(newMachine);
                }
                
                break;
                
                
            case 3: {
                /* IMPRIMIR CANTIDAD DE USUARIOS Y MAQUINAS */
                std::cout << sportsWorld;
                }
                
                break;
                
                
            case 4: {
                /* IMPRIMIR LAS MAQUINAS DEL GIMNASIO */
                sportsWorld.printMachines();
                }
                break;
                
                
            case 5: {
                /* IMPRIMIR LOS USUARIOS DEL GIMNASIO */ 
                sportsWorld.printUsers();
                }
                
                break;
                
                
            case 6: {
                /* CREAR UNA RUTINA */
                string rutineType;
                cout << "¿Que tipo de rutina quieres agregar?" << endl;
                cin.ignore();
                getline(cin,rutineType);
                Rutina routineToAdd(rutineType);
                
                
                int userID;
                std::cout << "Ingresa el número de usuario al que se le agregará una rutina" << std::endl;
                std::cin >> userID;
                userID = getInt(userID);
                
                int userPosition = sportsWorld.findUser(userID);
                
                if (userPosition == -1) {
                    cout << "No existe el usuario en este gimnasio." << endl;
                } else {
                    sportsWorld.getUsuarios()->at(userPosition).addRutina(routineToAdd);
                }
                
                
                }
                
                break;
                
            case 7: {
                /* ANADIR UNA MAQUINA A UNA RUTINA */
                int userID;
                std::cout << "Ingresa el número de usuario al que se le modificara su rutina: " << std::endl;
                std::cin >> userID;
                userID = getInt(userID);
                
                int userPosition = sportsWorld.findUser(userID);
                if (userPosition == -1) {
                    cout << "No existe el usuario en este gimnasio." << endl;
                    break;
                }
                
                Usuario * workingUser = sportsWorld.getUserAt(userPosition);
                
                int routineID;
                std::cout << "Ingresa el número de rutina a modificar: " << std::endl;
                std::cin >> routineID;
                routineID = getInt(routineID);
                
                int routinePos = workingUser->findRutina(routineID);
                if (routinePos == -1) {
                    cout << "No existe esa rutina para este usuario." << endl;
                    break;
                }
                
                Rutina * workingRutina = workingUser->getRutinaAt(routinePos);
                
                int machineID;
                std::cout << "Ingresa el número de maquina a insertar: " << std::endl;
                std::cin >> machineID;
                machineID = getInt(machineID);
                
                int machinePos = sportsWorld.findMachine(machineID);
                if (machinePos == -1) {
                    cout << "No existe tal maquina en este gimnasio" << endl;
                    break;
                }
                
                Maquina workingMachine = sportsWorld.getMaquinas()[machinePos];
                workingRutina->addEquipment(workingMachine);
            
                cout << "La maquina: " << workingMachine.getMachineName();
                cout << " ha sido añadida correctamente a la rutina: ";
                cout <<  workingUser->getRutinaAt(routinePos)->getRutinaID();
                cout << " del usuario: " << setw(15) << workingUser->getName() << endl << endl;
            }
            break;
                
            case 8: {
                /* IMPRIMIR LAS RUTINAS DE UN USUARIO */
                int userID;
                std::cout << "Ingresa el número de usuario cuyas rutinas quieres ver" << std::endl;
                std::cin >> userID;
                userID = getInt(userID);
                
                int userPosition = sportsWorld.findUser(userID);
                
                if (userPosition == -1) {
                    cout << "No existe el usuario en este gimnasio." << endl;
                } else {
                    vector<Usuario> usuarios = *sportsWorld.getUsuarios();
                    usuarios[userPosition].printRutinas();
                }
                
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
    if ( std::cin && value > 0)
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



