//
//  Usuario.h
//  Gimnasio
//
//  Created by Gerardo Teruel on 5/1/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __Gimnasio__Usuario__
#define __Gimnasio__Usuario__
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "Maquina.h"
#include "Rutina.h"

using namespace std;

class Usuario{
    friend std::ostream & operator<<(std::ostream & os, Usuario & user);
    
private:
    std::string nombre = "Sin nombre";
    std::string apellido = "Sin apellido";
    int userID;
    static int userCount;
    int averageRepetition = 12;
    int restedFactor = 12;
    int tiredDecrement = 1; 
    vector<Rutina> rutinas;
    
    void decrementRestedFactor(); 
    
public:
    Usuario(){ userID = ++userCount; };
    Usuario(string name, string _apellido) : nombre(name), apellido(_apellido) {
        userID = ++userCount;
    };
    Usuario(string name, string _apellido, int averageRep, int _tiredDec) : nombre(name), apellido(_apellido){
        userID = ++userCount;
        setAvgRep(averageRep);
        setTiredFactor(_tiredDec);
    };
    
    int getUserID() const{
        return userID;
    }
    
    void setAvgRep(int averageRep){
        if (averageRep > 2 && averageRep < 40) {
            averageRepetition = averageRep;
        }
    }
    
    void setTiredFactor(int tiredness){
        if (tiredness >= 1 && tiredness < averageRepetition){
            tiredDecrement = tiredness;
        }
    }
    
    void hacerEjercicio(const Maquina & machine); 
    
    void addRutina(map<Maquina,int>);
    void printRutinas();
};



#include <stdio.h>

#endif /* defined(__Gimnasio__Usuario__) */
