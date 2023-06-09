#pragma once

#include <iostream>
#include <sstream>
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
    float avaliation;
    vector<Building *> buildings;

    ConstructionCompany();
    ConstructionCompany(string cnpj, string name, string zip, string phone, float avaliation);
    ~ConstructionCompany();
    bool Search(string info);
    int DeleteCompany();
    int UpdateCompany(string lastId);
    int CreateCompany();
    bool HasBuilding();
    void Print();
    string GetAsCSV();
};