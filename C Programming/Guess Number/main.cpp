#include <iostream>

using namespace std;

int main(){
    int guess = 312;
    int input = -1;
    int tries = 0;
    cout << "PC picked a number. Guess between 1->500." << endl;
    while(true){
        cout << "Your guess is : ";
        cin >> input;
        if (input == 0) break;
        if (input < 0 || input > 500){
            cout << "Invalid input. Not within range." << endl;
        }
        else if (input == guess){
            cout << "YAYYYY! You got it!" << endl;
            break;
        }else if (input > guess){
            cout << "Your chosen number is bigger than mine" << endl;
        }else if (input < guess){
            cout << "Your chosen number is smaller than mine" << endl;
        }
        tries++;
    }
    cout << "It took you " << tries << " tries to get here." << endl;
    return 0;
}