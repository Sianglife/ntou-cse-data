/*Date: 2025/12/11
Author: 黃鈺翔
Description: Using struct to store member and book information
Using github copilot to write comments
*/
#include<stdio.h>

int main() {
    struct books {
        /* 借用 book 資料 */
        char no[8]; /* 編號 */
        char name[40]; /* 名稱 */
        char rentdate[11]; /* 租出日期 */
        char returndate[11]; /* 歸還日期 */ 
    };
    struct member {
        char name[16];
        char phone[11];
        struct books ebook;
    } Ethan = {"Ethan", "0965022177", "EB10001", "復仇者聯盟4", "2022/11/17", "2022/12/17"};

    printf("Name: %s\n", Ethan.name); // 使用 struct 成員，用.運算子存取
    printf("Phone: %s\n", Ethan.phone);
    printf("Book No.: %s\n", Ethan.ebook.no);
    printf("Book Name: %s\n", Ethan.ebook.name);
    printf("Rent Date: %s\n", Ethan.ebook.rentdate);
    printf("Return Date: %s\n", Ethan.ebook.returndate);
    return 0;
}