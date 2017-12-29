#include <iostream>

using namespace std;

int main(){

    const char underscore = '_';
    const char backslash = '\\';
    const char frontslash = '/';
    const char space = ' ';
    const char character = '*';

    int height = -1;
    int tempHeight = 0;
    int tempBase = -1;
    int tempSpaceCount = -1;
    cout << "Input height of triangle: ";
    cin >> height;

    //Draw equilateral
    while(tempHeight++ < height){
        tempSpaceCount = height - tempHeight;//space before first slash
        while(tempSpaceCount-- > 0) cout << space;
        cout << frontslash;
        tempBase = 2*(tempHeight) - 2;//gaps between front and back slash
        if (tempHeight == height) while(tempBase-- > 0) cout << underscore;//last line
        else while(tempBase-- > 0) cout << space;//middle line
        cout << backslash << endl; 
    }

    cout << endl << endl;

    //Draw right-angle triangle
    int spaceCount = 0;
    tempSpaceCount = 0;
    tempHeight = 1;
    cout << character << endl;
    while(tempHeight++ < height){
        cout << character;
        tempSpaceCount = spaceCount;
        if (tempHeight == height) while(tempSpaceCount-- > 0) cout << character;//fill last line with characters
        else while(tempSpaceCount-- > 0) cout << space;//gap between 2 characters
        cout << character << endl;
        spaceCount++;//space to second slash
    }



    return 0;
}
/*
Height | Base
1        0      /\
2        2       /\
                /__\
3        4      /\
               /  \
              /____\
4        6      /\
               /  \
              /    \
             /______\

Base = 2*height - 2
*/