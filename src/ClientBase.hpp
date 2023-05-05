#pragma once
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

    ClientBase(/* args */);
    virtual ~ClientBase();
    virtual int DeleteClient() = 0;
    virtual void PrintClient() = 0;
};