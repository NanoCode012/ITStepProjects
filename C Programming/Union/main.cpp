#include <iostream>

using namespace std;

//Like struct but at runtime, only has one variable. To save RAM
union Key{
    int a;
    char b;
};

int main(){
    Key myKey;

    //The below is bad practice. It is only supposed to have used one field of Key. The below is only for understanding how it only uses one variable
    myKey.a = 10;
    myKey.b = 'a';
    cout << myKey.a << endl;
    return 0;
}