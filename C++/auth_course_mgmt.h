#ifndef AUTH_COURSE_MGMT_H
#define AUTH_COURSE_MGMT_H

#define TABLE_SZ 100
#define CODE_LEN 20
#define NAME_LEN 100

typedef struct Course {
    char code[CODE_LEN];
    char name[NAME_LEN];
    struct Course* next;
} Course;

extern Course* courseTable[TABLE_SZ];

unsigned int hash(char* code);
void addCourse(char* code, char* name);
void removeCourse(char* code);
Course* findCourse(char* code);
void displayAllCourses();

#endif // AUTH_COURSE_MGMT_H
