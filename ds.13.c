// write a program to add two polynomial using linked list demonstrating the application of linked list, structure to represent and manipulate polynomial expressions

#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int expo;
    struct Term* next;
};

struct Term* createTerm(int coeff, int expo) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->expo = expo;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Term** poly, int coeff, int expo) {
    struct Term* newTerm = createTerm(coeff, expo);
    if (*poly == NULL || (*poly)->expo < expo) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        struct Term* temp = *poly;
        struct Term* prev = NULL;
        while (temp && temp->expo > expo) {
            prev = temp;
            temp = temp->next;
        }
        if (temp && temp->expo == expo) {
            temp->coeff += coeff;
            free(newTerm);
        } else {
            newTerm->next = temp;
            if (prev)
                prev->next = newTerm;
        }
    }
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    while (poly1 && poly2) {
        if (poly1->expo == poly2->expo) {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->expo > poly2->expo) {
            insertTerm(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        }
    }
    while (poly1) {
        insertTerm(&result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }
    while (poly2) {
        insertTerm(&result, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }
    return result;
}

void displayPolynomial(struct Term* poly) {
    struct Term* temp = poly;
    while (temp) {
        if (temp->coeff != 0) {
            printf("%dx^%d", temp->coeff, temp->expo);
            if (temp->next && temp->next->coeff >= 0)
                printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* sum = NULL;
    int n, coeff, expo;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &expo);
        insertTerm(&poly1, coeff, expo);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &expo);
        insertTerm(&poly2, coeff, expo);
    }

    sum = addPolynomials(poly1, poly2);

    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    printf("Sum of Polynomials: ");
    displayPolynomial(sum);

    return 0;
}
