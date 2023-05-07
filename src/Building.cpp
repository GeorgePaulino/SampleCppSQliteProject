#include "Building.hpp"

Building::Building()
{
}

Building::~Building()
{
}

int Building::DeleteBuilding()
{
    sqlite3 *db;

    if (SqliteManager::OpenDB(&db))
        return 1;

    string comm;

    if (client->type == 0)
    {
        comm = "UPDATE ClientPhysical SET CompanyCNPJ='', BuildingName='', BuildingPrice=0, BuildingStartDate='', BuildingEndDate='' WHERE CPF='" + client->id + "'";
    }
    else if (client->type == 1)
    {
        comm = "DELETE FROM Building WHERE CompanyCNPJ = '" + company->cnpj +
               "' AND ClientCNPJ = '" + client->id + "'";
    }

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;
    sqlite3_close(db);

    cout << "Building Deleted" << endl;
    return 0;
}

int Building::UpdateBuilding()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;

    stringstream ss;
    if (client->type == 0)
    {
        ss << "UPDATE ClientPhysical SET "
           << "CompanyCNPJ='" << company->cnpj << "', BuildingName='"
           << name << "', BuildingPrice='" << price
           << "', BuildingStartDate='" << startDate << "', BuildingEndDate='"
           << endDate << "' WHERE CPF='" << client->id << "'";
    }
    else if (client->type == 1)
    {
        ss << "UPDATE Building SET CompanyCNPJ='" << company->cnpj << "', Name='" << name << "', Price='" << price
           << "', StartDate='" << startDate << "', EndDate='" << endDate
           << "' WHERE ClientCNPJ='" << client->id << "'";
    }

    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

    cout << "Building Updated" << endl;
    return 0;
}

int Building::CreateBuilding()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;

    stringstream ss;
    ss << "INSERT INTO Building (CompanyCNPJ, ClientCNPJ, Name, Price, StartDate, EndDate) VALUES ('"
       << company->cnpj << "', '" << client->id << "', '" << name << "', " << price << ", '"
       << startDate << "', '" << endDate << "')";
    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

    cout << "Building Created" << endl;
    return 0;
}