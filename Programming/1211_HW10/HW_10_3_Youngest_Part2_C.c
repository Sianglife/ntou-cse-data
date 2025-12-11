/*Date: 2025/12/11
Author: 黃鈺翔
Description: Using struct to store person information, and find the youngest person
Using github copilot to write comments
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person {
    char name[20];
    char birthday[11]; // 紀錄方式: 月/日/年
};

typedef struct person Person;

int cmp(const void *a, const void *b) {
    Person *pa = (Person *)a;
    Person *pb = (Person *)b;

    // Read birthday into year, month, day
    int year_a, year_b, month_a, month_b, day_a, day_b;
    sscanf(pa->birthday, "%d/%d/%d", &month_a, &day_a, &year_a);
    sscanf(pb->birthday, "%d/%d/%d", &month_b, &day_b, &year_b);

    // Compare by year, then month, then day
    if (year_a != year_b) {
        return year_a - year_b;
    } else if (month_a != month_b) {
        return month_a - month_b;
    } else {
        return day_a - day_b;
    }
}

Person *findTheYoungestPerson(const Person **peopleData, int numberPeople) {
    Person *people = (Person *)peopleData;
    
    // Sort People by Birthday
    qsort(people, numberPeople, sizeof(Person), cmp);

    // Return the Youngest Person (Last in Sorted Order)
    return &people[numberPeople - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    Person people[n];
    
    // Input Person Data
    for (int i = 0; i < n; i++) {
        scanf("%s %s", people[i].name, people[i].birthday);
    }

    // Find the Youngest Person
    Person *youngest = findTheYoungestPerson((const Person **)people, n);

    // Output the Youngest Person
    char youngest_birthday[11];
    strcpy(youngest_birthday, youngest->birthday);
    for(int i = 0; i < n; i++) {
        if (strcmp(people[i].birthday, youngest_birthday) == 0) {
            printf("YoungestPerson Name: %s\n", people[i].name);
            printf("YoungestPerson birthday: %s\n", people[i].birthday);
        }
    }
    return 0;
}