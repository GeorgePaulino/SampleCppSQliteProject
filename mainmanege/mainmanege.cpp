#include <iostream>
#include <string>
#include "ConstructionCompany.hpp"
#include "ClientBase.hpp"
#include"ClientBase.hpp"


using namespace std;

ClientBase Readclient(){
    string name;
    string phone;
    string id;
    string ocupation;
    string avaliation;
    string 	startDate, endDate, income;

    cout << " Qual tipo de Cliete sera acrescentado ?";
    cout << "Pessoa fisica     01";
    cout << "Pessoa juridica  02"; 
    cout << "voltar           03";

    int tipo;
    cin >> tipo;
    cin.ignore();

    if( tipo == 3)
        return 0;
    
    switch (tipo){
    case (1):
        cout << "CPF do cliente: "
        getline(cin, id);
        cout << "Nome do cliente: "
        getline(cin, name);
        cout << "Telefone para contato: "
        getline(cin, phone);
        cout << "Preço aprozimado para construção: ";
        getline(cin, income);
        cout << "Data de inicio: "
        getline(cin, startDate);
        cout << "Data de termino: "
        getline(cin, endDate)

       PhysicalClient* client(id, name, phone, income, startDate, endDate);
        break;
    
    
    case (2):
        cout << "CNPJ do cliente: "
        getline(cin, id);
        cout << "Nome do cliente: "
        getline(cin, name);
        cout << "Telefone para contato: "
        getline(cin, phone);
        cout << "Tipo de construção: ";
        getline(cin, ocupation);
        cout << "Avaliação do cliente: "
        getline(cin, avaliation);
         LegalClient* client(id, name, phone, ocupation, avaliation);
        break;
    
    default:
        cout <<"opção invalida \n Por favor digitar outro numero:";
        break;
        }

    return client;
}

ConstructionCompany ReadCompany(){
    string nome, cnpj, phone, avaliation;

    cout << "CNPJ da construtora: ";
    getline(cin, cnpj)
    cout << "Nome da construtora: ";
    getline(cin, nome);
    cout << "Telefone de contato: ";
    getline(cin, phone);
    cout << "Avaliação do cliente: ";
    getline(cin, avaliation);

    ConstructionCompany* Company(cnpj, name, cnpj, phone, avaliation);

}