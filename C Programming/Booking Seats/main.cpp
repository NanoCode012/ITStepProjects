#include <iostream>

using namespace std;

int PrintSeats(int seat_num[], char seat_status[], int size);
int BookSeats(char status[], int size = 1);

int main(){
    const int size = 10;
    int seat_num[size];
    char seat_status[size];

    for(int i = 0; i < size; i++){
        seat_num[i] = 100 + i;
        seat_status[i] = 'A';
    }

    int opt;
    int id;
    while(true){
        //Show available seats
        cout << "\nID\tSeatNum\tStatus" << endl;
        PrintSeats(seat_num, seat_status, size);

        //Action
        cout << "Please choose which option you want to do: " << endl
             << "1. Book once"                                << endl
             << "2. Book multiple"                            << endl;
        cin >> opt;
        switch(opt){
            case 1: 
                BookSeats(seat_status, 1);
                break;
            case 2:
                int amountOfSeats;
                cout << "Please input how many seats you want to book: ";
                cin >> amountOfSeats;
                if (amountOfSeats > size) cout << "An error occurred. Amount of Seats exceed limit." << endl;
                else  BookSeats(seat_status, amountOfSeats);
                break;
        }
        //Re-check
        cout << "Do you want to continue? " << endl
             << "1. Yes"                    << endl
             << "2. No"                     << endl;
        cin >> opt;
        if (opt != 1) break;
    }
    return 0;
}


int PrintSeats(int seat_num[], char seat_status[], int size){
    for (int i = 0; i < size; i++){
            cout << i + 1 << "\t" << seat_num[i] << "\t" << seat_status[i] << endl;
    }
    return 0;
}

int BookSeats(char status[], int size){
    int id[size];
    int tempId;
    int opt;

    for (int i = 0; i < size; i++){
        while(true){
            cout << "Please select id " << i + 1 << ": ";
            cin >> tempId;
            if (status[tempId - 1] == 'A'){
                bool hasDuplicate = false;
                for(int j = 0; j < i; j++){
                    if (id[j] == tempId){
                        hasDuplicate = true;
                        break;
                    }
                }
                if (!hasDuplicate) {
                    id[i] = tempId;
                    break;
                }
                else {
                    cout << "Invalid seat" << endl;
                    cout << "Do you want to redo the booking?" << endl
                         << "1. Yes"                           << endl
                         << "2. No"                            << endl;
                    cin >> opt;
                    if (opt == 1){
                        i = -1;
                        break;
                    }
                }
            }
            else{
                cout << "Invalid seat" << endl;
            }
        }
    }
    for (int i = 0; i < size; i++){
        status[id[i] - 1] = 'U';
    }
    return 0;
}