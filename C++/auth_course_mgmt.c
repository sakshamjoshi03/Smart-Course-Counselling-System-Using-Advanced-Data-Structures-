#include "auth_course_mgmt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Course* courseTable[TABLE_SZ]={NULL};
unsigned int hash(char* code){
    unsigned int sum=0; for(int i=0; code[i]!='\0'; i++) sum+=code[i];
    return sum%TABLE_SZ;
}
void addCourse(char* code, char* name){
    unsigned int index=hash(code);
    Course* newCourse=(Course*)malloc(sizeof(Course));
    strcpy(newCourse->code, code); strcpy(newCourse->name, name);
    newCourse->next=courseTable[index]; courseTable[index]=newCourse;
}
void removeCourse(char* code){
    unsigned int index=hash(code);
    Course *temp=courseTable[index], *prev=NULL;
    while(temp){
        if(strcmp(temp->code, code)==0){
            if(prev==NULL) courseTable[index]=temp->next;
            else prev->next=temp->next;
            free(temp); return;
        }
        prev=temp; temp=temp->next;
    }
}
Course* findCourse(char* code){
    unsigned int index=hash(code); Course* temp=courseTable[index];
    while(temp){ if(strcmp(temp->code,code)==0) return temp; temp=temp->next;}
    return NULL;
}
void displayAllCourses(){
    for(int i=0;i<TABLE_SZ;i++){
        for(Course* temp=courseTable[i];temp;temp=temp->next)
            printf("Code: %s, Name: %s\n", temp->code, temp->name);
    }
}
