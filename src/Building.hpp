#pragma once
#include<string>
using namespace std;

class Building
{
public:
    string cnpj;
    string clientCnpj;
    
    float price;
    string names;
    string startDate;
    string endDate;

    Building();
    ~Building();
};