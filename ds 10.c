#include<stdio.h>
#include<conio.h>
#define MAX 20
int cost[MAX][MAX], n, e, i, j, s, d, w;
void prims() {
	int visited[MAX] = {0};
	int edge_count = 0;
	int min, a = -1, b = -1;
	int total_cost = 0;
	visited[1] = 1;
	while(edge_count < n-1){
		min = 999;
	for(i=1; i<=n; i++){
		if(visited[i]){
			for(j=1; j<=n; j++){
				if(!visited[j] && cost[i][j] < min){
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}
	}
		if(a != -1 && b != -1){
			printf("Edge cost from %d to %d : %d\n",a, b, cost[a][b]);
		total_cost += cost[a][b];
		visited[b] =1;
		edge_count++;
		cost[a][b] = cost[b][a] = 999;
	}else{
		break;
		}
		a = b = -1;
	}
	printf("Minimum cost of spanning tree = %d\n", total_cost );
}
void main() {
	printf("Enter the number of vertices : ");
	scanf("%d", &n);
	printf("Enter the number of edges : ");
	scanf("%d", &e);
	for(i=1; i<=e; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s <= 0 || d <= 0 || s > n || d > n || w < 0 ) {
			printf("Invalid data.Try again.\n");
			i--;
			continue;
		}
		cost[s][d] = w;
		cost[d][s] = w;
	}
	for(i=1; i <= n; i++) {
	    for(j=1; j<=n; j++) {
			if(cost[i][j] == 0)
			    cost[i][j] = 999;
	    }
	}
	printf("The edges of Minimum Cost Spanning Tree are : \n");
	prims();
}
