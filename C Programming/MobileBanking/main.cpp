#include <iostream>

using namespace std;

int main(){
    int userPw = 1;
    int inputPw;
    int balance = 100;
    bool retry = true;
    cout << "Please enter password: ";
    cin >> inputPw;
    if (userPw == inputPw){
        StartApplication:
        cout << "Welcome ${name}" << endl;
        cout << "Please choose one of the option below to continue." << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Transfer" << endl;
        cout << "3. Mobile Topup" << endl;
        cout << "4. Exit" << endl;
        int opt;
        cout << "Option: ";
        cin >> opt;
        
        if (opt == 1){
            cout << "You have " << balance << "$" << endl;
        }else if (opt == 2){
            int phoneNumber;
            int amount;
            cout << "Please enter receiver's phone number: ";
            cin >> phoneNumber;
            cout << "Please enter amount to send: ";
            cin >> amount;
            if (amount <= balance){
                balance -= amount;
                cout << "Success" << endl;
            }else cout << "Error. Not enough money in account." << endl;
        }else if (opt == 3){
            int amount;
            cout << "Please enter amount to top-up: ";
            cin >> amount;
            if (amount <= balance){
                balance -= amount;
                cout << "Success" << endl;
            }else cout << "Error. Not enough money in account." << endl;
        }else if (opt == 4){
            retry = false;
        }else {
            cout << "Invalid Input";
        }
        if (retry){
            char redo = 0;
            cout << "Do you want to make another transaction? Y to agree." << endl;
            cout << "Option: ";
            cin >> redo;
            if (redo == 'Y' || redo == 'y'){
                goto StartApplication;
            }
        }
    }else cout << "Wrong Password" << endl;
    return 0;
}