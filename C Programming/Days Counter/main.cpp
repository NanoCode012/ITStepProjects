#include <iostream>

using namespace std;

int main(){
    int d0;
    int m0;
    int y0;
    int d1;
    int m1;
    int y1;
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "Start day: ";
    cin >> d0;
    cout << "Start month: ";
    cin >> m0;
    cout << "Start year: ";
    cin >> y0;
    cout << "End day: ";
    cin >> d1;
    cout << "End month: ";
    cin >> m1;
    cout << "End year: ";
    cin >> y1;

    
    int sumDays = 0;
    int diffYear = y1 - y0 - 1;
    int monthsToRun;
    
    
    if (diffYear > 0){//dif 2 or more year apart
        // if (m0 != m1) monthsToRun = 12 - m0 + m1 - 1;
        monthsToRun = 12 - m0 + m1 - 1;
        sumDays += month[m0 - 1] - d0;
        sumDays += d1;
        sumDays += diffYear * 365;//Increase days by year
        for(int year = y0 + 1; year < y1; year++){//Only if there are years in between
            if(year % 4 == 0 && year % 100 != 0) sumDays++;
        }
        int tempMonth = m0;
        // if (tempMonth == 2) sumDays++;//if the start month is 2
        while(monthsToRun-- > 0)
        {
            sumDays += month[tempMonth % 12];
            if (tempMonth % 12 == 1)
            {
                if (monthsToRun >= 12){
                    if (y0 % 4 == 0 && y0 % 100 != 0) sumDays++;
                }else {
                    if (y1 % 4 == 0 && y1 % 100 != 0) sumDays++;
                }
            }
            tempMonth++;
        }
    }else if(diffYear < 0){//same year
        if (m0 == m1){
            monthsToRun = 0;
            sumDays += d1 - d0;
        }else {
            sumDays += month[m0 - 1] - d0;
            sumDays += d1;
            if(m0 == 1 && y0 % 4 == 0 & y0 % 100 != 0) sumDays++;
            for(int i = m0; i < m1 - 1; i++){
                sumDays += month[i];
            }
        }
    }else {//year after year each other
        sumDays += month[m0 - 1] - d0;
        sumDays += d1;
        monthsToRun = 12 - m0 + m1 - 1;
        int tempMonth = m0;
        while(monthsToRun-- > 0)
        {
            sumDays += month[tempMonth % 12];
            if (tempMonth == 1)
            {
                if (monthsToRun >= 12){
                    if (y0 % 4 == 0 && y0 % 100 != 0) sumDays++;
                }else {
                    if (y1 % 4 == 0 && y1 % 100 != 0) sumDays++;
                }
            }
            tempMonth++;
        }
    }
    
    
    

    // if (monthsToRun >= 0) {
    //     sumDays += month[m0 - 1] - d0;//Fill the days of the first month
    //     sumDays += d1;//Fill the days of the first month
        // if (monthsToRun > 0){
        //     int tempMonth = m0;//Start from the month after the first month
        //     for(int i = diffYear; i >= 0; i--){
        //         for(int j = tempMonth; j < 12; j++){
        //             if (monthsToRun <= 0) break;
        //             sumDays += month[i];
        //             monthsToRun--;
        //         }
        //         tempMonth = 0;
        //     }
        // }

    // }else {
    //     sumDays += d1-d0;
    // }
    
    // for(int i = m0; i < m1; i++){
    //     sumDays += month[i];
    // }
    cout << "The days difference is " << sumDays << endl;
    
    return 0;
}
/*
3/3/2017 - 4/5/2017
31-3=28
4+28 = 32
Month3-done
Month4-No
Month5-done
2 months,run auto 1 month
*/