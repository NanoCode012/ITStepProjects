#pragma once

#include <string>

class Subscriber
{
private:
    char *name;
    int homePhone, workPhone, mobilePhone;

public:
    Subscriber();
    Subscriber(const char *name, int homePhone, int workPhone, int mobilePhone);
    Subscriber(const Subscriber &sub);
    ~Subscriber();

    inline char* GetName();
    inline int GetHomePhone();
    inline int GetWorkPhone();
    inline int GetMobilePhone();

    void SetName(const char * name);
    void SetHomePhone(int num);
    void SetWorkPhone(int num);
    void SetMobilePhone(int num);
};

#include "Subscriber_inline.h"