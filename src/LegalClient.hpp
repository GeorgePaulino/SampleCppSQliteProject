#pragma once
#include<string>

#include"SqliteManager.hpp"
#include"ClientBase.hpp"
#include"Building.hpp"

using namespace std;

class LegalClient : public ClientBase
{
public:
    string zip;
    string occupation;
    float avaliation;

    vector<Building> buildings;

    LegalClient();
    LegalClient(int type, string id, string name, string phone, string zip, string occupation, float avaliation);
    ~LegalClient();

    int DeleteClient() override;
    int UpdateClient() override;
    int CreateClient() override;
    void PrintClient() override;
    bool HasBuilding() override;
};