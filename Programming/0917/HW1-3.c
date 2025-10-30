/* Date: 2025/9/17
   Author: 黃鈺翔
   Description: ask user price and weight, then print the price per gram of the item.*/
#include<stdio.h>

int main() {
    double price, weight, tmp; // price of item, weight (gram), tmp (temporary variable)
    scanf("%lf", &price); // ask user price
    scanf("%lf", &tmp); // ask user weight (kg)
    weight = tmp * 1000;
    scanf("%lf", &tmp); // ask user weight (g)
    weight = weight + tmp; // calculate total weight (g)
    printf("%f", price / weight); // print price per gram
    return 0;
}