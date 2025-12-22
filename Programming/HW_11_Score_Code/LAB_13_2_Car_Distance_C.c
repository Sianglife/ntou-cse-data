/*Date: 2025/12/19
Author: 黃鈺翔
Description: Calculating Distance Between Two Cars Based on Latitude and Longitude
Using github copilot to write comments
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

struct car {
    char VIN[18];
    double latitude;
    double longitude;
};
typedef struct car Car; 

double get_distance(double lat1, double lon1, double lat2, double lon2) {
    // 帶公式計算兩座標點間距離
    double dlat = lat1 - lat2;
    double dlon = lon1 - lon2;
    double a = pow(sin(dlat / 2 * M_PI / 180), 2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * pow(sin(dlon / 2 * M_PI / 180), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371.0 * c;
    return distance;
}

double getDistanceBetween2Cars(const Car *car1, const Car *car2) {
    // 把Car結構體的經緯度帶入計算距離的函式
    return get_distance(car1->latitude, car1->longitude, car2->latitude, car2->longitude);
}

int main() {
    Car car1, car2;
    char tmp[100]; // 暫存輸入字串
    while(fgets(tmp, sizeof(tmp), stdin)) { // 先讀行到暫存字串
        // 讀取兩台車的經緯度資料
        // 第一行
        sscanf(tmp, "(%lf, %lf)", &car1.latitude, &car1.longitude);
        if(strcmp(tmp, "\n") == 0) {
            // 如果輸入為空行則結束
            break;
        }

        // 第二行
        fgets(tmp, sizeof(tmp), stdin); // 先讀行到暫存字串
        sscanf(tmp, "(%lf, %lf)", &car2.latitude, &car2.longitude);
        if(strcmp(tmp, "\n") == 0) {
            // 如果輸入為空行則結束
            break;
        }
        
        // 計算並輸出兩車距離
        printf("%.2lf km\n", getDistanceBetween2Cars(&car1, &car2));
    }
    return 0;
}