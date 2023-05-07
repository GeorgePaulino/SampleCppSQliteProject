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
    sqlite3 *db;
    if(SqliteManager::OpenDB(db)) return 1;
    string comm = "DELETE FROM ConstructionCompany WHERE CNPJ = '" + cnpj + "'";
    if(SqliteManager::Execute(db, comm)) return 2;
    sqlite3_close(db);
    cout << "Construction Company Deleted" << endl;
    return 0;
}

bool ConstructionCompany::HasBuilding(){
    return buildings.size() != 0;
}