#include"Building.hpp"

Building::Building()
{
}

Building::~Building()
{
}

int Building::DeleteBuilding(){
    sqlite3 *db;

    if(SqliteManager::OpenDB(db)) return 1;

    string comm;

    if(client->type == 0){
        comm = "UPDATE ClientPhysical SET CompanyCNPJ='', BuildingName='', BuildingPrice=0, BuildingStartDate='', BuildingEndDate='' WHERE CPF='" + client->id + "'";
    } else if (client->type == 1) {
        comm = "DELETE FROM Building WHERE CompanyCNPJ = '" + company->cnpj + 
            "' AND ClientCNPJ = '" + client->id + "'";
    }

    if(SqliteManager::Execute(db, comm)) return 2;
    sqlite3_close(db);

    cout << "Building Deleted" << endl;

}
