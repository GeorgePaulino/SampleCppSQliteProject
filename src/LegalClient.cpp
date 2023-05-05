#include "LegalClient.hpp"

LegalClient::LegalClient(){}
LegalClient::~LegalClient(){}

int LegalClient::DeleteClient()
{
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