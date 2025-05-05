#include <stdio.h>
#include <stdlib.h>
#define MAX 99
#include <stdbool.h>

struct node{
int vertex;
struct node* next;
};
typedef struct node* GNODE;

GNODE graph[MAX];

int visited[MAX];

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty(){
	return front == -1;
}
void enqueue(int vertex){
	if(rear == MAX - 1){
		printf("Queue is full\n");
	}else{
		if(front == -1){
			front = 0;
		}
		queue[++rear] = vertex;
	}
}
int dequeue(){
	if(isEmpty()){
		printf("Queue is empty\n");
		return -1;
	}else{
		int dequeued = queue[front];
		if(front == rear){
			front = rear = -1;
		}else{
			front++;
		}
		return dequeued;
	}
}
void BFS(int start){
	visited[start] = 1;
	enqueue(start);

	while(!isEmpty()){
		int curr = dequeue();
		printf("\n");
		printf("%d",curr);

		GNODE temp = graph[curr];
		while(temp != NULL){
			int adj = temp->vertex;
			if(!visited[adj]){
				visited[adj] = 1;
				enqueue(adj);
			}
			temp = temp->next;
		}
	}
}
void main() {
	int n, E, s, d, i, j, v;
	GNODE p, q;
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	printf("Enter no of edges: ");
	scanf("%d",&E);
	for(i=1;i<=E;i++) {
		printf("Enter source: ");
		scanf("%d",&s);
		printf("Enter destination: ");
		scanf("%d",&d);
		q=(GNODE)malloc(sizeof(struct node));
		q->vertex=d;
		q->next=NULL;
		if(graph[s]==NULL) {
			graph[s]=q;
		} else {
			p=graph[s];
			while(p->next!=NULL)
				p=p->next;
			p->next=q;
		}
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("Enter Start Vertex for BFS: ");
	scanf("%d", &v);
	printf("BFS of graph: ");
	BFS(v);
	printf("\n");
}
