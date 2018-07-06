#include <iostream>

using namespace std;

char possibleCharacters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int number[100];

int Pow(int num, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= num;
    }
    return result;
}

void ConvertFromDecimal(int num, int base)
{
    if (base < 2 || base > 36) 
    {
        cout << "Base too low or too high! Base set to 10.";
        base = 10;
    }
    int size = 0;
    while(num > 0)
    {
        number[size++] = num % base;
        num /= base;
    }
    for (int i = size - 1; i >= 0; i--)
    {
        cout << possibleCharacters[number[i]];
    }
    cout << endl;
}

void ConvertToDecimal(int num, int base)
{
    int total = 0;
    if (base < 2 || base > 36) 
    {
        cout << "Base too low or too high! Base set to 10";
        base = 10;
    }
    int index = 0;
    while(num > 0)
    {
        total +=(num % 10) * Pow(base, index);
        num /= 10; 
        index++;
    }
    cout << total << endl;

}

int main(){
    int num;
    int base;
    
    cout << "Please enter num : ";
    cin >> num;
    cout << "Please enter base : ";
    cin >> base;
    
    cout << "From base 10 to base "<< base << " : ";
    ConvertFromDecimal(num, base);
    
    cout << "From base " << base << " to base 10 : ";
    ConvertToDecimal(num, base);
    return 0;
}