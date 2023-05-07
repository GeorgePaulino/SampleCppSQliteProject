#pragma once

#include <iostream>
#include <string>
#include <vector>
#include"SqliteManager.hpp"

#include "Building.hpp"

using namespace std;

// Solving Circular Dependency
class Building;

class ConstructionCompany
{
private:
public:
    string cnpj;
    string name;
    string zip;
    string phone;
    string avaliation;
    vector<Building *> buildings;

    ConstructionCompany();
    ConstructionCompany(string cnpj, string name, string zip, string phone, string avaliation);
    ~ConstructionCompany();
    int DeleteCompany();
    int UpdateCompany();
    int CreateCompany();
    bool HasBuilding();
};