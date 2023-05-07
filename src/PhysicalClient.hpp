#pragma once
#include"ClientBase.hpp"
#include"Building.hpp"

class PhysicalClient : public ClientBase
{
public:
    float income;
    Building building;
    
    PhysicalClient(/* args */);
    ~PhysicalClient();

    int DeleteClient() override;
    int UpdateClient() override;
    int CreateClient() override;
    void PrintClient() override;
    bool HasBuilding() override;
};
