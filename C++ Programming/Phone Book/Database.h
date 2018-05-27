#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Subscriber.h"
#include "Misc.h"

class Database
{
private:
    Subscriber *subscribers;
    int size, capacity;

    bool IsFull();
public:
    Database(int capacity = 10);
    ~Database();
    
    bool AddSubscriber(Subscriber subscriber);
    bool DeleteSubscriber(int indexOfSubscriber);
    
    bool SearchSubscriber(const char * name);
    
    void ShowSubscriber(int index);
    void ShowAllSubscriber();

    void SaveDataToFile(const char * path = "./build/Data.txt");
    bool ReadDataFromFile(const char * path = "./build/Data.txt");

    int GetSize();
};