#include<string>
#include"ClientBase.hpp"
#include"Building.hpp"

using namespace std;

class LegalClient : public ClientBase
{
public:
    string zip;
    string occupation;
    float avaliation;

    vector<Building*> buildings;

    LegalClient(/* args */);
    ~LegalClient();

    int DeleteClient() override;
    void PrintClient() override;
};