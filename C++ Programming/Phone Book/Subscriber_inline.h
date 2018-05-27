#pragma once

#include "Subscriber.h"

inline char* Subscriber::GetName()
{
    return name;
}
inline int Subscriber::GetHomePhone()
{
    return homePhone;
}
inline int Subscriber::GetWorkPhone()
{
    return workPhone;
}
inline int Subscriber::GetMobilePhone()
{
    return mobilePhone;
}