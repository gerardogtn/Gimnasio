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
    
    sportsWorld.addUser("Alejandro ", "Herce");
    sportsWorld.addUser("Alfredo ", "Campos");
    sportsWorld.addUser("Emilio ", "Ferreira");
    sportsWorld.addUser("Gerardo", "Teruel");
    sportsWorld.addUser("Gonzalo ", "Vergara");
    sportsWorld.addUser("Jonathan", "Ginsburg");
    sportsWorld.addUser("Juan ", "Leon");
    sportsWorld.addUser("Mauricio ", "Garcia");
    sportsWorld.addUser("Miguel ", "de la Colina");
    sportsWorld.addUser("Santiago ", "Rodriguez");
    
    sportsWorld.addUser("Margot ", "Duek");
    sportsWorld.addUser("Esther ", "Nereida");
    sportsWorld.addUser("Andrea ", "Eva");
    sportsWorld.addUser("Camila", "Catalina");
    sportsWorld.addUser("Aurora ", "Torres");
    sportsWorld.addUser("Yessica", "Romero");
    sportsWorld.addUser("Pilar ", "Suarez");
    sportsWorld.addUser("Tomasa ", "Busto");
    sportsWorld.addUser("Jovita ", "Escarcega");
    sportsWorld.addUser("Anastasia ", "Castro");
    
    Maquina A("banco-press", "abdomen");
    Maquina B("femorales", "pierna");
    Maquina C("leg-press","pierna");
    Maquina D("abductores", "pierna");
    Maquina E("dorsalera", "espalda");
    Maquina F("paralelas","abdomen");
    Maquina G("peck-deck", "pecho");
    Maquina H("banco-press", "pecho");
    Maquina I("remo","espalda");
    Maquina J("maquina de tricep", "brazo");
    Maquina K("maquina de bicep", "brazo");
    
    Usuario tiredQuick("Francisco", "Perez", 16, 4);
    Rutina  test("pecho");
    test.addEquipment(H);
    test.addEquipment(H);
    test.addEquipment(G);
    test.addEquipment(H);
    tiredQuick.addRutina(test); 
    
    sportsWorld.addUser(tiredQuick);
    
    sportsWorld.addMachine(A);
    sportsWorld.addMachine(A);
    sportsWorld.addMachine(A);
    sportsWorld.addMachine(A);
    sportsWorld.addMachine(B);
    sportsWorld.addMachine(B);
    sportsWorld.addMachine(B);
    sportsWorld.addMachine(C);
    sportsWorld.addMachine(D);
    sportsWorld.addMachine(D);
    sportsWorld.addMachine(E);
    sportsWorld.addMachine(E);
    sportsWorld.addMachine(E);
    sportsWorld.addMachine(F);
    sportsWorld.addMachine(G);
    sportsWorld.addMachine(G);
    sportsWorld.addMachine(H);
    sportsWorld.addMachine(I);
    sportsWorld.addMachine(I);
    sportsWorld.addMachine(I);
    sportsWorld.addMachine(I);
    sportsWorld.addMachine(J);
    sportsWorld.addMachine(K);
    
    std::cout << sportsWorld;
    
    sportsWorld.printMachines();
    sportsWorld.printUsers();
    
    // Menú de Opciones para el Usuario
    int option=1;
    while (option!=15)
    {
        std::cout << "                    Bienvenido a sports world."                  << std::endl;
        std::cout << "1.  Registrar nuevo usuario."                                    << std::endl;
        std::cout << "2.  Eliminar un usuario."                                        << std::endl;
        std::cout << "3.  Registrar una nueva máquina."                                << std::endl;
        std::cout << "4.  Eliminar una maquina."                                       << std::endl;
        std::cout << "5.  Mostrar la cantidad de usuarios y de máquinas del gimnasio." << std::endl;
        std::cout << "6.  Mostrar las máquinas disponibles."                           << std::endl;
        std::cout << "7.  Mostrar los usuarios del gimnasio."                          << std::endl;
        std::cout << "8.  Crear una nueva rutina a un usuario."                        << std::endl;
        std::cout << "9.  Eliminar una rutina de un usuario."                          << std::endl;
        std::cout << "10. Adicionar una maquina a una rutina existente. "              << std::endl;
        std::cout << "11. Eliminar una máquina de una rutina existente. "              << std::endl;
        std::cout << "12. Mostrar las rutinas de un usuario."                          << std::endl;
        std::cout << "13. Hacer ejercicio en una maquina especifica. "                 << std::endl;
        std::cout << "14. Hacer todos los ejercicios de una rutina. "                  << std::endl;
        std::cout << "15. Salir \n"                                                    << std::endl;
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
                
                /* Eliminar USUARIO */
                int userID;
                if (sportsWorld.getUsuarios()->empty()){
                    std::cout << "No existen usuarios en este gimnasio: " << std::endl;
                }
                std::cout << "Ingresa el número de usuario que quieres eliminar: " << std::endl;
                std::cin >> userID;
                userID = getInt(userID);
                
                int userPosition = sportsWorld.findUser(userID);
                if (userPosition == -1) {
                    cout << "No existe el usuario en este gimnasio." << endl;
                    break;
                }
                
                sportsWorld.removeUser(userPosition);
                cout << "Usuario eliminado" << endl;
                }
                
                break;    
                
            case 3:{
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
            
            case 4:{
                
                /* Eliminar Máquina */
                int machineID;
                if (sportsWorld.getMaquinas().empty()) {
                    std::cout << "No existen maquinas en este gimnasio: " << std::endl;
                    break;
                }
                
                std::cout << "Ingresa el número de máquina que quieres eliminar: " << std::endl;
                std::cin >> machineID;
                machineID = getInt(machineID);
                
                if (sportsWorld.findMachine(machineID) == -1) {
                    cout << "No existe esa máquina en este gimnasio." << endl;
                    break;
                }
                
                sportsWorld.removeMachine(machineID);
                cout << "Máquina eliminada" << endl;
                }
                
                break;     
                
            case 5: {
                /* IMPRIMIR CANTIDAD DE USUARIOS Y MAQUINAS */
                std::cout << sportsWorld;
                }
                
                break;
                
                
            case 6: {
                /* IMPRIMIR LAS MAQUINAS DEL GIMNASIO */
                sportsWorld.printMachines();
                }
                break;
                
                
            case 7: {
                /* IMPRIMIR LOS USUARIOS DEL GIMNASIO */ 
                sportsWorld.printUsers();
                }
                
                break;
                
                
            case 8: {
                /* CREAR UNA RUTINA */
                if (sportsWorld.getUsuarios()->empty()) {
                    std::cout << "No existen usuarios en este gimnasio" << std::endl;
                    break;
                }
                string rutineType;
                cout << "Ingresa el tipo de RUTINA que quires agregar";
                cout << ": pecho, espalda, brazo, pierna o abdomen" << endl;
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
                    cout << "Se ha añadido correctamente una rutina con numero de identificacion";
                    cout << setw(3) << routineToAdd.getRutinaID();
                    cout << "Al usuario con identificacion: " << setw(3) << userID;
                    sportsWorld.getUsuarios()->at(userPosition).addRutina(routineToAdd);
                }
                
                
                }
                
                break;
            
            case 9: {
                /* ELIMINAR UNA RUTINA */
                if (sportsWorld.getUsuarios()->empty()) {
                    std::cout << "No existen usuarios en este gimnasio" << std::endl;
                    break;
                }
                int userID;
                std::cout << "Ingresa el número de usuario al que se le quitará una rutina" << std::endl;
                std::cin >> userID;
                userID = getInt(userID);
                
                int userPosition = sportsWorld.findUser(userID);
                
                vector<Usuario> usuarios = *sportsWorld.getUsuarios();
                usuarios[userPosition].printRutinas();
                
                if (userPosition == -1) {
                    cout << "No existe el usuario en este gimnasio." << endl;
                    break;
                } else {
                    Usuario * workingUser = sportsWorld.getUserAt(userPosition);
                    
                    if(workingUser->getRutinas()->empty()){
                        cout << "Este usuario no tiene ninguna rutina" << endl;
                        break;
                    }
                    
                    int routineID;
                    std::cout << "Ingresa el número de rutina a modificar: " << std::endl;
                    std::cin >> routineID;
                    routineID = getInt(routineID);
                    
                    
                    
                    int routinePos = workingUser->findRutina(routineID);
                    if (routinePos == -1) {
                    cout << "No existe esa rutina para este usuario." << endl;
                    break;
                    }
                    
                    sportsWorld.getUsuarios()->at(userPosition).removeRutina(routinePos);
                }
                
                
                }
                
                break;    
                
            case 10: {
                /* ANADIR UNA MAQUINA A UNA RUTINA */
                
                if (sportsWorld.getUsuarios()->empty()) {
                    std::cout << "No existen usuarios en este gimnasio" << std::endl;
                    break;
                }
                
                
                
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
                
                if(workingUser->getRutinas()->empty()){
                    cout << "Este usuario no tiene ninguna rutina" << endl;
                    break;
                }
                
                
                if(workingUser->getRutinas()->empty()){
                    cout << "Este usuario no tiene ninguna rutina" << endl;
                    break;
                }
                
                
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
                
                if (sportsWorld.getMaquinas().empty()) {
                    cout << "No existen maquinas en este gimnasio." << endl;
                    break;
                }
                
                
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
                
                if (workingRutina->addEquipment(workingMachine)){
                    cout << "La maquina: " << workingMachine.getMachineName();
                    cout << " ha sido añadida correctamente a la rutina: ";
                    cout <<  workingUser->getRutinaAt(routinePos)->getRutinaID();
                    cout << " del usuario: " << setw(15) << workingUser->getName() << endl << endl;
                }
                
            }
            break;
            
            case 11: {
                /* ELIMINAR UNA MAQUINA DE UNA RUTINA */
                if (sportsWorld.getUsuarios()->empty()) {
                    std::cout << "No existen usuarios en este gimnasio" << std::endl;
                    break;
                }
                
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
                
                
                if(workingUser->getRutinas()->empty()){
                    cout << "Este usuario no tiene ninguna rutina" << endl;
                    break;
                }
                
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
                
                if (sportsWorld.getMaquinas().empty()) {
                    cout << "No existen maquinas en este gimnasio." << endl;
                    break;
                }
                
                int machineID;
                std::cout << "Ingresa el número de maquina a eliminar de la rutina: " << std::endl;
                std::cin >> machineID;
                machineID = getInt(machineID);
                
                workingRutina->removeEquipment(machineID);
                
                }
                
                
            break;
                
                
            case 12: {
                /* IMPRIMIR LAS RUTINAS DE UN USUARIO */
                if (sportsWorld.getUsuarios()->empty()) {
                    std::cout << "No existen usuarios en este gimnasio" << std::endl;
                    break;
                }
                
                int userID;
                std::cout << "Ingresa el número de usuario cuyas rutinas quieres ver" << std::endl;
                std::cin >> userID;
                userID = getInt(userID);
                
                int userPosition = sportsWorld.findUser(userID);
                
                if (userPosition == -1) {
                    cout << "No existe el usuario en este gimnasio." << endl;
                } else {
                    vector<Usuario> usuarios = *sportsWorld.getUsuarios();
                    if(usuarios[userPosition].getRutinas()->empty()){
                        cout << "Este usuario no tiene ninguna rutina" << endl;
                        break;
                    }
                    usuarios[userPosition].printRutinas();
                }
                
            }
                
                break;
                
            case 13: {
                /* HACER EJERCICIO */
                if (sportsWorld.getUsuarios()->empty()) {
                    std::cout << "No existen usuarios en este gimnasio" << std::endl;
                    break;
                }
                
                int userID;
                std::cout << "Ingresa el número de usuario que se va a ejercitar" << std::endl;
                std::cin >> userID;
                userID = getInt(userID);
                
                int userPosition = sportsWorld.findUser(userID);
                
                if (userPosition == -1) {
                    cout << "No existe el usuario en este gimnasio." << endl;
                    break;
                }
                
                int machineID;
                std::cout << "Ingresa el número de maquina a ejercitar: " << std::endl;
                std::cin >> machineID;
                machineID = getInt(machineID);
                
                
                int machinePos = sportsWorld.findMachine(machineID);
                if (machinePos == -1) {
                    cout << "No existe tal maquina en este gimnasio" << endl;
                    break;
                }
                
                sportsWorld.getUsuarios()->at(userPosition).hacerEjercicio(sportsWorld.getMaquinas()[machinePos]);
                
                
            }
                
                break;
                
                
                
            case 14: {
                /* EJERCITAR RUTINA */
                if (sportsWorld.getUsuarios()->empty()) {
                    std::cout << "No existen usuarios en este gimnasio" << std::endl;
                    break;
                }
                
                int userID;
                std::cout << "Ingresa el número de usuario que se va a ejercitar" << std::endl;
                std::cin >> userID;
                userID = getInt(userID);
                
                int userPosition = sportsWorld.findUser(userID);
                
                if (userPosition == -1) {
                    cout << "No existe el usuario en este gimnasio." << endl;
                    break;
                }
                
                Usuario * workingUser = sportsWorld.getUserAt(userPosition);
                
                if(workingUser->getRutinas()->empty()){
                    cout << "Este usuario no tiene ninguna rutina" << endl;
                    break;
                }
                
                int routineID;
                std::cout << "Ingresa el número de rutina a ejercitar: " << std::endl;
                std::cin >> routineID;
                routineID = getInt(routineID);
                
                int routinePos = workingUser->findRutina(routineID);
                if (routinePos == -1) {
                    cout << "No existe esa rutina para este usuario." << endl;
                    break;
                }
                
                Rutina * workingRutina = workingUser->getRutinaAt(routinePos);

                workingUser->ejercitarRutina(*workingRutina);
                
                
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



