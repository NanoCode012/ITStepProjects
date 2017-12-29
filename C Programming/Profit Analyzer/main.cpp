#include <iostream>

using namespace std;

int main(){
    const int months = 12;
    int profit[months] = {30,120,30,40,50,60,70,80,90,100,120,120};
    for(int i = 0; i < months; i++) cout << i + 1 << ". " << profit[i] << endl;
    int opt = -1;
    cout << "Options" << endl
         << "1. Get month with highest profit" << endl
         << "2. Display profit from" << endl
         << "3. Display profit between range" << endl
         << "Choose your option: ";
    cin >> opt;
    int highestProfit = -1;
    int highestProfitCount = 1;
    int highMonths[months];
    switch(opt){
        case 1:
            /*
            for (int j = 0; j < months; j++){
                if (highestProfit < profit[j]) {
                    highestProfit = profit[j];
                    highestProfitCount = 1;
                    highMonths[highestProfitCount] = j + 1; 
                }
                else if (highestProfit == profit[j]) {
                    highestProfitCount++;
                    highMonths[highestProfitCount] = j + 1;
                }
            }
            cout << "The highest profit is " << highestProfit << endl;
            cout << "The highest profit is earned in month ";
            for(int k = 1; k <= highestProfitCount; k++){
                cout << " " << highMonths[k];
            }
            cout << "." << endl;
            */
            for(int j = 0; j < months; j++) if (highestProfit < profit[j]) highestProfit = profit[j];
            for(int j = 0; j < months; j++) if (highestProfit == profit [j]) cout << "Month " << j + 1 << " is the highest with $" << highestProfit <<  endl;
            break;
        case 2:
            break;
        case 3:
            break;
        }
    return 0;
}