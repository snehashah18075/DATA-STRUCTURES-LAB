#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100

// Book structure as node
typedef struct Book {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int isAvailable;
    struct Book* prev;
    struct Book* next;
} Book;

Book* head = NULL;
Book* tail = NULL;

// Create a new book node
Book* createBook(int id, const char* title, const char* author) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->isAvailable = 1;
    newBook->prev = newBook->next = NULL;
    return newBook;
}

// Add a book at the end
void addBook(int id, const char* title, const char* author) {
    Book* newBook = createBook(id, title, author);
    if (head == NULL) {
        head = tail = newBook;
    } else {
        tail->next = newBook;
        newBook->prev = tail;
        tail = newBook;
    }
    printf("Book added: %s\n", title);
}

// Delete a book by ID
void deleteBook(int id) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            if (temp->prev) temp->prev->next = temp->next;
            else head = temp->next;

            if (temp->next) temp->next->prev = temp->prev;
            else tail = temp->prev;

            printf("Book deleted: %s\n", temp->title);
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

// Search for a book by ID
void searchBook(int id) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book Found:\nID: %d\nTitle: %s\nAuthor: %s\nAvailability: %s\n",
                   temp->id, temp->title, temp->author,
                   temp->isAvailable ? "Available" : "Not Available");
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

// Check availability by ID
void checkAvailability(int id) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book %s is %s.\n", temp->title,
                   temp->isAvailable ? "available" : "not available");
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

// Display books forward
void displayForward() {
    Book* temp = head;
    printf("Library books (Forward Traversal):\n");
    while (temp != NULL) {
        printf("ID: %d, Title: %s, Author: %s, %s\n",
               temp->id, temp->title, temp->author,
               temp->isAvailable ? "Available" : "Not Available");
        temp = temp->next;
    }
}

// Display books backward
void displayBackward() {
    Book* temp = tail;
    printf("Library books (Backward Traversal):\n");
    while (temp != NULL) {
        printf("ID: %d, Title: %s, Author: %s, %s\n",
               temp->id, temp->title, temp->author,
               temp->isAvailable ? "Available" : "Not Available");
        temp = temp->prev;
    }
}

// Main function with menu
int main() {
    int choice, id;
    char title[MAX_TITLE], author[MAX_AUTHOR];

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n2. Delete Book\n3. Search Book\n4. Check Availability\n5. Display Forward\n6. Display Backward\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Book Title: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0; // remove newline
                printf("Enter Author Name: ");
                fgets(author, MAX_AUTHOR, stdin);
                author[strcspn(author, "\n")] = 0;
                addBook(id, title, author);
                break;
            case 2:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                searchBook(id);
                break;
            case 4:
                printf("Enter Book ID to check availability: ");
                scanf("%d", &id);
                checkAvailability(id);
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                printf("Exiting Library System.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
