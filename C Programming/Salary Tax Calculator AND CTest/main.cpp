#include <iostream>
#include "logic.h"

using namespace std;

int main()
{
    //Declare
    float salary = -1;
    float tax = -1;
    float netSalary = -1;

    //Input
    cout << "Input : ";
    cin >> salary;

    //Logic
    if (cin){
        tax = CalculateTax(salary);
        netSalary = salary - tax;
    }
    
    //Output
    cout.precision(14);
    if (tax != -1){
        cout << "=======================================" << endl
             << "Gross salary : "            << salary    << endl
             << "Tax          : "            << tax       << endl
             << "Net salary   : "            << netSalary << endl;
    }else{
        cout << "Invalid input. Please retry again later." << endl; //Check for -ive number or character
    }
    return 0;
}

/*
Monthly salary (Riels)	Rate
0 - 1,000,000	0%
1,000,001 - 1,500,000	5%
1,500,001 - 8,500,000	10%
8,500,001 - 12,500,000	15%
12,500,001 - upwards	20% */