#include "ConstructionCompany.hpp"

ConstructionCompany::ConstructionCompany() {}

ConstructionCompany::ConstructionCompany(string cnpj, string name, string zip, string phone, float avaliation) : cnpj(cnpj), name(name), zip(zip), phone(phone), avaliation(avaliation) {}

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

    string comm = "DELETE FROM Building WHERE CompanyCNPJ = '" + cnpj + "'";
    if (SqliteManager::Execute(db, comm.c_str()))
        return 3;
    comm = "DELETE FROM ConstructionCompany WHERE CNPJ = '" + cnpj + "'";
    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;
    comm = "UPDATE ClientPhysical SET CompanyCNPJ='', BuildingPrice=0, BuildingName='', BuildingStartDate='', BuildingEndDate='' WHERE CompanyCNPJ = '" + cnpj + "'";
    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

    return 0;
}

int ConstructionCompany::UpdateCompany(string lastId)
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;

    stringstream ss;
    ss << "UPDATE ConstructionCompany SET CNPJ='" << cnpj << "', Name='" << name
       << "', Zip='" << zip << "', PhoneNumber='" << phone << "', Avaliation='" << avaliation << "' WHERE CNPJ='" << lastId << "'";
    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

    return 0;
}

int ConstructionCompany::CreateCompany()
{
    sqlite3 *db;
    if (SqliteManager::OpenDB(&db))
        return 1;

    stringstream ss;
    ss << "INSERT INTO ConstructionCompany (CNPJ, Name, Zip, PhoneNumber, Avaliation) VALUES ('"
       << cnpj << "', '" << name << "', '" << zip << "', '" << phone << "', " << avaliation << ")";
    string comm = ss.str();

    if (SqliteManager::Execute(db, comm.c_str()))
        return 2;

    sqlite3_close(db);

    return 0;
}

bool ConstructionCompany::HasBuilding()
{
    return buildings.size() != 0;
}

bool ConstructionCompany::Search(string info)
{
    if (name.find(info) != std::string::npos)
    {
        return this;
    }
    else if (cnpj.find(info) != std::string::npos)
    {
        return this;
    }
}

void ConstructionCompany::Print()
{
    std::cout << "CNPJ: " << cnpj << " | Nome: " << name << " | Telefone: " << phone << " | CEP: " << zip << " | Avaliação: " << avaliation << endl;
    if (HasBuilding())
    {
        for (auto &building : buildings)
        {
            if (building->client->type == 0)
                std::cout << "\tCPF: " << building->client->id << " | ";
            else if (building->client->type == 1)
                std::cout << "\tCNPJ: " << building->client->id << " | ";
            building->PrintBuilding();
        }
    }
}

string ConstructionCompany::GetAsCSV()
{
    std::ostringstream ss;
    ss << cnpj << ",";
    ss << name << ",";
    ss << zip << ",";
    ss << phone << ",";
    ss << avaliation << endl;
    return ss.str();
}