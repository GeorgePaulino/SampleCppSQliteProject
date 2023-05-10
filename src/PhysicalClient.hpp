#pragma once
#include"ClientBase.hpp"
#include"Building.hpp"

class PhysicalClient : public ClientBase
{
public:
    float income;
    Building building;
    
    PhysicalClient();
    PhysicalClient(int type, string id, string name, string phone, float income);
    ~PhysicalClient();

    int DeleteClient() override;
    int UpdateClient() override;
    int CreateClient() override;
    void PrintClient() override;
    bool HasBuilding() override;
};
