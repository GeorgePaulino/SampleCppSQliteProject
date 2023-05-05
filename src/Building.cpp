#include"Building.hpp"

Building::Building()
{
}

Building::~Building()
{
}

int Building::DeleteBuilding(){
    if(client->type == 0){
        return 0;
    }
    
    sqlite3 *db;
    char* errMsg = 0;

    int rc = sqlite3_open("./database/Database.sqlite", &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    string comm = "DELETE FROM Building WHERE CompanyCNPJ = '";
    comm += company->cnpj + "' AND ClientCNPJ = '" + client->id + "'";

    rc = sqlite3_exec(db, comm.c_str(), NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error executing SQL statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 2;
    }

    // Close the database connection
    sqlite3_close(db);

}
