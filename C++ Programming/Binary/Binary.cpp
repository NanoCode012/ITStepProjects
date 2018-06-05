#include "Binary.h"

using namespace std;

Binary::Binary(int num)
{
    if (num > 0) this->num = num;
}
Binary Binary::operator+(const Binary &other)
{
    return Binary(this->num + other.num);
}
Binary Binary::operator-(const Binary &other)
{
    return Binary(this->num - other.num);
}
Binary Binary::operator*(const Binary &other)
{
    return Binary(this->num * other.num);
}
Binary Binary::operator/(const Binary &other)
{
    return Binary(this->num / other.num);
}

int Binary::operator++()
{
    return (++this->num);
}

int Binary::operator++(int k)
{
    return (this->num++);
}

Binary::operator int()
{
    return ConvertToBinary(num);
}

void Binary::Print()
{
    cout << ConvertToBinary(num) << endl;
}

int Binary::ConvertToBinary(int num)
{
    int bin = 0;
    int index = 0;
    int temp = 0;
    while(num > 0)
    {
        temp = 1;
        for (int i = 0; i < index; i++)
        {
            temp *= 10;
        }
        bin += (num & 1) * temp;

        num = num >> 1;
        index++;
    }
    return bin;
}