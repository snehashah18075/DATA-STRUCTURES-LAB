#include<stdio.h>
#include<stdlib.h>
#include "GraphsAdjacencyListDirectedGraph.c" 

void main() {
	int x, op;
	int N,E,s,d,i,j;
	GNODE p,q;
	printf("Enter the number of vertices : ");
	scanf("%d",&N);
	printf("Enter the number of edges : ");
	scanf("%d",&E);
	for(i=1;i<=E;i++) {
		printf("Enter source : ");
		scanf("%d",&s);
		printf("Enter destination : ");
		scanf("%d",&d);
		q=(GNODE)malloc(sizeof(struct node));
		q->vertex=d;
		q->next=NULL;
		if(graph[s]==NULL)
			graph[s]=q;
		else {
			p=graph[s];
			while(p->next!=NULL)
				p=p->next;
			p->next=q;
		}
	}
	while(1) {
		printf("1.Insert vertex 2.Insert edge 3.Delete vertex 4.Delete edge 5.Print adjacency list 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	
					insertVertex(&N);
					break;
			case 2:
					insertEdge(&N);
					break;
			case 3: 
					deleteVertex(&N);
					break;
			case 4:
					deleteEdge(&N);
					break;
			case 5:
					print(&N);
					break;
			case 6:
					exit(0);
		}
	}
}
#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *next;
	int vertex;
};
typedef struct node *GNODE;
GNODE graph[20];

void print(int * N) {
	int i;
	GNODE temp;
	for (i=1; i<= *N; i++){
		if (graph[i] != NULL){
			printf("%d=>",i);
			temp = graph[i];
			while(temp != NULL){
				printf("%d\t", temp->vertex);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}
void insertVertex(int * N) {
	if(*N >= 20){
		printf("Maximum number of vertices reached.\n");
		return;
	}
	(*N)++;
	graph[*N] = NULL;
	printf("Vertex %d inserted.\n", *N);
	print(N);
}
void insertEdge(int *N) {
	int s, d;
	printf("Enter the source vertex of the edge : ");
	scanf("%d", &s);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d", &d);

	if(s < 1 || d < 1|| s > *N || d > *N){
		printf("Invalid vertices.\n");
		return;
	}
	GNODE newNode = (GNODE)malloc(sizeof(struct node));
	newNode->vertex = d;
	newNode->next = NULL;

	if(graph[s] == NULL){
		graph[s] = newNode;
	}else{
		GNODE temp = graph[s];
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}

	printf("After inserting edge the adjacency list is : \n");
	print(N);
}
void deleteVertex(int *N) {
	int v, i;
	printf("Enter the vertex to be deleted : ");
	scanf("%d", &v);

	if (v < 1|| v > *N){
		printf("Invalid vertex.\n");
		return;
	}
	GNODE temp = graph[v], next;
	while(temp != NULL){
		next = temp->next;
		free(temp);
		temp = next;
	}
	graph[v] = NULL;
	for(i=1; i<=*N; i++){
		if (i==v) continue;
		GNODE curr = graph[i], prev = NULL;
		while(curr != NULL){
			if(curr->vertex == v){
				if(prev == NULL){
					graph[i] = curr->next;
				}else{
					prev->next = curr->next;
				}
				free(curr);
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}

	printf("After deleting vertex the adjacency list is : \n");
	print(N);
}
void deleteEdge(int *N) {
	int s, d;
	printf("Enter the source vertex of the edge : ");
	scanf("%d", &s);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d", &d);

	if(s < 1|| d < 1 || s > *N || d > *N){
		printf("Invalid vertices.\n");
		return;
	}

	GNODE curr = graph[s], prev = NULL;
	while(curr != NULL){
		if(curr->vertex == d){
			if(prev == NULL){
				graph[s] = curr->next;
			}else{
				prev->next = curr->next;
			}
			free(curr);
			printf("After deleting edge the adjacency list is : \n");
			print(N);
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	printf("Edge not found.\n");
}
