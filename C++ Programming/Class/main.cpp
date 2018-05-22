#include "Test.cpp"
#include "Point.h"
#include "Student.cpp"
#include "Fraction.h"

int main()
{
    //public / private modifiers
    Test obj;
    obj.SetInitialValues(5, 6);

    //cannot access below because is private
    /* obj.a; */

    //can access below because is pubic
    obj.Show();
    
    //More Examples
    Fraction fA;
    fA.SetInitialValue(3, 5);
    Fraction fB;
    fB.SetInitialValue(1, 10);
    fA.Add(fB);
    fA.Show();

    //Constructors and Destructors
    Student john("john", "08/20/2019", "pp", "kh", "yi", "po", 4045, 2938);
    john.Show();

    Student *joshPointer = new Student("hark", "7/2/2012", "pp", "kh", "Nd", "kf", 2932, 3848);
    delete(joshPointer);//Need to delete ourself because we directly allocated memory

    //More Examples
    Point pointA(5, 3, 2);
    // pointA.ReadCoordinatesFromFileAtPath("Data.txt");
    pointA.ShowCoordinates();
    // pointA.SaveCoordinatesToFileAtPath("Data.txt");

    return 0;
}