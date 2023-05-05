#include"ClientBase.hpp"

ClientBase::ClientBase(){

}

ClientBase::~ClientBase(){}

void ClientBase::deleteClient( ClientBase* c){
    delete c;
    cout << " Cliente deletado";
    return;
}