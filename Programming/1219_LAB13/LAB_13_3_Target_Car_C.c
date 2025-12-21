/*Date: 2025/12/19
Author: 黃鈺翔
Description: Sorting Mobile Cars Based on Distance to Target Car
Using github copilot to write comments
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct car {
    char VIN[18];
    double latitude;
    double longitude;
};
typedef struct car Car; 

Car targetCar;

double get_distance(double lat1, double lon1, double lat2, double lon2) {
    // 帶公式計算兩座標點間距離
    double dlat = lat1 - lat2;
    double dlon = lon1 - lon2;
    double a = pow(sin(dlat / 2 * M_PI / 180), 2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * pow(sin(dlon / 2 * M_PI / 180), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371.0 * c;
    return distance;
}

int cmpCars(const void *a, const void *b) {
    // 比較兩台車與目標車的距離，給qsort使用
    const Car *carA = *(const Car **)a;
    const Car *carB = *(const Car **)b;
    double distA = get_distance(targetCar.latitude, targetCar.longitude, carA->latitude, carA->longitude);
    double distB = get_distance(targetCar.latitude, targetCar.longitude, carB->latitude, carB->longitude);
    return distA - distB;
}

void printMobileCarsByTarget(const Car *target, const Car **mobileCars, int numCars) {
    // 根據與目標車的距離排序並輸出移動車輛資訊
    qsort(mobileCars, numCars, sizeof(Car *), cmpCars); // 用qsort排序
    for(int i = 0; i < numCars; i++) {
        // 輸出每台車的VIN、經緯度及與目標車的距離
        printf("%s (%.2lf, %.2lf) %.2lf\n", mobileCars[i]->VIN, mobileCars[i]->latitude, mobileCars[i]->longitude, get_distance(target->latitude, target->longitude, mobileCars[i]->latitude, mobileCars[i]->longitude));
    }
}

int main() {
    Car **mobileCars = malloc(100 * sizeof(Car*));
    for(int i = 0; i < 100; i++) {
        mobileCars[i] = malloc(sizeof(Car));
    }
    int numMobileCars;
    char tmp[100]; // 暫存輸入字串
    
    // 輸入處理迴圈
    while(scanf("%d", &numMobileCars) == 1) {
        getchar(); // 吃掉換行符號
        
        // Target car
        scanf("%s", targetCar.VIN); // 讀取VIN
        getchar(); // 吃掉空格符號
        fgets(tmp, sizeof(tmp), stdin); // 先讀行到暫存字串
        sscanf(tmp, "(%lf, %lf)", &targetCar.latitude, &targetCar.longitude); // 讀取經緯度
        
        // Mobile cars
        for(int i = 0; i < numMobileCars; i++) {
            scanf("%s", mobileCars[i]->VIN); // 讀取VIN
            getchar(); // 吃掉空格符號
            fgets(tmp, sizeof(tmp), stdin); // 先讀行到暫存字串
            sscanf(tmp, "(%lf, %lf)", &(mobileCars[i]->latitude), &(mobileCars[i]->longitude)); // 讀取經緯度
        }

        // Call function to print mobile cars by target
        printMobileCarsByTarget(&targetCar, (const Car **)mobileCars, numMobileCars); // 強制轉型為const Car**
    }
    
    // 釋放記憶體
    for(int i = 0; i < 100; i++) {
        free(mobileCars[i]);
    }
    free(mobileCars);

    return 0;
}
