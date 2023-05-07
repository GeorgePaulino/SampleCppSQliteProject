#pragma once

#include<iostream>
#include<sqlite3.h>
#include<string>

using namespace std;

class SqliteManager
{
public:
    static int OpenDB(sqlite3 *db);
    static int Execute(sqlite3 *db, string comm);
    static int ExecuteStmt(sqlite3 *db, const char *comm, sqlite3_stmt **stmt);
};
