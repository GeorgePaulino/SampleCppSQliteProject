#include "LegalClient.hpp"
//    string id ; string name; string phone, string occupation; float avaliation;
LegalClient::LegalClient(string zip, string name, string phone, string occupation, float avaliation)
:
    zip(zip), name(name), phone(phone), occupation(occupation), avaliation(avaliation) {}

LegalClient::~LegalClie, nt(){}

int LegalClient::DeleteClient()
{
    sqlite3 *db;
    char* errMsg = 0;

    int rc = sqlite3_open("./database/Database.sqlite", &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    //erro em buildings->client->id
    string comm = "DELETE FROM ClientPhysicalPerson WHERE CNPJ = '";
    comm += buildings->client->id;

    rc = sqlite3_exec(db, comm.c_str(), NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error executing SQL statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 2;
    }

    // Close the database connection
    sqlite3_close(db);

    sqlite3 *db;
    int rc = sqlite3_open("./database/Database.sqlite", &db);
    if (rc)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }
    
    cout << "Pessoa Fisica deletada ";
    return 0;
}

void LegalClient::PrintClient(){
    std::cout << "Name: " << name << " CNPJ: " << id << std::endl;
}