#include <iostream>

using namespace std;
int main(){
    //Declaration
    int inputSeconds, hours, secRemaining, minutes, seconds = 0;
    const int secPerHour = 3600;
    const int secPerMin = 60;

    //Input
    cout << "Please enter second(s) : " ;
    cin >> inputSeconds;

    //Logic
    hours = inputSeconds/secPerHour;
    secRemaining = inputSeconds % secPerHour;
    minutes = secRemaining/secPerMin;
    seconds = secRemaining % secPerMin;

    //Output
    cout << "\nThe time converted from the input given is "   
         << hours    << " hour(s), "           
         << minutes  << " minute(s), and "   
         << seconds  << " second(s).";
    return 0;
}