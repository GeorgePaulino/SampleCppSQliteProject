#pragma once

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>

#include "ConstructionCompany.hpp"
#include "ClientBase.hpp"
#include "Building.hpp"
#include "PhysicalPerson.hpp"
#include "LegalPerson.hpp"

class Manager
{
public:
    vector<ConstructionCompany> companies;
    vector<ClientBase*> allClients;
    vector<PhysicalPerson> physicalClients;
    vector<LegalPerson> legalClients;

    Manager();

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