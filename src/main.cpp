#include <iostream>
#include <string>
#include <sqlite3.h>
#include "ConstructionCompany.hpp"

using namespace std;


class P
{
public:
    int id;
    string nome;

     P(int id, string nome):id(id), nome(nome){}

    };

// Create a callback function
int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    P p( 12, " ");
    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value

    for (int i = 0; i < argc; i++)
    {
        if(azColName[i] == "Id" ){
            p.id = (int)argv[i];
        }
        if(azColName[i] == "Name"){
            p.nome = (string)argv[i];
        }
        // Show column name, value, and newline
        cout << azColName[i] << ": " << argv[i] << endl;
    }

    // Insert a newline
    cout << endl;

    // Return successful 
    return 0;
}

int main()
{

    // Pointer to SQLite connection
    sqlite3 *db;
    // Save any error messages
    char *zErrMsg = 0;
    // Save the result of opening the file
    int rc;

    // Save any SQL
    string sql;

    // Save the result of opening the file
    rc = sqlite3_open("./database/db.db", &db);

    if (rc)
    {
        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return (1);
    }

    // Save SQL insert data
    // sql = "INSERT INTO PEOPLE ('ID', 'NAME') VALUES ('1','Cara');";
    // Run the SQL (convert the string to a C-String with c_str() )
    // rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Save SQL insert data
    sql = "SELECT * FROM 'Character';";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Close the SQL connection
    sqlite3_close(db);

    return 0;
}