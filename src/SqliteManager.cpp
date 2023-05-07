#include "SqliteManager.hpp"
int SqliteManager::OpenDB(sqlite3 *db)
{
    int rc = sqlite3_open("./database/Database.sqlite", &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }
    return 0;
}

int SqliteManager::Execute(sqlite3 *db, string comm)
{
    char *errMsg = 0;
    int rc = sqlite3_exec(db, comm.c_str(), NULL, NULL, &errMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error executing SQL statement: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }
    return 0;
}

int SqliteManager::ExecuteStmt(sqlite3 *db, const char *comm, sqlite3_stmt **stmt)
{
    cout << comm << endl;
    int rc = sqlite3_prepare_v2(db, comm, -1, stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    return 0;
}