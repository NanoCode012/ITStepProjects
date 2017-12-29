#include <iostream>

using namespace std;
int main(){
    
    //Declaration
    float initialCost, cost, firstDiscount, secondDiscount, discountAmount = 0;
    char productName[10];

    //Input
    
    cout << "Please enter product name : " ;
    cin >> productName;
    cout << "Please enter cost($) : " ;
    cin >> initialCost;
    cout << "Please enter discount 1(%) : ";
    cin >> firstDiscount;
    cout << "Please enter discount 2(%) : ";
    cin >> secondDiscount;

    //Logic
    cost = initialCost;
    cost *= 1 - firstDiscount/100;
    cost *= 1 - secondDiscount/100;
    discountAmount = initialCost - cost;

    //Output
    cout << "=================================" << endl;
    cout << "Product : " << productName << endl;
    cout << "Subtotal : " << initialCost << endl;
    cout << "DiscountAmount : " << discountAmount << endl;
    cout << "Total : " << cost << endl; 

    
    return 0;
}