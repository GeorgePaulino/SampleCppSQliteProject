#include"Building.hpp"

Building::Building()
{
}

Building::~Building()
{
}

void Building::deleteBuilding( Building* b){
    delete b;
    cout << " Construção Deletada";
    return;
}
