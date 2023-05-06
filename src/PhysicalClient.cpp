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
    char* errMsg = 0;

    int rc = sqlite3_open("./database/Database.sqlite", &db);
    if (rc)
    {
    std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return 1;
    }

    string comm = "DELETE FROM PhysicalClient WHERE CNPJ = '";
    comm += building->client->id;

    rc = sqlite3_exec(db, comm.c_str(), NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error executing SQL statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 2;
    }
    cout << "Cliente Fisico deletado";
    return 0;
}

void PhysicalClient::PrintClient(){
    std::cout << "Name: " << name << " CPF: " << id << std::endl;
}