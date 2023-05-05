#include <iostream>
#include <string>
#include "Building.hpp"
#include "ClietBase.hpp"

using namespace std;

class PysicalPerson : public ClientBase{
public:
    Building person;
    float income;
    
    PysicalPerson(){}

    void readPerson(){}
    void showPerson(){}
    void deletePerson( PysicalPerson* p){}
};