#include "String.h"

int main()
{
    //Base constructor with optional parameter
    String s;
    s.Input("Hello");
    s.Output();

    String s2(40);
    s2.Input("Fan");
    s2.Output();

    //Constructor with const char * parameter
    String s3("Hiccup");
    s3.Output();

    //Copy Constructor
    String s4 = s3;
    s4.Input("Let");
    s3.Output();
    s4.Output();
    return 0;
}