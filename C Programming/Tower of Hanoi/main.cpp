#include <iostream>

using namespace std;

void PrintLine(char character = '=')
{
    for (int i = 0; i < 20; i++) cout << character;
    cout << endl;
}

void PrintTowers(int *towerA, int *towerB, int *towerC, int size)
{
    PrintLine();
    for (int i = 0; i < size; i++)
    {
        if (towerA[i] != 0) cout << towerA[i];
        cout << "\t";
        if (towerB[i] != 0) cout << towerB[i];
        cout << "\t";
        if (towerC[i] != 0) cout << towerC[i];
        cout << endl;
    }
    PrintLine();
}

void SetTowerToFull(int *tower, int size)
{
    for (int i = 0; i < size; i++)
    {
        tower[i] = i + 1;
    }
}

void SetToDefault(int *towerA, int *towerB, int *towerC, int size)
{
    for (int i = 0; i < size; i++)
    {
        towerA[i] = 0;
        towerB[i] = 0;
        towerC[i] = 0;
    }
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Swap(int *towerSource, int *towerDest, int originalSize)
{
    int currentPoint = 0;
    bool stop = false;
    while(currentPoint != originalSize && !stop) 
    {
        if (towerSource[currentPoint] != 0)
        {
            int i = -1;
            //Fill in full
            while(i < originalSize - 1 && !stop)
            {
                if (towerDest[i + 1] != 0)
                {
                    if (towerDest[i + 1] > towerSource[currentPoint])
                    {
                        Swap(towerSource[currentPoint], towerDest[i]);
                    }
                    stop = true;
                }
                i++;
            }
            //Empty
            if (i == originalSize - 1 && towerDest[i] == 0 && stop == false) Swap(towerSource[currentPoint], towerDest[i]);
        }
        currentPoint++;
    }
}

int main(){
    int size = 4;
    // cout << "Please enter desired size : ";
    // cin >> size;
    int *towerA = new int[size];
    int *towerB = new int[size];
    int *towerC = new int[size];
    SetToDefault(towerA, towerB, towerC, size);
    SetTowerToFull(towerA, size);
    PrintTowers(towerA, towerB, towerC, size);

    Swap(towerA, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    cout << "Finish 1" << endl;

    Swap(towerA, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerC, towerA, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    cout << "Finish 2" << endl;

    Swap(towerA, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerC, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerC, towerA, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerA, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    cout << "Finish 3" << endl;

    Swap(towerA, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerC, towerA, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerC, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerC, towerA, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerA, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerC, towerA, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerC, towerB, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerA, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerB, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    Swap(towerA, towerC, size);
    PrintTowers(towerA, towerB, towerC, size);
    return 0;
}