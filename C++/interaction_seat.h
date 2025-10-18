// interaction_seat.h
#define MAX_NAME 50
typedef struct CourseLL { int id; char name[MAX_NAME]; struct CourseLL* next; } CourseLL;
typedef struct QueueNode { int sid; struct QueueNode* next; } QueueNode;
typedef struct Queue { QueueNode* front,*rear; int sz,cap; } Queue;
CourseLL* addCourseLL(CourseLL* head,int id,const char* name);
CourseLL* removeCourseLL(CourseLL* head,int id);
void displayCoursesLL(CourseLL* head);
Queue* createQueue(int cap);
void enqueue(Queue* q,int sid);
int dequeue(Queue* q);
void displayQueue(Queue* q);
