/*Date: 2025/12/22
Author: 黃鈺翔
Description: Student Score Management System
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DB_FILENAME "db.dat"

// TODO: Test, comments

struct student {
    int chineseScore;
    int englishScore;
    char name[60];
};
typedef struct student student;


FILE *fp;
student tmpStudent;
student currentStudent;

void addRecord(FILE *fName, student *newRecord) {
    fName = fopen(DB_FILENAME, "a+b");
    fwrite(newRecord, sizeof(student), 1, fName);
    fclose(fName);
}

int findRecord(FILE *fName, student *newRecord) {
    int result = 0;
    fName = fopen(DB_FILENAME, "rb");
    while(fread(&currentStudent, sizeof(student), 1, fName) == 1) {
        if(strcmp(newRecord->name, currentStudent.name) == 0) {
            result = 1;
            break;
        }
    }
    fclose(fName);
    return result;
}

void modifyRecord(FILE *fName, student *updatedRecord) {
    fName = fopen(DB_FILENAME, "r+b");
    while(fread(&currentStudent, sizeof(student), 1, fName) == 1) {
        if(strcmp(updatedRecord->name, currentStudent.name) == 0) {
            fseek(fName, -(long long)sizeof(student), SEEK_CUR);
            fwrite(updatedRecord, sizeof(student), 1, fName);
            break;
        }
    }
    fclose(fName);  
}

void deleteRecord(FILE *fName, student *deleteRecord) {    
    fName = fopen(DB_FILENAME, "rb");
    FILE *new_fp = fopen("temp.dat", "ab");
    while(fread(&currentStudent, sizeof(student), 1, fName) == 1) {
        if(strcmp(deleteRecord->name, currentStudent.name) != 0) {
            fwrite(&currentStudent, sizeof(student), 1, fName);
        }
    }
    fclose(fName);
    fclose(new_fp);
    remove(DB_FILENAME);
    rename("temp.dat", DB_FILENAME);
}

student *printRecord(FILE *fName, char name[]) {
    fName = fopen(DB_FILENAME, "rb");
    while(fread(&currentStudent, sizeof(student), 1, fName) == 1) {
        if(strcmp(name, currentStudent.name) == 0) {
            printf("學生姓名: %s\n", currentStudent.name);
            printf("國文成績: %d\n", currentStudent.chineseScore);
            printf("英文成績: %d\n", currentStudent.englishScore);
            break;
        }
    }
    fclose(fName);
    return &currentStudent;
}

void ADD() {
    // ADD
    printf("\n新學生姓名: ");
    scanf("%s", &tmpStudent.name);
    printf("\n國文成績: ");
    scanf("%d", &tmpStudent.chineseScore);
    printf("\n英文成績: ");
    scanf("%d", &tmpStudent.englishScore);

    addRecord(fp, &tmpStudent);

    printf("輸入成功！\n");
}

void MODIFY() {
    // MODIFY
    printf("要修改哪一位學生的資料: ");
    scanf("%s", &tmpStudent.name);
    if(findRecord(fp, &tmpStudent) == 0) {
        // 
        printf("查無此人！\n");
        return;
    }

    printf("\n該生國文成績: ");
    scanf("%d", &tmpStudent.chineseScore);
    printf("\n該生英文成績: ");
    scanf("%d", &tmpStudent.englishScore);

    modifyRecord(fp, &tmpStudent);

    printf("修改成功！\n");
}

void DELETE() {
    // DELETE
    printf("要刪除哪一位學生的資料: ");
    scanf("%s", &tmpStudent.name);
    if(findRecord(fp, &tmpStudent) == 0) {
        // 
        printf("查無此人！\n");
        return;
    }
    student *sp = printRecord(fp, tmpStudent.name);
    printf("確認刪除？(Y/N): ");
    char confirm;
    scanf("%c", &confirm);
    if(confirm == 'y' || confirm == 'Y') {
        deleteRecord(fp, sp);
        printf("成功刪除！\n");
    }
}

int cmpChinese(const void *a, const void *b) {
    student *stuA = (student *)a;
    student *stuB = (student *)b;
    return stuA->chineseScore - stuB->chineseScore;
}

int cmpEnglish(const void *a, const void *b) {
    student *stuA = (student *)a;
    student *stuB = (student *)b;
    return stuA->englishScore - stuB->englishScore;
}

void printChineseScore(FILE *fName) {
    fName = fopen(DB_FILENAME, "rb");
    student students[100];
    int count = 0;
    while(fread(&students[count], sizeof(student), 1, fName) == 1) {
        count++;
    }

    qsort(students, count, sizeof(student), cmpChinese);

    printf("國文成績由大到小：\n");
    for(int i = 0; i < count; i++) {
        printf("%s %d\n", students[i].name, students[i].chineseScore);
    }
}

void printEnglishScore(FILE *fName) {
    fName = fopen(DB_FILENAME, "rb");
    student students[100];
    int count = 0;
    while(fread(&students[count], sizeof(student), 1, fName) == 1) {
        count++;
    }

    qsort(students, count, sizeof(student), cmpEnglish);

    printf("英文成績由大到小：\n");
    for(int i = 0; i < count; i++) {
        printf("%s %d\n", students[i].name, students[i].englishScore);
    }
}


int main() {
    int mode;
    while(1) {
        printf("請選擇功能: ");
        scanf("%d", &mode);
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