#include <iostream>
#include <string>

using namespace std;

class ClientBase{
public:
    int  id; //Chave Primaria
    string name, phoneNumber;

    ClientBase();
    ~ClientBase();

    void deleteClient( ClientBase* c){}
};
