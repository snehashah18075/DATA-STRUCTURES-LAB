#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	newNode -> next = newNode;
	return newNode;
}
struct Node* 
insertAtPositionInCLL(struct Node* first, int position, int data){
	struct Node* newNode = createNode(data);
	if(first == NULL){
		return newNode;
	}
	if(position == 1){
		struct Node* temp = first;
		while(temp -> next != first){
			temp = temp -> next;
		}
		temp -> next = newNode;
		newNode -> next = first;
		return newNode;
	}
	struct Node* current = first;
	int index = 1;
	while(current -> next != first && index < position - 1){
		current = current -> next;
		index++;
	}
	if(current->next == first && position != index + 1){
		printf("Position not found\n");
		free(newNode);
		return first;
	}
	newNode->next = current -> next;
	current->next = newNode;
	return first;
}
struct Node* deleteAtPositionInCLL(struct Node* first, int position){
	if(first == NULL){
		printf("CLL is empty\n");
		return first;
	}
struct Node* current = first;
struct Node* prev = NULL;
if(position == 1){
	if(current->next == first){
		printf("Deleted element: %d\n", current -> data);
		free(first);
		return NULL;
	}
	while(current->next != first){
		current = current->next;
	}
	printf("Deleted element: %d\n", first->data);
	current->next = first->next;
	free(first);
	return current->next;
}
	int index = 1;
	while(current -> next != first && index <position){
		prev = current;
		current = current->next;
		index++;
	}
	if(current == first || index <position){
	printf("Position not found\n");
	return first;
	}
	prev -> next = current -> next;
	printf("Deleted element: %d\n", current -> data);
	free(current);
	return first;
}
void traverseListInCLL(struct Node* first){
	if(first == NULL){
		printf("CLL is empty\n");
		return;
	}
	struct Node* current = first;
	do{
		printf("%d --> ", current -> data);
		current = current -> next;
	}while(current != first);
	printf("\n");
	}
struct Node* reverseCLL(struct Node* first){
	if(first == NULL){
		printf("CLL is empty\n");
		return first;
	}
	struct Node* prev = NULL;
	struct Node* current = first;
	struct Node* nextNode = NULL;
	do{
		nextNode = current -> next;
		current -> next = prev;
		prev = current;
		current = nextNode;
	}while(current != first);
	first -> next = prev;
	return prev;
}
int main(){
	struct Node* first = NULL;
	int x, pos, op;
	while(1){
		printf("1.Insert 2.Delete 3.Display 4.Reverse 5.Exit\n");
		printf("choice: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Position: ");
			scanf("%d",&pos);
			if(pos<=0){
				printf("Position not found\n");
			}else{
				printf("Element: ");
				scanf("%d",&x);
				first = insertAtPositionInCLL(first,pos,x);
			}
			break;
			case 2:
				if(first == NULL){
					printf("CLL is empty\n");
				}else{
					printf("Position: ");
					scanf("%d",&pos);
					first = deleteAtPositionInCLL(first, pos);
				}
			break;
			case 3:
			if(first == NULL){
				printf("CLL is empty\n");
			}else{
				printf("Elements in CLL are: ");
				traverseListInCLL(first);
			}
			break;
			case 4:
				if(first == NULL){
					printf("CLL is empty\n");
				}else{
					first = reverseCLL(first);
					printf("CLL reversed\n");
				}
			break;
			case 5:
			exit(0);
			break;
			default:
			printf("Invalid choice\n");
		}
	}
	return 0;
}
void main() {
    NODE first = NULL;
    int x, pos, op;
    while (1) {
        printf("1.Insert 2.Delete 3.Display 4.Reverse 5.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 2:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                }
                break;
            case 5:
                exit(0);
        }
    }
}
