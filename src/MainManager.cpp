#include "MainManager.hpp"

MainManager::MainManager() {}

void MainManager::MainPage()
{
    int type;

    while (true)
    {
        cout << "[Gerenciador de Construtora]" << endl;
        cout << "\t[01] Buscar Registro" << endl;
        cout << "\t[02] Novo Registro" << endl;
        cout << "\t[03] Atualizar Registro" << endl;
        cout << "\t[04] Deletar Registro" << endl;
        cout << "\t[05] Gerar relatório" << endl;
        cout << "\t[06] Fechar" << endl;

        cout << "R: ";
        if (cin >> type)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');;
            cout << endl;
            switch (type)
            {
            case 1:
            {
                Search();
                break;
            }
            case 2:
            {
                Insert();
                break;
            }
            case 3:
            {
                Update();
                break;
            }
            case 4:
            {
                Delete();
                break;
            }
            case 6:
            {
                cout << "!!! Fechando Programa !!!" << endl;
                return;
                break;
            }
            default:
            {
                cout << "!!! Escolha Invalida !!!" << endl
                     << endl;
                continue;
                break;
            }
            }
        }
        else
        {
            cout << "!!! Escolha Invalida !!!" << endl
                 << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void MainManager::Update()
{
    int type;
    string id;

    while (true)
    {
        cout << "- Qual tipo de registro atualizar: " << endl;
        cout << "\t[01] Cliente" << endl;
        cout << "\t[02] Construtora" << endl;
        cout << "\t[03] Construção" << endl;
        cout << "\t[04] Retornar" << endl;
        cout << "R: ";
        if (cin >> type)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');;
            cout << endl;
            switch (type)
            {
            case 1:
            {
                cout << "Cliente ID (CPF / CNPJ): ";
                getline(cin, id);
                auto c = DataMg->GetClient(id);
                if (c)
                {
                    auto newC = ReadClient(c);
                    if(c->type == 1){
                        ((LegalClient *) newC)->buildings = ((LegalClient *)c)->buildings;
                    }
                    newC->UpdateClient(c->id);
                    cout << "Cliente Atualizado";
                }
                else
                {
                    cout << "Cliente Não Registrado.";
                }
                cout << endl
                     << endl;
                break;
            }
            case 2:
            {
                cout << "CNPJ: ";
                getline(cin, id);
                cout << endl;
                auto c = DataMg->GetCompany(id);
                if (c)
                {
                    auto newC = ReadCompany(c);
                    newC->UpdateCompany(c->cnpj);
                    cout << "Construtora Atualizada";
                }
                else
                {
                    cout << "Construtora Não Registrada.";
                }
                cout << endl
                     << endl;
                break;
            }
            case 3:
            {
                cout << "Client ID (CPF / CNPJ): ";
                getline(cin, id);
                cout << endl;
                auto client = DataMg->GetClient(id);
                if (!client)
                {
                    cout << "Cliente não registrado." << endl
                         << endl;
                    break;
                }

                cout << "CNPJ: ";
                getline(cin, id);
                cout << endl;
                auto company = DataMg->GetCompany(id);
                if (!company)
                {
                    cout << "Construtora não registrada" << endl
                         << endl;
                    break;
                }

                bool exist;
                for (auto &b : company->buildings)
                {
                    if (b->client->id == client->id)
                    {
                        auto newB = ReadBuilding(b);
                        newB->client = client;
                        newB->company = company;
                        newB->UpdateBuilding();
                        exist = true;
                    }
                }
                if (exist)
                    cout << "Construção Atualizada.";
                else
                {
                    cout << "Construção não registrada.";
                }
                cout << endl
                     << endl;
                break;
            }
            case 4:
            {
                cout << endl;
                cout << "Retornando..." << endl;
                return;
                break;
            }
            default:
            {
                cout << "!!! Escolha Invalida !!!" << endl
                     << endl;
                break;
            }
            }
        }
        else
        {
            cout << "!!! Escolha Invalida !!!" << endl
                 << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        DataMg->Reload();
    }
}

void MainManager::Delete()
{
    int type;
    string id;

    while (true)
    {
        cout << "- Qual tipo de registro deletar: " << endl;
        cout << "\t[01] Cliente" << endl;
        cout << "\t[02] Construtora" << endl;
        cout << "\t[03] Construção" << endl;
        cout << "\t[04] Retornar" << endl;
        cout << "R: ";
        if (cin >> type)
        {
            cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;
            cout << endl;
            switch (type)
            {
            case 1:
            {
                cout << "Cliente ID (CPF / CNPJ): ";
                getline(cin, id);
                auto c = DataMg->GetClient(id);
                if (c)
                {
                    c->DeleteClient();
                    cout << "Cliente Deletado";
                }
                else
                {
                    cout << "Cliente Não Registrado.";
                }
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "CNPJ: ";
                getline(cin, id);
                cout << endl;
                auto c = DataMg->GetCompany(id);
                if (c)
                {
                    c->DeleteCompany();
                    cout << "Construtora Deletada";
                }
                else
                {
                    cout << "Construtora Não Registrada.";
                }
                cout << endl
                     << endl;
                break;
            }
            case 3:
            {
                cout << "Client ID (CPF / CNPJ): ";
                getline(cin, id);
                cout << endl;
                auto client = DataMg->GetClient(id);
                if (!client)
                {
                    cout << "Cliente não registrado." << endl
                         << endl;
                    break;
                } else if(client->type == 0){
                    if(client->HasBuilding()){
                        ((PhysicalClient *)client)->building.DeleteBuilding();
                        cout << "Construção Removida dos Registros." << endl << endl;
                        break;
                    }
                    else{
                        cout << "Construção não registrada." << endl << endl;
                        break;
                    }
                }
                cout << "CNPJ: ";
                getline(cin, id);
                cout << endl;
                auto c = DataMg->GetCompany(id);
                if (!c)
                {
                    cout << "Construtora não registrada" << endl
                         << endl;
                    break;
                }

                bool exist;
                for (auto &b : c->buildings)
                {
                    if (b->client->id == client->id)
                    {
                        b->DeleteBuilding();
                        exist = true;
                    }
                }
                if (exist)
                    cout << "Construção Removida dos Registros.";
                else
                {
                    cout << "Construção não registrada.";
                }
                cout << endl
                     << endl;
                break;
            }
            case 4:
            {
                cout << endl;
                cout << "Retornando..." << endl;
                return;
                break;
            }
            default:
            {
                cout << "!!! Escolha Invalida !!!" << endl
                     << endl;
                break;
            }
            }
        }
        else
        {
            cout << "!!! Escolha Invalida !!!" << endl
                 << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        DataMg->Reload();
    }
}

void MainManager::Search()
{
    int type;
    string info;
    while (true)
    {
        cout << "- Qual tipo de busca?" << endl;
        cout << "\t[01] Cliente Físico" << endl;
        cout << "\t[02] Cliente Juridíco" << endl;
        cout << "\t[03] Construtora" << endl;
        cout << "\t[04] Retornar" << endl;
        cout << "R: ";
        if (cin >> type)
        {
            cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;
            cout << endl;

            switch (type)
            {
            case 1:
            {
                cout << "CPF / Nome do Cliente (Empty to get all): ";
                getline(cin, info);
                cout << endl;
                for (auto &client : DataMg->physicalClients)
                {
                    if (client.Search(info))
                    {
                        client.PrintClient();
                    }
                }
                break;
            }
            case 2:
            {
                cout << "CNPJ / Nome do Cliente (Empty to get all): ";
                getline(cin, info);
                cout << endl;
                for (auto &client : DataMg->legalClients)
                {
                    if (client.Search(info))
                    {
                        client.PrintClient();
                    }
                }
                break;
            }
            case 3:
            {
                cout << "CNPJ / Nome da construtora (Empty to get all): ";
                getline(cin, info);
                cout << endl;
                for (auto &client : DataMg->companies)
                {
                    if (client.Search(info))
                    {
                        client.Print();
                    }
                }
                cout << endl;
                break;
            }
            case 4:
            {
                cout << "Retornando..." << endl;
                cout << endl
                     << endl;
                return;
                break;
            }
            default:
            {
                cout << "!!! Escolha Invalida !!!" << endl
                     << endl;
                continue;
                break;
            }
            }
        }
        else
        {
            cout << "!!! Escolha Invalida !!!" << endl
                 << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void MainManager::Insert()
{
    int type;
    string info;
    while (true)
    {
        cout << "- O que você deseja inserir?" << endl;
        cout << "\t[01] Cliente" << endl;
        cout << "\t[02] Construtora" << endl;
        cout << "\t[03] Construção" << endl;
        cout << "\t[04] Retornar" << endl;
        cout << "R: ";
        if (cin >> type)
        {
            cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;
            cout << endl
                 << endl;
            switch (type)
            {
            case 1:
            {
                ClientBase *client = ReadClient();
                if (client)
                {
                    client->CreateClient();
                    if (client->type == 0)
                        DataMg->physicalClients.push_back(*(PhysicalClient *)client);
                    else if (client->type == 1)
                        DataMg->legalClients.push_back(*(LegalClient *)client);
                    DataMg->allClients.push_back(client);
                    cout << "Cliente Registrado" << endl;
                }
                cout << endl
                     << endl;
                continue;
                break;
            }
            case 2:
            {
                ConstructionCompany *company = ReadCompany();
                if (company)
                {
                    company->CreateCompany();
                    DataMg->companies.push_back(*company);
                    cout << "Construtora Registrada" << endl;
                }
                cout << endl
                     << endl;
                continue;
                break;
            }
            case 3:
            {
                Building *b = ReadBuilding();
                if (b)
                {
                    if (b->client->type == 0)
                    {
                        PhysicalClient *pc = (PhysicalClient *)b->client;
                        pc->building = *b;
                        pc->UpdateClient(pc->id);
                    }
                    else
                    {
                        LegalClient *lc = (LegalClient *)b->client;
                        lc->buildings.push_back(*b);
                        lc->UpdateClient(lc->id);
                    }
                    b->company->buildings.push_back(b);
                    cout << "Construção Registrada" << endl;
                }
                cout << endl
                     << endl;

                continue;
                break;
            }
            case 4:
            {
                cout << "Retornando..." << endl;
                break;
            }
            default:
            {
                cout << "!!! Escolha Invalida !!!" << endl
                     << endl;
                continue;
                break;
            }
            }
            cout << endl
                 << endl;
            return;
        }
        else
        {
            cout << "!!! Escolha Invalida !!!" << endl
                 << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

ClientBase *MainManager::ReadClient(ClientBase *client)
{
    bool update = client;
    string id;
    string name;
    string phone;

    if (update)
    {
        cout << "[ Atualizando Cliente ]" << endl;
        cout << "Obs: Deixe o valor em branco pra não altera-lo." << endl
             << endl;
        cout << (client->type == 0 ? "CPF" : "CNPJ") << " do cliente (" << client->id << "): ";
        getline(cin, id);
        if (id == "")
            id = client->id;
        cout << "Nome do cliente (" << client->name << "): ";
        getline(cin, name);
        if (name == "")
            name = client->name;
        cout << "Telefone para contato (" << client->phone << "): ";
        getline(cin, phone);
        if (phone == "")
            phone = client->phone;
        if (client->type == 0)
        {
            PhysicalClient *c = (PhysicalClient *)client;
            float income = c->income;
            cout << "Renda do cliente (" << c->income << "): ";
            cin >> income;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');;
            cout << endl;
            return new PhysicalClient(0, id, name, phone, income);
        }
        else
        {
            LegalClient *c = (LegalClient *)client;
            string zip;
            string occupation;
            float avaliation = c->avaliation;

            cout << "CEP da Empresa (" << c->zip << "): ";
            getline(cin, zip);
            if (zip == "")
                zip = c->zip;

            cout << "Área de Atuação (" << c->occupation << "): ";
            getline(cin, occupation);
            if (occupation == "")
                occupation = c->occupation;

            cout << "Média de Avaliações (" << c->avaliation << "): ";
            cin >> avaliation;
            cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;
            cout << endl;
            return new LegalClient(1, id, name, phone, zip, occupation, avaliation);
        }
    }

    cout << "[ Novo Cliente ]" << endl;
    cout << "- Tipo de Cliente" << endl;
    cout << "\t[01] Pessoa fisica" << endl;
    cout << "\t[02] Pessoa juridica" << endl;
    cout << "\t[03] Voltar" << endl;

    int type;

    while (true)
    {
        cout << "R: ";
        cin >> type;
        cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;
        if (type == 3)
            return nullptr;
        else if (type != 1 && type != 2)
        {
            cout << "Tipo invalido de cliente. Escolha uma opção válida (1 - 3): ";
        }
        else
        {
            break;
        }
    }
    cout << endl;

    cout << (type == 1 ? "CPF" : "CNPJ") << " do cliente: ";
    getline(cin, id);

    if (DataMg->GetClient(id))
    {
        cout << "O cliente já está registrado." << endl;
        return nullptr;
    }

    cout << "Nome do cliente: ";
    getline(cin, name);
    cout << "Telefone para contato: ";
    getline(cin, phone);

    switch (type)
    {
    case (1):
    {
        float income;
        cout << "Renda do cliente: ";
        cin >> income;
        cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;

        client = new PhysicalClient(0, id, name, phone, income);
        break;
    }

    case (2):
    {
        string zip;
        string occupation;
        float avaliation;
        cout << "CEP da Empresa: ";
        getline(cin, zip);
        cout << "Área de Atuação: ";
        getline(cin, occupation);
        cout << "Média de Avaliações: ";
        cin >> avaliation;
        cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;
        client = new LegalClient(1, id, name, phone, zip, occupation, avaliation);
        break;
    }
    }
    cout << endl;

    return client;
}

ConstructionCompany *MainManager::ReadCompany(ConstructionCompany *company)
{
    bool update = company;
    string name, cnpj, phone, zip;
    float avaliation;

    if (update)
    {
        avaliation = company->avaliation;
        cout << "[ Atualizando Construtora ]" << endl;
        cout << "Obs: Deixe o valor em branco pra não altera-lo." << endl
             << endl;
        cout << "CNPJ da construtora: (" << company->cnpj << "): ";
        getline(cin, cnpj);
        if (cnpj == "")
            cnpj = company->cnpj;
        cout << "Nome da construtora: (" << company->name << "): ";
        getline(cin, name);
        if (name == "")
            name = company->name;
        cout << "Telefone de contato: (" << company->phone << "): ";
        getline(cin, phone);
        if (phone == "")
            phone = company->phone;
        cout << "CEP da Construtora: (" << company->zip << "): ";
        getline(cin, zip);
        if (zip == "")
            zip = company->zip;
        cout << "Média de avaliações: (" << company->avaliation << "): ";
        cin >> avaliation;
        cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;
    }
    else
    {
        cout << "[ Nova Construtora ]" << endl;
        cout << "CNPJ da construtora: ";
        getline(cin, cnpj);

        if (DataMg->GetCompany(cnpj))
        {
            cout << "A construtora já esta registrada." << endl;
            return nullptr;
        }

        cout << "Nome da construtora: ";
        getline(cin, name);
        cout << "Telefone de contato: ";
        getline(cin, phone);
        cout << "CEP da Construtora: ";
        getline(cin, zip);
        cout << "Média de avaliações: ";
        cin >> avaliation;
        cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;
    }

    cout << endl;
    return new ConstructionCompany(cnpj, name, zip, phone, avaliation);
}

Building *MainManager::ReadBuilding(Building *building)
{
    bool update = building;
    string cnpj, id;
    ConstructionCompany *company;
    ClientBase *client;
    string name, startDate, endDate;
    float price;

    if (update)
    {
        price = building->price;
        cout << "[ Atualizando Construção ]" << endl;
        cout << "Obs: Deixe o valor em branco pra não altera-lo." << endl
             << endl;

        cout << "Nome da obra: (" << building->name << "): ";
        getline(cin, name);
        if (name == "")
            name = building->name;
        
        cout << "Preço da obra: (" << building->price << "): ";
        cin >> price;
        cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;

        cout << "Data de início: (" << building->startDate << "): ";
        getline(cin, startDate);
        if(startDate == "")
            startDate = building->startDate;

        cout << "Data do fim: (" << building->endDate << "): ";
        getline(cin, endDate);
        if(endDate == "")
            endDate = building->endDate;
    }
    else
    {
        cout << "[ Nova Construção ]" << endl
             << endl;
        cout << "Client ID (CPF / CPNJ) do cliente: ";
        getline(cin, id);
        client = DataMg->GetClient(id);
        if (!client)
        {
            cout << endl;
            cout << "Este cliente não está registrado no sistema." << endl
                 << "Faça o seu registro antes de continuar." << endl;
            return nullptr;
        }

        cout << "CNPJ da construtora: ";
        getline(cin, cnpj);
        company = DataMg->GetCompany(cnpj);
        if (!company)
        {
            cout << endl;
            cout << "Esta construtora não está registrada no sistema." << endl
                 << "Faça o seu registro antes de continuar." << endl;
            return nullptr;
        }

        cout << "Nome da obra: ";
        getline(cin, name);

        cout << "Preço da obra: ";
        cin >> price;
        cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');;

        cout << "Data de início: ";
        getline(cin, startDate);

        cout << "Data do fim: ";
        getline(cin, endDate);
    }

    cout << endl;

    return new Building(company, client, price, name, startDate, endDate);
}