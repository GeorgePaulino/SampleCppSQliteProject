#include "PhysicalClient.hpp"

PhysicalClient::PhysicalClient()
{
}
PhysicalClient::~PhysicalClient()
{
}

int PhysicalClient::DeleteClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(db))
        return 1;
    string comm = "DELETE FROM ClientPhysicalPerson WHERE CPF = '" + id + "'";
    if (SqliteManager::Execute(db, comm))
        return 2;
    sqlite3_close(db);
    cout << "Physical Client Deleted" << endl;
    return 0;
}

int PhysicalClient::UpdateClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(db))
        return 1;
    stringstream ss;
    ss << "UPDATE ClientPhysicalPerson SET CPF='" << id << "', Name='" << name
       << "', PhoneNumber='" << phone << "', Income='" << income << "'";
    if (HasBuilding())
    {
        ss << ", CompanyCNPJ='" << building.company->cnpj << "', BuildingName='"
           << building.name << "', BuildingPrice='" << building.price
           << "', BuildingStartDate='" << building.startDate << "', BuildingEndDate='"
           << building.endDate << "'";
    }
    else
    {
        ss << ", CompanyCNPJ='', BuildingName='', BuildingPrice=0, BuildingStartDate='', BuildingEndDate=''";
    }
    ss << " WHERE CPF='" << id << "'";
    string comm = ss.str();
    if (SqliteManager::Execute(db, comm))
        return 2;
    sqlite3_close(db);
    cout << "Physical Client Updated" << endl;
    return 0;
}

int PhysicalClient::CreateClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(db))
        return 1;

    stringstream ss;
    ss << "INSERT INTO ClientPhysical (CPF, Name, PhoneNumber, Income, CompanyCNPJ, BuildingName, BuildingPrice, BuildingStartDate, BuildingEndDate) VALUES ('"
       << id << "', '" << name << "', '" << phone << "', '" << income;

    if (HasBuilding())
    {
        ss << "', '" << building.company->cnpj << "', '" << building.name << "', '" << building.price << "', '"
           << building.startDate << "', '" << building.endDate << "')";
    }
    else
    {
        ss << "', '', '', 0, '', '')";
    }
    
    string comm = ss.str();

    if (SqliteManager::Execute(db, comm))
        return 2;
    
    sqlite3_close(db);
    
    cout << "Physical Client Created" << endl;
    
    return 0;
}

void PhysicalClient::PrintClient()
{
    std::cout << "Name: " << name << " CPF: " << id << std::endl;
}

bool PhysicalClient::HasBuilding()
{
    return building.company != nullptr;
}