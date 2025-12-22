/*Date: 2025/12/22
Author: 黃鈺翔
Description: Student Score Management System
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DB_FILENAME "db.dat"

struct student {
    int chineseScore;
    int englishScore;
    char name[60];
};
typedef struct student student;


FILE *fp; // file pointer
student tmpStudent; // temporary student record
student currentStudent; // current student record

void addRecord(FILE *fName, student *newRecord) {
    // Add new student record to the database
    fName = fopen(DB_FILENAME, "a+b"); // open file in append binary mode
    fwrite(newRecord, sizeof(student), 1, fName); // write new record to file
    fclose(fName); // close file
}

int findRecord(FILE *fName, student *newRecord) {
    // Find student record in the database
    int result = 0; // 0: not found, 1: found
    fName = fopen(DB_FILENAME, "rb"); // open file in read binary mode
    while(fread(&currentStudent, sizeof(student), 1, fName) == 1) {
        // Read each record
        if(strcmp(newRecord->name, currentStudent.name) == 0) {
            // compare names
            result = 1; // found
            break;
        }
    }
    fclose(fName); // close file
    return result; // return result
}

void modifyRecord(FILE *fName, student *updatedRecord) {
    // Modify existing student record in the database
    fName = fopen(DB_FILENAME, "r+b"); // open file in read and write binary mode
    while(fread(&currentStudent, sizeof(student), 1, fName) == 1) {
        // Read each record
        if(strcmp(updatedRecord->name, currentStudent.name) == 0) {
            // compare names
            fseek(fName, -(long long)sizeof(student), SEEK_CUR); // move file pointer back to the start of the record
            fwrite(updatedRecord, sizeof(student), 1, fName); // write updated record
            break;
        }
    }
    fclose(fName);   // close file
}

void deleteRecord(FILE *fName, student *deleteRecord) { 
    // Delete student record from the database   
    fName = fopen(DB_FILENAME, "rb"); // open file in read binary mode
    FILE *new_fp = fopen("temp.dat", "wb"); // open temporary file in write binary mode
    while(fread(&currentStudent, sizeof(student), 1, fName) == 1) { 
        // Read each record
        if(strcmp(deleteRecord->name, currentStudent.name) != 0) {
            // compare names
            fwrite(&currentStudent, sizeof(student), 1, new_fp); // write record to temporary file if not the one to delete
        }
    }
    fclose(fName); // close original file
    fclose(new_fp); // close temporary file
    remove(DB_FILENAME);  // delete original file
    rename("temp.dat", DB_FILENAME); // rename temporary file to original file name
}

student *printRecord(FILE *fName, char name[]) {
    // Print student record and return pointer to it
    fName = fopen(DB_FILENAME, "rb"); // open file in read binary mode
    while(fread(&currentStudent, sizeof(student), 1, fName) == 1) {
        // Read each record
        if(strcmp(name, currentStudent.name) == 0) {
            // compare names
            printf("學生姓名: %s\n", currentStudent.name);
            printf("國文成績: %d\n", currentStudent.chineseScore);
            printf("英文成績: %d\n", currentStudent.englishScore);
            break;
        }
    }
    fclose(fName); // close file
    return &currentStudent; // return pointer to current student
}

void ADD() {
    // ADD
    printf("\n新學生姓名: ");
    scanf("%s", &tmpStudent.name);
    printf("\n國文成績: ");
    scanf("%d", &tmpStudent.chineseScore);
    printf("\n英文成績: ");
    scanf("%d", &tmpStudent.englishScore);

    addRecord(fp, &tmpStudent); // add new record to database

    printf("輸入成功！\n");
}

void MODIFY() {
    // MODIFY
    printf("要修改哪一位學生的資料: ");
    scanf("%s", &tmpStudent.name);
    if(findRecord(fp, &tmpStudent) == 0) {
        // Not found
        printf("查無此人！\n");
        return;
    }

    printf("\n該生國文成績: ");
    scanf("%d", &tmpStudent.chineseScore);
    printf("\n該生英文成績: ");
    scanf("%d", &tmpStudent.englishScore);

    modifyRecord(fp, &tmpStudent); // modify record in database

    printf("修改成功！\n");
}

void DELETE() {
    // DELETE
    printf("要刪除哪一位學生的資料: ");
    scanf("%s", &tmpStudent.name);
    if(findRecord(fp, &tmpStudent) == 0) {
        // Not found
        printf("查無此人！\n");
        return;
    }
    student *sp = printRecord(fp, tmpStudent.name); // print record to be deleted
    printf("確認刪除？(Y/N): ");
    char confirm;
    scanf(" %c", &confirm);
    if(confirm == 'y' || confirm == 'Y') {
        // Confirmed
        deleteRecord(fp, sp); // delete record from database
        printf("成功刪除！\n");
    }
}

int cmpChinese(const void *a, const void *b) {
    // Compare function for qsort to sort by Chinese score
    student *stuA = (student *)a;
    student *stuB = (student *)b;
    return stuB->chineseScore - stuA->chineseScore;
}

int cmpEnglish(const void *a, const void *b) {
    // Compare function for qsort to sort by English score
    student *stuA = (student *)a;
    student *stuB = (student *)b;
    return stuB->englishScore - stuA->englishScore;
}

void printChineseScore(FILE *fName) {
    // Print Chinese scores in descending order
    fName = fopen(DB_FILENAME, "rb");
    student students[100]; // array to hold student records
    // read all records into array and count length
    int count = 0;
    while(fread(&students[count], sizeof(student), 1, fName) == 1) {
        count++;
    }

    qsort(students, count, sizeof(student), cmpChinese); // sort array by Chinese score

    printf("國文成績由大到小：\n");
    for(int i = 0; i < count; i++) {
        // print sorted records
        printf("%s %d\n", students[i].name, students[i].chineseScore);
    }
    fclose(fName); // close file
}

void printEnglishScore(FILE *fName) {
    // Print English scores in descending order
    fName = fopen(DB_FILENAME, "rb");
    student students[100]; // array to hold student records
    // read all records into array and count length
    int count = 0;
    while(fread(&students[count], sizeof(student), 1, fName) == 1) {
        count++;
    }

    qsort(students, count, sizeof(student), cmpEnglish); // sort array by English score
 
    printf("英文成績由大到小：\n");
    for(int i = 0; i < count; i++) {
        // print sorted records
        printf("%s %d\n", students[i].name, students[i].englishScore);
    }
    fclose(fName); // close file
}


int main() {
    int mode;
    while(1) {
        printf("請選擇功能: ");
        scanf("%d", &mode);
        // Call Action Based on User Input
        if (mode == 1) {
            ADD();
        } else if (mode == 2) {
            MODIFY();
        } else if (mode == 3) {
            DELETE();
        } else if (mode == 4) {
            printChineseScore(fp);
        } else if (mode == 5) {
            printEnglishScore(fp);
        } else if (mode == 0) {
            break;
        }
    }
    return 0;
}