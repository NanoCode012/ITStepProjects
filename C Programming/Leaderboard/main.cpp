#include <iostream>
#include "array.h"

using namespace std;

int SetName(char list[][10], char names[]){
    int lastIndex = Count(list);
    int lastChar = Count(names);
    for (int i = 0; i < lastChar; i++){
        list[lastIndex][i] = names[i];
    }
    return 0;
}

int ShowName(char names[][10], int index){
    int count = Count(names[index]);
    for (int i = 0; i < count; i++){
        cout << names[index][i];
    }
    
    cout << endl;
    return 0;
}

int SetValue(int scores[][2], int score){
    int count = Count(scores);
    scores[count][0] = score; 
    scores[count][1] = count;
    return 0;
}

int Swap(int scores[][2], int pos0, int pos1){
    int temp = scores[pos0][0];
    scores[pos0][0] = scores[pos1][0];
    scores[pos1][0] = temp;

    temp = scores[pos0][1];
    scores[pos0][1] = scores[pos1][1];
    scores[pos1][1] = temp;
    return 0;
}

int BubbleSort(int scores[][2]){
    int count = Count(scores);
    bool hasSwapped;
    for (int i = 0; i < count; i++){
        hasSwapped = false;
        for (int j = i+1; j < count; j++){
            if (scores[i][0] < scores[j][0]) {
                Swap(scores, i, j);
                hasSwapped = true;
            }
        }
        if (!hasSwapped) break;
    }
    return 0;
}

int ShowLeaderboard(int scores[][2], char names[][10], int numOfParticipants){
    int tempScore = 0;
    int rank = 0;
    int tempRank = rank;
    for (int i = 0; i < numOfParticipants; i++) {
        rank++;
        if (tempScore == scores[i][0]) {
            cout << tempRank << "\t";
            ShowName(names, scores[i][1]);
        }else {
            cout << rank << "\t" ;
            ShowName(names, scores[i][1]);
            tempRank = rank;
        }
        tempScore = scores[i][0];
    }
    return 0;
}

int main(){
    
    int numOfPeople = 5;
    int scores[numOfPeople][2];
    char names[numOfPeople][10];

    names[0][0] = '0';//when init a char[], it sets char[0][1] to 'p', bypassing my check

    //Input
    int tempScore = 0;
    char tempName[10];
    cout << "Please input amountOfPeople: ";
    cin >> numOfPeople;
    for (int i = 0; i < numOfPeople; i++){
        cout << "Please input score between 1->100: ";
        cin >> tempScore;
        if (0 < tempScore && tempScore <= 100){
            cout << "Please set name: ";
            cin >> tempName;
            SetValue(scores, tempScore);
            SetName(names, tempName);
            cout << "Name added!" << endl;
        }else {
            cout << "Score not within range. Please try again." << endl;
            i--;
        }
    }
    /*
    //Set scores (score cannot be 0)
    SetValue(scores, 87);
    SetValue(scores, 98);
    SetValue(scores, 50);
    SetValue(scores, 98);
    SetValue(scores, 75);
    //Set names
    SetName(names, "happy");
    // cout << Count(names) << endl;
    SetName(names, "box");
    // cout << Count(names) << endl;
    SetName(names, "card");
    // cout << Count(names) << endl;
    // ShowName(names, 0);
    // ShowName(names, 2);
    // ShowName(names, 0);
    SetName(names, "eli");
    SetName(names, "pox");
    */

    BubbleSort(scores);
    cout << "Rank\tName" << endl;
    ShowLeaderboard(scores, names, numOfPeople);


    return 0;
}

