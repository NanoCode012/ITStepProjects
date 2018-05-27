#include "Subscriber.h"

Subscriber::Subscriber()
{
    SetName(NULL);
    SetHomePhone(0);
    SetWorkPhone(0);
    SetMobilePhone(0);
}
Subscriber::Subscriber(const char *name, int homePhone, int workPhone, int mobilePhone)
{
    SetName(name);
    SetHomePhone(homePhone);
    SetWorkPhone(workPhone);
    SetMobilePhone(mobilePhone);
}
Subscriber::Subscriber(const Subscriber &sub)
{
    this->SetName(sub.name);
    this->SetHomePhone(sub.homePhone);
    this->SetWorkPhone(sub.workPhone);
    this->SetMobilePhone(sub.mobilePhone);
}
Subscriber::~Subscriber()
{
    delete []name;
}

void Subscriber::SetName(const char * name)
{
    if (name == NULL)
    {
        this->name = NULL;
    }
    else
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}
void Subscriber::SetHomePhone(int num)
{
    if (num >= 0) this->homePhone = num;
}
void Subscriber::SetWorkPhone(int num)
{
    if (num >= 0) this->workPhone = num;
}
void Subscriber::SetMobilePhone(int num)
{
    if (num >= 0) this->mobilePhone = num;
}