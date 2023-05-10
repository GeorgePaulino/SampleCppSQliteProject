#include "Building.hpp"

Building::Building()
{
}

Building::Building(ConstructionCompany *company, ClientBase *client, float price, string name, string startDate, string endDate)
    : company(company), client(client), price(price), name(name), startDate(startDate), endDate(endDate)
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

    // cout << "Building Deleted" << endl;
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
        cout << company->cnpj;
        cout << client->id;
        ss << "UPDATE Building SET CompanyCNPJ='" << company->cnpj << "', Name='" << name << "', Price='" << price
           << "', StartDate='" << startDate << "', EndDate='" << endDate
           << "' WHERE ClientCNPJ='" << client->id << "' AND CompanyCNPJ='" << company->cnpj << "'";
    }

    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

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
    return 0;
}

void Building::PrintBuilding()
{
    cout << "Name: " << name << " | R$: " << price << " | Start " << startDate << " - End " << endDate << endl;
}

string Building::GetAsCSV()
{
    std::stringstream ss;
    ss << name << "," << price << "," << startDate << "," << endDate << ",";
    ss << company->cnpj << "," << client->id << endl;
    return ss.str();
}