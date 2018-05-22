#include <iostream>

using namespace std;

class Test
{
//Private variable cannot be accessed out of class through dot-notation
private:
    int a;
    int b;

//Public variable can be accessed out of class through dot-notation
public:

    void SetInitialValues(int numA, int numB)
    {
        a = numA;
        b = numB;
    }

    void Show()
    {
        cout << "a has value of " << a << endl
             << "b has a value of " << b << endl;
    }
};
