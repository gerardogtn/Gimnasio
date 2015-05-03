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
    
    B.hacerEjercicio(BB); 
    
    // Menú de Opciones para el Usuario
    int option=1;
    while (option!=8)
    {
        std::cout << "Bienvenido a Sports World."                                     << std::endl;
        std::cout << "1. Registrar Nuevo Usuario."                                    << std::endl;
        std::cout << "2. Registrar una Nueva Máquina."                                << std::endl;
        std::cout << "3. Mostrar la Cantidad de Usuarios y de Máquinas del Gimnasio." << std::endl;
        std::cout << "4. Mostrar las Máquinas Disponibles."                           << std::endl;
        std::cout << "5. Mostrar los Usuarios del Gimnasio."                          << std::endl;
        std::cout << "6. Generar una rutina a un usuario."                            << std::endl;
        std::cout << "7. Mostrar las rutinas de un usuario."                          << std::endl;
        //std::cout << "8. Hacer ejercicio. ";
        //std::cout << "";
        //std::cout << "";
        std::cout <<"8. Salir \n"                                                     << std::endl;
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
                std::cin.ignore();
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
                
                std::cout << type << std::endl;
                
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
                
                string type;
                cout << "¿Que tipo de rutina quieres agregar?" << endl;
                cin.ignore();
                
                // PARA QUE UN GETLINE? NO BASTA CON UN CIN << TYPE???
                getline(cin,type);
                
                /* NOT WORKING
                int user;
                std::cout << "Ingresa el número de usuario al que se le agregará una rutina" << std::endl;
                std::cin >> user;
                getInt(user);
                
                sportsWorld.findUser(user).addRutina();*/
                
               // A.addRutina(sportsWorld.getMachines());
                
                
                
                
                }
                
                break;
                
                
            case 7: {
                /* NOT WORKING
                int user;
                std::cout << "Ingresa el número de usuario cuyas rutinas quieres ver" << std::endl;
                std::cin >> user;
                getInt(user);
                
                sportsWorld.findUser(user).printRutinas(); */
                
                A.printRutinas();
                }
                
            case 0:
                break;
        }
    }
    
    return 0;
}

int getInt(int value)
{
    if ( std::cin && value > 0 && value <= 8)
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



/* CODE FOR INTERACTIVE MENU.
 
 
 string type;
 cout << "¿Que tipo de rutina quieres agregar?" << endl;
 cin.ignore();
 getline(cin,type);
 
 Rutina rutina(type);
 
 if (type =="pierna"||type=="general"||type=="pecho"||type=="abdomen"||type=="brazo"||type=="espalda")
 {
 for (auto i: maquinas)
 {
 if((get<0>(i).getTipo() == type) || type == "general")
 {
 rutina.addEquipment(get<0>(i));
 }
 }
 
 if (rutina.getEquipo().empty())
 {
 cout << "Por el momento no contamos con máquinas para ese tipo de rutina" << endl;
 }
 else
 {
 rutinas.push_back(rutina);
 }
 }
 else
 {
 cout << "No contamos son ese tipo de rutina" << endl;
 }
 
 
 
 */


