#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    int choice = 1;
    while (choice) {
        struct Node *newnode;

        newnode = (struct Node *)malloc(sizeof(struct Node));

        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter data for the new node: ");
        scanf("%d", &newnode->data);

        newnode->next = head;
        head = newnode;

        printf("\nDo you want to insert more (0/1): ");
        scanf("%d", &choice);
    }
}
void bi() {
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    printf("Enter data : ");
    scanf("%d", &newnode->data);

    newnode->next = head;  
    head = newnode;        
}


void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void li() {
    struct Node *temp, *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void si() {
    int loc;
    int i = 1;
    struct Node *temp, *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    printf("Enter location: ");
    scanf("%d", &loc);

    temp = head;

    if (loc == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        while (temp != NULL && i < loc - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Invalid location\n");
            free(newnode);
        } else {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void search() {
    struct Node *temp;
    temp = head;

    printf("Search: ");
    int s, i;
    i = 0;
    scanf("%d", &s);
    fflush(stdin);

    while (temp != NULL) {
        if (temp->data == s) {
            printf("%d is present at %d\n", s, i);
            return;
        }
        temp = temp->next;  // Move to the next node in the linked list
        i++;
    }

    printf("%d is not present in the list\n", s);
}


int main() {
    int choice = 0;

    while (choice != 7) {
        printf("\n1. Create\n2. Beginning Insert\n3. Ending Insert\n4. Display\n5. Search\n6. Specific Insert\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                bi();
                break;
            case 3:
                li();
                break;
            case 4:
                display();
                break;
            case 5:
                search();
                break;
            case 6:
                si(); 
                break;
            case 7:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
