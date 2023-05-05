#include<string>
#include"ClientBase.hpp"
#include"Building.hpp"

using namespace std;

class LegalPerson : public ClientBase
{
public:
    string zip;
    string occupation;
    float avaliation;

    vector<Building> buildings;

    LegalPerson(/* args */);
    ~LegalPerson();

    void deletePerson(LegalPerson *p);
};