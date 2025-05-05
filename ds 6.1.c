#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
void insert(int n){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = n;
	new_node->next = NULL;

	if(head == NULL){
		new_node->prev = NULL;
		head = tail = new_node;
	}else{
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}
}
void remov(int n){
	struct Node* temp = head;
	while(temp != NULL){
		if(temp->data == n){
			if(temp->prev != NULL){
				temp->prev->next = temp->next;
			}else{
				head = temp->next;
			}
			if(temp->next != NULL){
				temp->next->prev = temp->prev;
			}else{
				tail = temp->prev;
			}
			free(temp);
			return;
		}
		temp = temp->next;
	}
	printf("%d not found\n",n);
}
void display(){
	struct Node* temp = head;
	if(temp == NULL){
		printf("List is empty\n");
		return;
	}
	while(temp != NULL){
		printf("%d\t", temp->data);
		if(temp->next != NULL){
		}
		temp = temp->next;
	}
	printf("\n");
}
void reverse(){
	struct Node* temp = NULL;
	struct Node* current = head;

	while(current != NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if(temp != NULL){
		tail = head;
		head = temp->prev;
	}
}
int main() {
    int n, ch;
    do {
        printf("Operations on doubly linked list\n");
        printf("1.Insert\n2.Remove\n3.Display\n4.Reverse\n0.Exit\n");
        printf("Enter Choice 0-4: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &n);
                remov(n);
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                printf("List reversed\n");
                break;
        }
    } while (ch != 0);
    return 0;
}
