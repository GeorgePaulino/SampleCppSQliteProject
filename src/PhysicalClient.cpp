#include "PhysicalClient.hpp"

PhysicalClient::PhysicalClient()
{
    building.client = this;
    building.company = nullptr;
}
PhysicalClient::PhysicalClient(int type, string id, string name, string phone, float income)
    : ClientBase(type, id, name, phone), income(income)
{
    building.client = this;
    building.company = nullptr;
}

PhysicalClient::~PhysicalClient() {}

int PhysicalClient::DeleteClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;
    string comm = "DELETE FROM ClientPhysical WHERE CPF = '" + id + "'";
    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;
    sqlite3_close(db);
    cout << "Physical Client Deleted" << endl;
    return 0;
}

int PhysicalClient::UpdateClient(string lastId)
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;
    stringstream ss;

    ss << "UPDATE ClientPhysical SET "
       << "CPF='" << id << "', "
       << "Name='" << name << "', "
       << "PhoneNumber='" << phone << "', "
       << "Income='" << income << "', "
       << "CompanyCNPJ='', "
       << "BuildingName='', "
       << "BuildingStartDate='', "
       << "BuildingEndDate='' "
       << "WHERE CPF='" << id << "'";

    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

    if (HasBuilding())
        building.UpdateBuilding();

    return 0;
}

int PhysicalClient::CreateClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;

    stringstream ss;

    ss << "INSERT INTO ClientPhysical (CPF, Name, PhoneNumber, Income) VALUES ('"
       << id << "', '" << name << "', '" << phone << "', '" << income << "')";

    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

    if (HasBuilding())
        building.UpdateBuilding();

    // cout << "Physical Client Created" << endl;

    return 0;
}

void PhysicalClient::PrintClient()
{
    std::cout << "CPF: " << id << " | Nome: " << name << " | Telefone: " << phone << " | Income: " << income << endl;
    if (HasBuilding())
    {
        std::cout << "\tConstrutora: " << building.company->cnpj << " | ";
        building.PrintBuilding();
    }
    std::cout << endl;
}

bool PhysicalClient::HasBuilding()
{
    return building.company != nullptr;
}