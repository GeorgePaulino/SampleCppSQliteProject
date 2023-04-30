#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Building.hpp"

using namespace std;

class ConstructionCompany
{
private:
public:
    string cnpj;
    string name;
    string zip;
    string phone;
    float avaliation;
    vector<Building> buildings;

    ConstructionCompany(string cnpj, string name, string zip, string phone, float avaliation);
    ~ConstructionCompany();
};