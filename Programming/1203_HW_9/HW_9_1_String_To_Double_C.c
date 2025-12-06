/*Date: 2025/12/07
Author: 黃鈺翔
Description: Convert string to double
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>
#include<math.h>

// Convert character digit to integer digit
int char2digit(char c) {
    // Input should be '0' to '9'
    return c - '0';
}

// Convert string to integer
int str2int(char *str) {
    // Input should be integer string only
    int result = 0; // Result integer
    int exp = 0; // Exponent of 10 for now place
    for(int i = strlen(str) - 1; i >= 0; i--){
        result += char2digit(str[i]) * pow(10, exp++); // Add digit value multiplied by its place base value
    }
    return result;
}

// Convert fractional string to double below 1
double str2double_below1(char *str) {
    // Input should be fractional string only, e.g. "123" for 0.123
    double result = 0; // Result double
    int exp = -1; // Exponent of 10 for now place
    for(int i = 0; i < strlen(str); i++){ 
        result += char2digit(str[i]) * pow(10, exp--); // Add digit value multiplied by its place base value
    }
    return result;
}

// Convert string to double
double atod(const char *input) {
    int i, sign, point_pos, index = 0, len = strlen(input);
    // sign: 1 for positive, -1 for negative
    // point_pos: position of decimal point
    // index: current index in input string
    // len: length of input string
    // i: loop counter
    double result = 0; // Result double

    // Determine positive or negative, and set starting index
    if(input[0] == '-') {
        sign = -1;
        index++;
    } else {
        sign = 1;
    }
    
    char str_buffer[50];
    // Convert number before float point
    for(i = 0; index < len; i++) {
        str_buffer[i] = input[index]; // Copy each character to buffer
        if(input[index] == '.') {
            // Encounter decimal point, end of integer part
            str_buffer[i] = '\0'; // Terminate string at the end of buffer
            index++; // also move index to next character after point
            break;
        }
        index++;
    }
    result += str2int(str_buffer) * sign; // Convert integer part and apply sign

    // Convert number after float point
    for(i = 0; index < len; i++) {        
        str_buffer[i] = input[index]; // Copy each character to buffer
        index++;
    }
    str_buffer[i] = '\0'; // Terminate string at the end of buffer
    result += str2double_below1(str_buffer) * sign; // Convert fractional part and apply sign
    return result;
}

int main() {
    char input[100];
    while(scanf("%s", input) == 1){
        printf("%.6lf\n", atod(input));
    }
    return 0;
}