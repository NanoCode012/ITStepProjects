#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

char *months[] = {"None" , "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
char *GetMonth(int input){
    return ((input < 1) || input > 12) ? months[0] : months[input];
}


int main(){
    //String using array
    char greeting[] = "Hello";
    char greeting2[] = {'H', 'e', 'l', 'l', 'o', '\0'};//The last char is a null, it determines the end of the string
    cout << greeting << endl;
    cout << greeting2 << endl;

    //String using pointer
    char *greeting3 = new char[10];
    strcpy(greeting3, "hello"); 
    puts(greeting3);//Alternative of cin but only accepts char*
    delete []greeting3;//benefit of pointer is the abilty to de-allocate

    //String array
    int input;
    cout << "Please input month number: ";
    cin >> input;
    cout << "You got " << GetMonth(input) << endl;

    //Compare strings
    char *s1 = new char[100];
    char *s2 = new char[100];

    cout << "Please input S1: ";
    cin >> s1;
    cout << "Please input S2: ";
    cin >> s2;

    int result = strcmp(s1, s2);
    cout << "Result is : " << result << endl;

    //Length
    char *s3 = new char[10];
    strcpy(s3, "Hi");
    int length = strlen(s3);
    cout << "Word is : " << s3 << endl;
    cout << "Length is : " << length << endl;

    //Contains
    char *s4 = new char[10];
    strcpy(s4, "Hil");
    if (strchr(s4, 'l') != NULL)
    {
        cout << "contains" << endl;
    }
    else {
        cout << "does not contain" << endl;
    }

    //Search key within string
    char *key = new char[10];
    cout << "Input key : ";
    cin >> key;
    for (int i = 0; i < 13; i++)
    {
        if (strstr(strlwr(ConvertToArray(months[i])), key))
        {
            cout << "Found one at " << months[i] << endl;
        }
    }
    return 0;
}