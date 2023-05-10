#pragma once
#include <sstream>
#include<string>
#include<vector>

using namespace std;

class ClientBase
{
public:
    /// @brief 0 - Physical | 1 - Legal
    int type;
    string id;
    string name;
    string phone;

    ClientBase();
    ClientBase(int type, string id, string name, string phone);

    bool Search(string info);
    virtual int DeleteClient() = 0;
    virtual int UpdateClient(string lastId) = 0;
    virtual int CreateClient() = 0;
    virtual void PrintClient() = 0;
    virtual bool HasBuilding() = 0;
};