#pragma once
#include"ConstructionCompany.hpp"
#include"ClientBase.hpp"

#include<string>

using namespace std;

// Solving Circular Dependency
class ConstructionCompany;

class Building
{
public:
    ConstructionCompany* company;
    ClientBase* person;

    float price;
    string name;
    string startDate;
    string endDate;

    Building(/* args */);
    ~Building();
    void deleteBuilding(Building *b);
};
