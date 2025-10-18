#include "interaction_seat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CourseLL* addCourseLL(CourseLL* head, int id, const char* name) {
    CourseLL *n = (CourseLL*)malloc(sizeof(CourseLL));
    if (!n) {
        printf("Memory allocation failed\n");
        return head;
    }
    n->id = id;
    strcpy(n->name, name);
    n->next = head;
    return n;
}

CourseLL* removeCourseLL(CourseLL* head, int id) {
    CourseLL *t = head, *p = NULL;

    while (t && t->id != id) {
        p = t;
        t = t->next;
    }

    if (!t) {
        // ID not found
        return head;
    }

    if (!p) {
        // Remove head node
        head = t->next;
    } else {
        // Remove node other than head
        p->next = t->next;
    }

    free(t);
    return head;
}

void displayCoursesLL(CourseLL* head) {
    while (head) {
        printf("ID: %d Name: %s\n", head->id, head->name);
        head = head->next;
    }
}

Queue* createQueue(int cap) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    q->sz = 0;
    q->cap = cap;
    return q;
}

void enqueue(Queue* q, int sid) {
    if (q->sz >= q->cap) {
        printf("Queue full - waitlist\n");
        return;
    }

    QueueNode *n = (QueueNode*)malloc(sizeof(QueueNode));
    if (!n) {
        printf("Memory allocation failed\n");
        return;
    }

    n->sid = sid;
    n->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }

    q->sz++;
}

int dequeue(Queue* q) {
    if (!q->front) {
        printf("Queue empty\n");
        return -1;
    }

    QueueNode *t = q->front;
    int id = t->sid;
    q->front = q->front->next;

    if (!q->front) {
        q->rear = NULL;
    }

    free(t);
    q->sz--;
    return id;
}

void displayQueue(Queue* q) {
    QueueNode *t = q->front;
    while (t) {
        printf("SID: %d\n", t->sid);
        t = t->next;
    }
}
