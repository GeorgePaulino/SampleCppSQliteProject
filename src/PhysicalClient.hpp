#include"ClientBase.hpp"

#include"Building.hpp"

class PhysicalClient : public ClientBase
{
public:
    float income;
    Building* building;
    
    PhysicalClient(/* args */);
    ~PhysicalClient();

    int DeleteClient() override;
    void PrintClient() override;
};
