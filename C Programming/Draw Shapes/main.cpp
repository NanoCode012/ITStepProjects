#include <iostream>

using namespace std;

int main(){
    const char sign = '*';
    const char space = ' ';
    const int row = 10;
    const int column = 10;

    //Draw right-slash diagonal with top-half filled
    cout << "right-slash diagonal with top-half filled" << endl;
    for (int i = 0; i < row; i++){
        for (int j = i; j < column; j++) cout << sign;
        cout << endl;
    }
    cout << endl;

    //Draw left-slash diagonal with top-half filled
    cout << "left-slash diagonal with top-half filled" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < i; j++) cout << space;
        for (int j = i; j < column; j++) cout << sign;
        cout << endl;
    }
    cout << endl;

    //Draw left-slash diagonal with bottom-half filled
    cout << "left-slash diagonal with bottom-half filled" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j <= i; j++) cout << sign;
        cout << endl;
    }
    cout << endl;

    //Draw right-slash diagonal with bottom-half filled
    cout << "right-slash diagonal with bottom-half filled" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column - i; j++) cout << space;
        for (int j = column - i; j <= column; j++) cout << sign;
        cout << endl;
    }
    cout << endl;

    //Draw upside-down triangle(2*height - 2)=column
    cout << "upside-down triangle" << endl;
    int height = ( row + 2 ) / 2;
    int amountOfSpace = 0;
    for (int i = 0; i < height; i++){
        for(int j = 0; j < amountOfSpace; j++) cout << space;
        for (int j = 0; j < column - (amountOfSpace * 2); j++) cout << sign;
        for(int j = 0; j < amountOfSpace; j++) cout << space;
        amountOfSpace++;
        cout << endl;
    }
    for (int i = 0; i < row - height; i++) cout << endl;
    cout << endl;

    //Draw upside triangle(2*height - 2)=column
    cout << "upside triangle" << endl;
    amountOfSpace = (column - 1)/2;
    for (int i = 0; i <= row - height; i++) cout << endl;
    for (int i = 0; i < height - 1; i++){
        for(int j = 0; j < amountOfSpace; j++) cout << space;
        for (int j = 0; j < column - (amountOfSpace * 2); j++) cout << sign;
        for(int j = 0; j < amountOfSpace; j++) cout << space;
        amountOfSpace--;
        cout << endl;
    }
    cout << endl;

    return 0;
}