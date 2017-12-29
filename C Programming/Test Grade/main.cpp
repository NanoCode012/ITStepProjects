#include <iostream>

using namespace std;

int main(){
    //Declare
    int i = 0;
    float input = 0;
    int passCount = 0;
    float average = 0;

    const int timesToRun = 5;
    const int passGrade = 50;
    const int passRequired = 3;

    //Output key
    cout << "****** KEY ******" << endl;
    cout << "S1 - Math" << endl;
    cout << "S2 - English" << endl;
    cout << "S3 - Programming" << endl;
    cout << "S4 - Physic" << endl;
    cout << "S5 - Khmer" << endl;
    cout << "Grade should be an integer from 0 to 100" << endl << endl;

    //Input&Logic
AppStart:
    i++;
    cout << "Please input S" << i << " grade: ";
    cin >> input;
    if (input < 0 || input > 100){//Defense
        cout << "Invalid number. Please try again." << endl;
        i--;
        goto AppStart;
    }
    if (input >= passGrade) passCount++;
    average += input;
    if (i < timesToRun) goto AppStart;

    average /= i;

    //Output
    (average >= passGrade) ? cout << "Pass through first rule" << endl 
                            : cout << "Fail first rule" << endl;
    (average >= passGrade && passCount >= passRequired) 
                            ? cout << "Pass through second rule" << endl 
                            : cout << "Fail second rule" << endl;
    return 0;
}