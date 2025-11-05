#include<algorithm>
#include<iostream>
using namespace std;

int main() {
    int arr[5];
    int *ptr = arr;
    printf("int: before: %p, after: %p\n", ptr, ptr+1);
    char char_arr[5];
    char *c_ptr = char_arr;
    printf("char: before: %p, after: %p\n", c_ptr, c_ptr+1);
    string s_arr[5];
    string *s_ptr = s_arr;
    printf("string: before: %p, after: %p\n", s_ptr, s_ptr+1);
    printf("%p", sizeof(string));
    
}