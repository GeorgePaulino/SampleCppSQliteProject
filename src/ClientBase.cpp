#include "ClientBase.hpp"

ClientBase::ClientBase() {}
ClientBase::ClientBase(int type, string id, string name, string phone)
    : type(type), id(id), name(name), phone(phone) {}

bool ClientBase::Search(string info)
{
    if (name.find(info) != std::string::npos)
    {
        return true;
    }
    else if(id.find(info) != std::string::npos)
    {
        return true;
    }
    return false;
}