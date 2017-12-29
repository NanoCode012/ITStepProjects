#include <iostream>

using namespace std;

int main(){
    //Declare
    int width, height;
    char c;
    const char space = ' ';

    //Input
    cout << "Width of rectangle: ";
    cin >> width;
    cout << "Height of rectangle: ";
    cin >> height;
    cout << "Character to make box out of: ";
    cin >> c;

    /*
    //Draw forloop
    //First Line
    for (int i = 0; i < width; i++){
        cout << c;
    }
    cout << endl;
    //Lines between first and last
    for (int row = 0; row < height - 2; row++){
        cout << c;
        for (int column = 1; column < width - 1; column++){
            cout << space;
        }
        cout << c;
        cout << endl;
    }
    //Last Line
    for (int i = 0; i < width; i++){
        cout << c;
    }
    cout << endl;
    */

    //Draw whileloop
    int tempWidth = 1;
    int tempHeight = 1;
    /* 
    //First method
    //First Line
    while(tempWidth++ <= width){
        cout << c;
    }
    cout << endl;
    //Lines between first and last
    tempWidth = 1;
    while(tempHeight++ <= height - 2){
        cout << c;
        tempWidth = 1;
        while(tempWidth++ <= width - 2){
            cout << space;
        }
        cout << c;
        cout << endl;
    }
    //Last Line
    tempWidth = 1;
    while(tempWidth++ <= width){
        cout << c;
    }
    cout << endl;
    */
    
    //Second method
    while(tempHeight <= height){
        tempWidth = 1;
        if (tempHeight == 1 || tempHeight == height){
            while(tempWidth++ <= width) cout << c;
        }else if (1 < tempHeight && tempHeight < height){
            cout << c;
            while(tempWidth++ <= width - 2) cout << space;
            cout << c;
        }
        cout << endl;
        tempHeight++;
    }

    return 0;
}