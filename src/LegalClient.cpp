#include "LegalClient.hpp"

LegalClient::LegalClient() {}
LegalClient::LegalClient(
    int type, string id, string name, string phone, string zip, string occupation, float avaliation) : ClientBase(type, id, name, phone), zip(zip), occupation(occupation), avaliation(avaliation) {}

LegalClient::~LegalClient() {}

int LegalClient::DeleteClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;
    
    string comm = "DELETE FROM Building WHERE ClientCNPJ = '" + id + "'";
    if (SqliteManager::Execute(db, comm.c_str()))
        return 3;

    comm = "DELETE FROM ClientLegal WHERE CNPJ = '" + id + "'";
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
       << "', PhoneNumber='" << phone << "', ZipCode='" << zip << "', OccupationArea='"
       << occupation << "', Avaliation='" << avaliation << "' WHERE CNPJ='" << id << "'";
    string comm = ss.str();
    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    comm = "DELETE FROM Building WHERE ClientCNPJ = '" + id + "'";
    if (SqliteManager::Execute(db, comm.c_str()))
        return 3;
    sqlite3_close(db);

    for (auto &building : buildings)
    {
        building.CreateBuilding();
    }

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

    for (auto &building : buildings)
    {
        building.CreateBuilding();
    }

    return 0;
}

void LegalClient::PrintClient()
{
    std::cout << "CNPJ: " << id << " | Nome: " << name << " | Telefone: " << phone << " | CEP: " << zip << " | Ocupação: " << occupation << " | Avaliação: " << avaliation << endl;
    if (HasBuilding())
    {
        for (auto &building : buildings)
        {
            std::cout << "\tConstrutora: " << building.company->cnpj << " | ";
            building.PrintBuilding();
        }
    }
    std::cout << endl;
}

bool LegalClient::HasBuilding()
{
    return buildings.size() != 0;
}