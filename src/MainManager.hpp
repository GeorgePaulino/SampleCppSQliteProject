#include <limits>

#include "DataManager.hpp"
#include "ConstructionCompany.hpp"
#include "ClientBase.hpp"
#include "LegalClient.hpp"
#include "PhysicalClient.hpp"
#include "Building.hpp"

using namespace std;

class MainManager {
public:
    DataManager *DataMg;

    MainManager();

    void MainPage();
    void Update();
    void Delete();
    void Search();
    void Insert();
    ClientBase *ReadClient(ClientBase *client = nullptr);
    ConstructionCompany *ReadCompany(ConstructionCompany *company = nullptr);
    Building *ReadBuilding(Building *building = nullptr);
};