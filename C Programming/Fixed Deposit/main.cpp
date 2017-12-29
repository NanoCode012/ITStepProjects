#include <iostream>

using namespace std;

int main(){
    int base = 0;
    float monthlyRate = 0.01f;
    int interest = 0;
    int months = 0;
    int total = 0;

    cout << "Please enter deposit: ";
    cin >> base;
    cout << "Interest rate: ";
    cin >> monthlyRate;
    cout << "Time(months) to withdrawal: ";
    cin >> months;

    cout << "Index\tBase\t\tInterest\tTotal" <<endl;
    total = base;
    for (int i = 1; i <= months; i++){
        base = total;
        interest = base * monthlyRate;
        total += interest;

        cout << i << ".\t" << base << "\t\t" << interest << "\t\t\t" << total << endl;
    }
    return 0;
}