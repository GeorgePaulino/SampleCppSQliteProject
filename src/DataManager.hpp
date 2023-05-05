#pragma once

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>

#include "ConstructionCompany.hpp"
#include "ClientBase.hpp"
#include "Building.hpp"
#include "PhysicalClient.hpp"
#include "LegalClient.hpp"

class DataManager
{
public:
    vector<ConstructionCompany> companies;
    vector<ClientBase*> allClients;
    vector<PhysicalClient> physicalClients;
    vector<LegalClient> legalClients;

    DataManager();

    /**
     * @brief Load all companies to companies vector
     * @return 
     * [0 - Success]
     * [1 - Cannot Open Database]
     * [2 - Cannot prepare statement]
     */
    int LoadCompanies();
    
    /**
     * @brief Load all companies to companies vector
     * @return 
     * [0 - Success]
     * [1 - Cannot Open Database]
     * [2 - Cannot prepare statement]
     */
    int LoadPhysicalClients();

    /**
     * @brief Load all companies to companies vector
     * @return 
     * [0 - Success]
     * [1 - Cannot Open Database]
     * [2 - Cannot prepare statement 1]
     * [3 - Cannot prepare statement 2]
     */
    int LoadLegalClients();

    void SetCompaniesRelations();
};