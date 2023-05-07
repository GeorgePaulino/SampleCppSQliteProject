#include "ConstructionCompany.hpp"

ConstructionCompany::ConstructionCompany() {}

ConstructionCompany::ConstructionCompany(string cnpj, string name, string zip, string phone, float avaliation) : cnpj(cnpj), name(name), zip(zip), phone(phone), avaliation(avaliation)
{
    cout << "Created some" << endl;
}

ConstructionCompany::~ConstructionCompany()
{
    // Deallocating vector memory
    buildings.clear();
    vector<Building *>().swap(buildings);
}

int ConstructionCompany::DeleteCompany()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;
    string comm = "DELETE FROM ConstructionCompany WHERE CNPJ = '" + cnpj + "'";
    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;
    sqlite3_close(db);
    cout << "Construction Company Deleted" << endl;
    return 0;
}

int ConstructionCompany::UpdateCompany()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;

    stringstream ss;
    ss << "UPDATE ConstructionCompany SET CNPJ='" << cnpj << "', Name='" << name
       << "', PhoneNumber='" << phone << "', Avaliation='" << avaliation << "' WHERE CNPJ='" << cnpj << "'";
    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;
    sqlite3_close(db);
    cout << "Construction Company Updated" << endl;
    return 0;
}

int ConstructionCompany::CreateCompany()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;

    stringstream ss;
    ss << "INSERT INTO ConstructionCompany (CNPJ, Name, PhoneNumber, Avaliation) VALUES ('"
       << cnpj << "', '" << name << "', '" << phone << "', " << avaliation << ")";
    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);
    
    cout << "Construction Company Create" << endl;
    
    return 0;
}

bool ConstructionCompany::HasBuilding()
{
    return buildings.size() != 0;
}