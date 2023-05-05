#include <iostream>
#include <string>
#include "Building.hpp"
#include "physicalPerson.hpp"

using namespace std;

    PysicalPerson::PysicalPerson(){ person.cnpj == " "; }

    void PysicalPerson::readPerson( ){}
    void PysicalPerson::showPerson( ){}
    
    void PysicalPerson::deletePerson( PysicalPerson* p){
        delete p;
        cout << "Pessoa Fisica deletada";
        return;
    }
