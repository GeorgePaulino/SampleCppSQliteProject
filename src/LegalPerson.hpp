#include <iostream>
#include <string>
#include <vector>
#include "Building.hpp"
#include "ClietBase.hpp"

using namespace std;

class LegalPerson : public ClientBase {
public:
    vector<Building> legalPerson;
    int zipCode;
    float avaliation;
    string occupationArea, avaliationName;

    LegalPerson();
    ~LegalPerson();

    void avaliation(float a);
};