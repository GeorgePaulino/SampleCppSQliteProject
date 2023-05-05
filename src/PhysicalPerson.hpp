#include"ClientBase.hpp"

#include"Building.hpp"

class PhysicalPerson : public ClientBase
{
public:

    float income;
    Building building;
    
    PhysicalPerson(/* args */);
    ~PhysicalPerson();
};
