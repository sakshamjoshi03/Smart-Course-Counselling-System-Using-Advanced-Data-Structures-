
#include "recommend_traverse.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
Node* adj[MAX_COURSES]; int indegree[MAX_COURSES];
char courseNames[MAX_COURSES][NAME_LEN]; int courseCount;
void initGraph(int n){ courseCount=n; for(int i=0;i<n;i++){adj[i]=NULL; indegree[i]=0;}}
void addEdge(int u,int v){
    Node* n=(Node*)malloc(sizeof(Node)); n->idx=v; n->next=adj[u]; adj[u]=n; indegree[v]++;
}
int getCourseIndexByName(const char* name){
    for(int i=0; i<courseCount; i++) if(strcmp(courseNames[i],name)==0) return i;
    return -1;
}
void recommendAllCourses(){
    int inDeg[MAX_COURSES]; for(int i=0;i<courseCount;i++) inDeg[i]=indegree[i];
    int queue[MAX_COURSES],f=0,r=0;
    for(int i=0;i<courseCount;i++) if(inDeg[i]==0) queue[r++]=i;
    printf("Recommended Course Order:\n");
    while(f<r){
        int u=queue[f++]; printf("- %s\n", courseNames[u]);
        Node* t=adj[u]; while(t){
            int v=t->idx; inDeg[v]--; if(inDeg[v]==0) queue[r++]=v; t=t->next;
        }
    }
}
void recommendNext(int idx){
    Node* t=adj[idx]; printf("Direct next courses after %s:\n",courseNames[idx]);
    while(t){ printf("  - %s\n", courseNames[t->idx]); t=t->next;}
}
