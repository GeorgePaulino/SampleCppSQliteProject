#include "ClietBase.hpp"

void ClientBase::deleteClient( ClientBase* c){
    delete c;
    cout << " Cliente deletado";
    return;
}

