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
        cout << "\t[03] Deletar Registro" << endl;
        cout << "\t[04] Gerar relatório" << endl;
        cout << "\t[05] Fechar" << endl;

        cout << "R: ";
        if (cin >> type)
        {
            cin.ignore();
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
                Delete();
                break;
            }
            case 5:
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
            cin.ignore();
            cout << endl;
            switch (type)
            {
            case 1:
            {
                cout << "ID (CPF / CNPJ): ";
                getline(cin, id);
                auto c = DataMg->GetClient(id);
                if(c) {
                    c->DeleteClient();
                    cout << "Cliente Deletado";
                }
                else {
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
                if(c) {
                    c->DeleteCompany();
                    cout << "Construtora Deletada";
                }
                else {
                    cout << "Construtora Não Registrada.";
                }
                cout << endl << endl;
                break;
            }
            case 3:
            {
                cout << "Client (ID / CPF): ";
                getline(cin, id);
                cout << endl;
                auto client = DataMg->GetClient(id);
                if(!client){
                    cout << "Cliente não registrado." << endl << endl;
                    break;
                }
                cout << "CNPJ: ";
                getline(cin, id);
                cout << endl;
                auto c = DataMg->GetCompany(id);
                if(!c) {
                    cout << "Construtora não registrada" << endl << endl;
                    break;
                }

                bool exist;
                for(auto &b : c->buildings){
                    if(b->client->id == client->id){
                        b->DeleteBuilding();
                        exist = true;
                    }
                }
                if(exist) cout << "Construção Removida dos Registros.";
                else {
                    cout << "Construção não registrada.";
                }
                cout << endl << endl;
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
            cin.ignore();
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
            cin.ignore();
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
                    if(client->type == 0) DataMg->physicalClients.push_back(*(PhysicalClient *)client);
                    else if(client->type == 1) DataMg->legalClients.push_back(*(LegalClient *)client);
                    DataMg->allClients.push_back(client);
                    cout << "Cliente Registrado" << endl;
                }
                cout << endl << endl;
                continue;
                break;
            }
            case 2:
            {
                ConstructionCompany *company = ReadCompany();
                if (company){
                    company->CreateCompany();
                    DataMg->companies.push_back(*company);
                    cout << "Construtora Registrada" << endl;

                }
                cout << endl << endl;
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
                        pc->UpdateClient();
                    }
                    else
                    {
                        LegalClient *lc = (LegalClient *)b->client;
                        lc->buildings.push_back(*b);
                        lc->UpdateClient();
                    }
                    b->company->buildings.push_back(b);
                    cout << "Construção Registrada" << endl;
                }
                cout << endl << endl;

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

ClientBase *MainManager::ReadClient()
{
    ClientBase *client;
    string id;
    string name;
    string phone;

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
        cin.ignore();
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
        cin.ignore();
        
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
        cin.ignore();
        client = new LegalClient(1, id, name, phone, zip, occupation, avaliation);
        break;
    }
    }
    cout << endl;

    return client;
}

ConstructionCompany *MainManager::ReadCompany()
{
    string name, cnpj, phone, zip;
    float avaliation;
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
    cin.ignore();

    cout << endl;

    return new ConstructionCompany(cnpj, name, zip, phone, avaliation);
}

Building *MainManager::ReadBuilding()
{
    string cnpj, id;
    ConstructionCompany *company;
    ClientBase *client;
    string name, startDate, endDate;
    float price;

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
    cin.ignore();

    cout << "Data de início: ";
    getline(cin, startDate);

    cout << "Data do fim: ";
    getline(cin, endDate);

    cout << endl;

    return new Building(company, client, price, name, startDate, endDate);
}