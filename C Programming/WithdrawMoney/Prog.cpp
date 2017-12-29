#include <iostream>

using namespace std;
int main(){
    //Declaration
    int inputDollar, leftOver, hundredNote, fiftyNote, twentyNote, tenNote, fiveNote, oneNote = 0;

    //Input
    cout << "Please enter amount to withdraw($) : " ;
    cin >> inputDollar;

    //Logic
    leftOver = inputDollar;

    hundredNote = leftOver / 100;
    leftOver %= 100;

    fiftyNote = leftOver / 50;
    leftOver %=  50;

    twentyNote = leftOver / 20;
    leftOver %= 20;

    tenNote = leftOver / 10;
    leftOver %= 10;

    fiveNote = leftOver / 5;
    leftOver %= 5;

    oneNote = leftOver / 1;


    //Output
    cout << "You are given "               << endl
         << hundredNote << " hundredNote " << endl
         << fiftyNote   << " fiftyNote "   << endl
         << twentyNote  << " twentyNote "  << endl
         << tenNote     << " tenNote "     << endl
         << fiveNote    << " fiveNote "    << endl
         << oneNote     << " oneNote."     << endl;

    return 0;
}