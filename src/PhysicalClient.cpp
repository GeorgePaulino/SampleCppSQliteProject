#include "PhysicalClient.hpp"

PhysicalClient::
PhysicalClient(string zip, string name, string phone, string income, string startDate, string endDate)
:
    zip(zip), name(name), phone(phone), income(income), StartDate(StartDate), EndDate(EndDate){}

PhysicalClient::~PhysicalClient(){}

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

int PhysicalClient::UpdateClient()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;
    stringstream ss;
    
    ss << "UPDATE ClientPhysical SET CPF='" << id << "', Name='" << name
       << "', PhoneNumber='" << phone << "', Income='" << income << "'"
       << " WHERE CPF='" << id << "'";
    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

    if(HasBuilding()) building.UpdateBuilding();

    cout << "Physical Client Updated" << endl;
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

    if (HasBuilding()) building.UpdateBuilding();

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