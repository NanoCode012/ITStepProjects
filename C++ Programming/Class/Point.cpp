#include "Point.h"

using namespace std;

int ConvertFromStringToInt(string input)
{
    int num = 0;
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        num += (input[i] - '0') * (int)pow(10, length - i - 1);
    }
    return num;
}

Point::Point()
{

}

Point::Point(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point::ShowCoordinates()
{
    cout << "Point is at position ( " << x << ", " << y << ", " << z << " )" << endl;
}

inline int Point::GetXCoordinate()
{
    return x;
}

inline int Point::GetYCoordinate()
{
    return y;
}

inline int Point::GetZCoordinate()
{
    return z;
}

void Point::SaveCoordinatesToFileAtPath(string path)
{
    ofstream writeStream;
    writeStream.open(path);
    if (writeStream) 
    {
        writeStream << x << "/" << y << "/" << z << "/" << endl;
        writeStream.close();
    }
}

void Point::ReadCoordinatesFromFileAtPath(string path)
{
    ifstream readStream(path);
    string input;
    int pos = 0;
    if (readStream.is_open())
    {
        if (getline(readStream, input))
        {
            string temp = "";
            while(input[pos] != '/')
            {
                temp += input[pos];
                pos++;
            }
            x = ConvertFromStringToInt(temp);
            temp = "";
            pos++;
            while(input[pos] != '/')
            {
                temp += input[pos];
                pos++;
            }
            y = ConvertFromStringToInt(temp);
            temp = "";
            pos++;
            while(input[pos] != '/')
            {
                temp += input[pos];
                pos++;
            }
            z = ConvertFromStringToInt(temp);
        }
    }
}

