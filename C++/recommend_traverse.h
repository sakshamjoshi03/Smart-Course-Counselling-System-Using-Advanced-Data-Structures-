#define MAX_COURSES 100
#define NAME_LEN 100
typedef struct Node { int idx; struct Node* next; } Node;
extern Node* adj[MAX_COURSES];
extern int indegree[MAX_COURSES];
extern char courseNames[MAX_COURSES][NAME_LEN];
extern int courseCount;
void initGraph(int n);
void addEdge(int u, int v);
void recommendAllCourses();
void recommendNext(int idx);
int getCourseIndexByName(const char* name);
