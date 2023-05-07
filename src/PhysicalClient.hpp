#include"ClientBase.hpp"

#include"Building.hpp"

class PhysicalClient : public ClientBase
{
public:
    float income;
    Building* building;
    string 	StartDate, EndDate;
    
    PhysicalClient(string zip, string name, string phone, string income, string startDate, string endDate);
    ~PhysicalClient();

    int DeleteClient() override;
    void PrintClient() override;
};
