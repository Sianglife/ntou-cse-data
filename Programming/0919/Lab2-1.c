/*Date: 2025/9/15
  Author: 黃鈺翔
  Description: print size of types*/

#include <stdio.h>

int main() {
    printf("char:%d個位元組\n", sizeof(char)); // 可儲存一個字元，1byte=8bit，可以-128~127的值儲存8-bit ASCII Code
    printf("short:%d個位元組\n", sizeof(short)); // 可儲存較小的整數，2byte=16bit，可存(2^15)-32768~32767的值
    printf("long:%d個位元組\n", sizeof(long)); // 可儲存整數，4byte=32bit，可存(2^31)-2,147,483,648~2,147,483,647的值
    printf("int:%d個位元組\n", sizeof(int)); // 可儲存整數，4byte=32bit，可存(2^31)-2,147,483,648~2,147,483,647的值，Windows中int與long相同
    printf("float:%d個位元組\n", sizeof(float)); // 可儲存小數，4byte=32bit，可存約7位有效數字，有1-bit sign bit、8-bit exponent、23-bit mantissa
    printf("double:%d個位元組\n", sizeof(double)); // 8byte=64bit，比float可儲存更精確的小數，可存約15位有效數字，更不容易overflow，有1bit sign bit、11-bit exponent、52-bit mantissa
    printf("long double:%d個位元組\n", sizeof(long double)); // 16byte=128bit，比double可儲存更精確的小數，各作業系統不同 
    printf("unsigned short:%d個位元組\n", sizeof(unsigned short)); // short的無正負號版本，因此可存0~65,535的值
    printf("unsigned int:%d個位元組\n", sizeof(unsigned int)); // int的無正負號版本，因此可存0~4,294,967,295的值
    return 0;
}