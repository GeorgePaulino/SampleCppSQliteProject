#include "LegalClient.hpp"

LegalClient::LegalClient(){}
LegalClient::~LegalClient(){}

int LegalClient::DeleteClient()
{
    sqlite3 *db;
    if(SqliteManager::OpenDB(db)) return 1;
    string comm = "DELETE FROM ClientLegalPerson WHERE CNPJ = '" + id + "'";
    if(SqliteManager::Execute(db, comm)) return 2;
    sqlite3_close(db);
    cout << "Legal Client Deleted" << endl;
    return 0;
}

int LegalClient::UpdateClient()
{
    sqlite3 *db;
    if(SqliteManager::OpenDB(db)) return 1;
    string comm = "DELETE FROM ClientLegalPerson WHERE CNPJ = '" + id + "'";
    if(SqliteManager::Execute(db, comm)) return 2;
    sqlite3_close(db);
    cout << "Legal Client Deleted" << endl;
    return 0;
}

int LegalClient::CreateClient()
{
    sqlite3 *db;
    if(SqliteManager::OpenDB(db)) return 1;
    string comm = "DELETE FROM ClientLegalPerson WHERE CNPJ = '" + id + "'";
    if(SqliteManager::Execute(db, comm)) return 2;
    sqlite3_close(db);
    cout << "Legal Client Deleted" << endl;
    return 0;
}

void LegalClient::PrintClient(){
    std::cout << "Name: " << name << " CNPJ: " << id << std::endl;
}

bool LegalClient::HasBuilding(){
    return buildings.size() != 0;
}