#pragma once

#include<sqlite3.h>
#include<string>
#include <iostream>

#include"ConstructionCompany.hpp"
#include"ClientBase.hpp"

using namespace std;

// Solving Circular Dependency
class ConstructionCompany;

class Building
{
public:
    ConstructionCompany* company;
    ClientBase* client;

    float price;
    string name;
    string startDate;
    string endDate;

    Building();
    ~Building();

    int DeleteBuilding();
};
