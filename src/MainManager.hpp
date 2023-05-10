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
    void Delete();
    void Search();
    void Insert();
    ClientBase *ReadClient();
    ConstructionCompany *ReadCompany();
    Building *ReadBuilding();
};