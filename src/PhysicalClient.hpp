#pragma once
#include"ClientBase.hpp"
#include"Building.hpp"

class PhysicalClient : public ClientBase
{
public:
    float income;
<<<<<<< HEAD
    Building* building;
    string 	StartDate, EndDate;
=======
    Building building;
>>>>>>> 473453e66982ef3d29a70206c2419f2a775050ec
    
    PhysicalClient(string zip, string name, string phone, string income, string startDate, string endDate);
    ~PhysicalClient();

    int DeleteClient() override;
    int UpdateClient() override;
    int CreateClient() override;
    void PrintClient() override;
    bool HasBuilding() override;
};
