#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void WriteToFile(string path, string message){
    ofstream outputFileStream;
    outputFileStream.open(path, ios::app);//ios::app means append. remove it to replace file
    outputFileStream << message << endl;
    outputFileStream.close();
}

void ReadFromFile(string path, string *arr, int length){
    ifstream inputFileStream(path);
    if (inputFileStream.is_open()){
        for (int i = 0; i < length; i++) if (!getline(inputFileStream, arr[i])) break;
    }else{
        puts("File not found!");
    }
    inputFileStream.close();
}

void Output(string *arr, int length){
    for (int i = 0; i < length; i++) {
        if (arr[i].length() > 0){
            cout << arr[i] << endl;
        }else break;
    }
}

int main(){
    //WriteToFile
    // puts("Enter message: ");
    // string message;
    // getline(cin, message);
    // WriteToFile("./log.txt", message);
    // puts("Successfully saved to file");

    //ReadFromFile
    int length = 10;
    string *arr = new string[10];
    puts("Reading 10 lines.");
    ReadFromFile("./log.txt", arr, length);
    Output(arr, length);
    return 0;
}