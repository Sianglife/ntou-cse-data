/*Date: 2025/12/14
Author: 黃鈺翔
Description: Determining Car Model Year from VIN
Using github copilot to write comments
*/

#include<stdio.h>
#include<string.h>

struct car {
    char VIN[18];
    double latitude;
    double longitude;
};
typedef struct car Car; 

int getCarModelYear(const Car *aCar) {
    int year_code = aCar->VIN[9]; // 取得VIN的第10個字元（索引9）
    int year;
    // 1992-2021 對應的年份代碼
    switch (year_code) {
        case 'N': year = 1992; break;
        case 'P': year = 1993; break;
        case 'R': year = 1994; break;
        case 'S': year = 1995; break;
        case 'T': year = 1996; break;
        case 'V': year = 1997; break;
        case 'W': year = 1998; break;
        case 'X': year = 1999; break;
        case 'Y': year = 2000; break;
        case '1': year = 2001; break;
        case '2': year = 2002; break;
        case '3': year = 2003; break;
        case '4': year = 2004; break;
        case '5': year = 2005; break;
        case '6': year = 2006; break;
        case '7': year = 2007; break;
        case '8': year = 2008; break;
        case '9': year = 2009; break;
        case 'A': year = 2010; break;
        case 'B': year = 2011; break;
        case 'C': year = 2012; break;
        case 'D': year = 2013; break;
        case 'E': year = 2014; break;
        case 'F': year = 2015; break;
        case 'G': year = 2016; break;
        case 'H': year = 2017; break;
        case 'J': year = 2018; break;
        case 'K': year = 2019; break;
        case 'L': year = 2020; break;
        case 'M': year = 2021; break;
        default: year = -1; break; // 無效的年份代碼
    }
    return year;
}

int main() {
    char vin[18];
    Car myCar;
    while(scanf("%17s", vin) == 1) { // 讀取VIN碼，最多17個字元
        strcpy(myCar.VIN, vin); // 複製VIN碼到myCar struct
        printf("%d\n", getCarModelYear(&myCar)); // 輸出車輛年份
    }
    return 0;
}