#include <iostream>

using namespace std;

int main(){
    float base;
    float interest;
    float monthlyRate;
    float installment;
    float remainder;
    int month;
    cout << "Loan amount: ";
    cin >> base;
    cout << "Monthly rate: ";
    cin >> monthlyRate;
    cout << "Installment amount: ";
    cin >> installment;
    cout << "Time(month): ";
    cin >> month;

    monthlyRate /= 100;
    remainder = base;
    if (installment <= monthlyRate * base){
        cout << "Warning! Installment paid is less than interest owed. Please redo this. The calculation below will be never ending." << endl;
    }
    cout << "Index\tBase\tInterest\tInstallment\tRemainder" << endl;
    for (int i = 1; i <= month; i++){
        base = remainder;
        interest = base*monthlyRate;
        remainder -= installment - interest;
        if (remainder < 0) {
            cout << i << ".\t" << base << "\t" << interest << "\t\t" << 50 + remainder 
            << "\t\t" << 0 << endl;
            cout << "END" << endl;
            break;
        }else{
            cout << i << ".\t" << base << "\t" << interest << "\t\t" << installment 
                 << "\t\t" << remainder << endl;
        }
    }


    return 0;
}