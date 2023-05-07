#include <string>
#include "DataManager.hpp"

DataManager::DataManager()
{
    LoadCompanies();
    LoadPhysicalClients();
    LoadLegalClients();
    SetCompaniesRelations();
}

int DataManager::LoadCompanies()
{
    sqlite3 *db;
    if(SqliteManager::OpenDB(&db)) return 1;

    sqlite3_stmt *companyDataRow;
    if(SqliteManager::ExecuteStmt(db, "SELECT * FROM ConstructionCompany", &companyDataRow)) return 2;

    while (sqlite3_step(companyDataRow) == SQLITE_ROW)
    {
        ConstructionCompany data;
        data.cnpj = std::string(reinterpret_cast<const char *>(sqlite3_column_text(companyDataRow, 0)));
        data.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(companyDataRow, 1)));
        data.phone = std::string(reinterpret_cast<const char *>(sqlite3_column_text(companyDataRow, 2)));
        data.avaliation = sqlite3_column_double(companyDataRow, 3);
        companies.push_back(data);
    }

    sqlite3_finalize(companyDataRow);
    sqlite3_close(db);

    std::cout << "| Loaded Companies" << std::endl;

    // Uncomment to show all loaded companies.
    for (const auto &data : companies)
    {
        std::cout << "CNPJ: " << data.cnpj << " | Name: " << data.name << std::endl;
    }
    return 0;
}

int DataManager::LoadPhysicalClients()
{
    sqlite3 *db;
    if(SqliteManager::OpenDB(&db)) return 1;

    string comm = "SELECT * FROM ClientPhysical";

    sqlite3_stmt *physicalClientsDataRow;
    if(SqliteManager::ExecuteStmt(db, comm.c_str(), &physicalClientsDataRow)) return 2;

    while (sqlite3_step(physicalClientsDataRow) == SQLITE_ROW)
    {
        PhysicalClient data;
        data.type = 0;
        data.id = std::string(reinterpret_cast<const char *>(sqlite3_column_text(physicalClientsDataRow, 0)));
        data.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(physicalClientsDataRow, 1)));
        data.phone = std::string(reinterpret_cast<const char *>(sqlite3_column_text(physicalClientsDataRow, 2)));
        data.income = sqlite3_column_double(physicalClientsDataRow, 3);

        data.building.company = nullptr;
        std::string companyCNPJ = std::string(reinterpret_cast<const char *>(sqlite3_column_text(physicalClientsDataRow, 4)));
        for (auto &c : companies)
        {
            if (companyCNPJ == c.cnpj)
            {
                data.building.company = &c;
            }
        }
        data.building.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(physicalClientsDataRow, 5)));
        data.building.price = sqlite3_column_double(physicalClientsDataRow, 6);
        data.building.startDate = std::string(reinterpret_cast<const char *>(sqlite3_column_text(physicalClientsDataRow, 7)));
        data.building.endDate = std::string(reinterpret_cast<const char *>(sqlite3_column_text(physicalClientsDataRow, 8)));
        physicalClients.push_back(data);
    }

    sqlite3_finalize(physicalClientsDataRow);
    sqlite3_close(db);

    std::cout << "| Loaded Physical Clients" << std::endl;

    // Uncomment to show all loaded physical clients.
    for (const auto &data : physicalClients)
    {
        std::cout << "CPF: " << data.id << " | Name: " << data.name << " | Has Building? " << (data.building.company != nullptr ? "Yes" : "No") << std::endl;
    }
    return 0;
}

int DataManager::LoadLegalClients()
{
    sqlite3 *db;
    if(SqliteManager::OpenDB(&db)) return 1;
    
    string comm = "SELECT * FROM ClientLegal";
    
    sqlite3_stmt *legalClientsDataRow;
    if(SqliteManager::ExecuteStmt(db, comm.c_str(), &legalClientsDataRow)) return 2;

    while (sqlite3_step(legalClientsDataRow) == SQLITE_ROW)
    {
        LegalClient data;
        data.type = 1;
        data.id = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientsDataRow, 0)));
        data.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientsDataRow, 1)));
        data.phone = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientsDataRow, 2)));
        data.zip = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientsDataRow, 3)));
        data.occupation = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientsDataRow, 4)));
        data.avaliation = sqlite3_column_double(legalClientsDataRow, 5);


        comm = "SELECT * FROM Building WHERE ClientCNPJ ='" + data.id + "'";

        sqlite3_stmt *legalClientBuildingsDataRow;
        if(SqliteManager::ExecuteStmt(db, comm.c_str(), &legalClientBuildingsDataRow)) return 2;

        while (sqlite3_step(legalClientBuildingsDataRow) == SQLITE_ROW)
        {
            Building building;
            string companyCNPJ = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientBuildingsDataRow, 0)));
            for (auto &c : companies)
            {
                if (companyCNPJ == c.cnpj)
                {
                    building.company = &c;
                }
            }
            building.name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientBuildingsDataRow, 2)));
            building.price = sqlite3_column_double(legalClientBuildingsDataRow, 3);
            building.startDate = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientBuildingsDataRow, 4)));
            building.endDate = std::string(reinterpret_cast<const char *>(sqlite3_column_text(legalClientBuildingsDataRow, 5)));
            data.buildings.push_back(building);
        }

        legalClients.push_back(data);
    }

    sqlite3_finalize(legalClientsDataRow);
    sqlite3_close(db);

    std::cout << "| Loaded Legal Clients" << std::endl;

    // Uncomment to show all loaded legal clients.

    for (const auto &data : legalClients)
    {
        std::cout << "CNPJ: " << data.id << " | Name: " << data.name << " | N Buildings: " << data.buildings.size() << std::endl;
    }
    return 0;
}

void DataManager::SetCompaniesRelations()
{
    for(auto &client : physicalClients){
        client.building.client = &client;
        allClients.push_back(&client);
    }
    for(auto &client : legalClients){
        for(auto &building: client.buildings) building.client = &client;
        allClients.push_back(&client);
    }

    for (auto &client : allClients)
    {
        if (client->type == 0)
        {
            PhysicalClient *pp = (PhysicalClient *)client;
            if(!pp->HasBuilding()) continue;
            for (auto &c : companies)
            {
                if (pp->building.company->cnpj == c.cnpj)
                {
                    c.buildings.push_back(&pp->building);
                }
            }
        }
        else if (client->type == 1)
        {
            LegalClient *lp = (LegalClient *)client;
            for(auto &b : lp->buildings){
                for(auto &c: companies){
                    if(b.company->cnpj == c.cnpj){
                        c.buildings.push_back(&b);
                        continue;
                    }
                }
            }
        }
    }

    std::cout << "| Loaded Builds" << std::endl;

    for(auto &company : companies){
        cout << "Company: " << company.name << " | Buildings: " << (company.HasBuilding() ? "" : "Whitout Buildings") << endl;
        for(auto &building: company.buildings){
            cout << "\t" << building->name << endl;
        }
    }
}