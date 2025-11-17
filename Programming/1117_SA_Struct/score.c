#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[50];
    float score;
} Student;

void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    Student* studentA = a;
    Student* studentB = b;
    if (studentA->score < studentB->score) return 1;
    else if (studentA->score > studentB->score) return -1;
    else return 0;
}

void sortByScore(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

void printAverage(Student students[], int n) {
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        total += students[i].score;
    }
    printf("\n平均分數：%.2f\n", total / n);
}

void printAll(Student students[], int n) {
    printf("\n學生資料列表：\n");
    for (int i = 0; i < n; i++) {
        printf("%s %.2f\n", students[i].name, students[i].score);
    }
}

void printFailed(Student students[], int n) {
    printf("\n不及格學生：\n");
    for (int i = 0; i < n; i++) {
        if (students[i].score < 60.0) {
            printf("%s %.2f\n", students[i].name, students[i].score);
        }
    }
}

void findTopStudent(Student students[], int n) {
    Student* topStudent = &students[0];
    for (int i = 0; i < n; i++) {
        if (students[i].score > topStudent->score) {
            topStudent = &students[i];
        }   
    }
    printf("最高分學生：\n%s %.2f\n", topStudent->name, topStudent->score);
}

int addStudent(Student students[], int n) {
    printf("\n是否要新增學生？(y/n)：\n");
    char choice;
    char name[50];
    float score;
    scanf(" %c", &choice);
    if (choice == 'y') {
        printf("輸入姓名：");
        scanf("%s", &name);
        printf("輸入分數：");
        scanf("%f", &score);

        students = realloc(students, (n + 1) * sizeof(Student));
        students[n].score = score;
        strcpy(students[n].name, name);
        
        printf("新增成功 目前資料如下：\n");
        printAll(students, n + 1);
        return n + 1;
    }
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    
    Student *students = malloc(n * sizeof(Student));
    for(int i = 0; i < n; i++) {
        scanf("%s", &students[i].name);
        scanf("%f", &students[i].score);
    }

    printAll(students, n);
    findTopStudent(students, n);
    printAverage(students, n);
    printFailed(students, n);
    n = addStudent(students, n);
    // sortByScore(students, n);
    qsort(students, n, sizeof(Student), compare);
    printf("\n重新排序後：\n");
    printAll(students, n);

    free(students);
    return 0;
}


/*
5
Amy
88
Bob
59
Clark
100
Dora
45
Eason
61
*/