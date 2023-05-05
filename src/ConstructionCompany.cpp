#include"ConstructionCompany.hpp"

ConstructionCompany::ConstructionCompany(){}

ConstructionCompany::ConstructionCompany(string cnpj, string name, string zip, string phone, float avaliation) :
    cnpj(cnpj), name(name), zip(zip), phone(phone), avaliation(avaliation)
{
    cout << "Created some" << endl;
}

ConstructionCompany::~ConstructionCompany()
{
    // Deallocating vector memory
    buildings.clear();
    vector<Building *>().swap(buildings);
}

int ConstructionCompany::DeleteCompany(){
    cout << "Companinha de Construção Deleta";
    return 0;
}
