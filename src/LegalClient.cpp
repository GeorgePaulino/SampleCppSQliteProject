#include "LegalClient.hpp"
//    string id ; string name; string phone, string occupation; float avaliation;
LegalClient::LegalClient(string zip, string name, string phone, string occupation, float avaliation)
:
    zip(zip), name(name), phone(phone), occupation(occupation), avaliation(avaliation) {}

<<<<<<< HEAD
LegalClient::~LegalClie, nt(){}
=======
LegalClient::LegalClient() {}
LegalClient::~LegalClient() {}
>>>>>>> 473453e66982ef3d29a70206c2419f2a775050ec

int LegalClient::DeleteClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;
    string comm = "DELETE FROM ClientLegal WHERE CNPJ = '" + id + "'";
    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;
    sqlite3_close(db);
    cout << "Legal Client Deleted" << endl;
    return 0;
}

int LegalClient::UpdateClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;
    stringstream ss;
    ss << "UPDATE ClientLegal SET CNPJ='" << id << "', Name='" << name
       << "', PhoneNumber='" << phone << "', ZipCode='" << zip << "' OccupationArea='"
       << occupation << "', Avaliation='" << avaliation << "' WHERE CNPJ='" << id << "'";
    string comm = ss.str();
    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;
    sqlite3_close(db);
    cout << "Legal Client Updated" << endl;
    return 0;
}

int LegalClient::CreateClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;
    
    stringstream ss;
    ss << "INSERT INTO ClientLegal (CNPJ, Name, PhoneNumber, ZipCode, OccupationArea, Avaliation) VALUES ('" << id << "', '"
       << name << "', '" << phone << "', '" << zip << "', '" << occupation << "', '" << avaliation << "')";
    string comm = ss.str();
    
    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;
    sqlite3_close(db);

    for(auto &building: buildings){
        building.CreateBuilding();
    }

    cout << "Legal Client Created" << endl;


    return 0;
}

void LegalClient::PrintClient()
{
    std::cout << "Name: " << name << " CNPJ: " << id << std::endl;
}

bool LegalClient::HasBuilding()
{
    return buildings.size() != 0;
}