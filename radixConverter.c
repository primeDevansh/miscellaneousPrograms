#include <stdio.h>
#include <stdlib.h> //for malloc()

//stack's element
//stack for entered number's whole part
//read the following as 'element of stack'
struct elementStack {
    char val;
    struct elementStack* prev;
};

//topStack impplies top of stack
struct elementStack* topStack = NULL;

void pushStack(char ch) {
    struct elementStack* temp = (struct elementStack*)malloc(sizeof(struct elementStack));
    if (temp == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    temp -> val = ch;
    temp -> prev = topStack;
    topStack = temp;
    return;
}

void popStackAll() {
    if(topStack == NULL) {
        printf("Stack empty! - Underflow");
    }
    else {
        struct elementStack* temp = NULL;
        while(topStack) {
            printf("%c ", topStack -> val);
            temp = topStack;
            topStack = topStack -> prev;
            free(temp);
        }
        printf("\n");
    }
    return;
}

//queue's element
//queue for entered number's fractional part
//read the following as 'element of queue'
struct elementQueue {
    char val;
    struct elementQueue* next;
};

//firstQueue implies first element of queue and similar stuff can be inferred for lastQueue
struct elementQueue* firstQueue = NULL;
struct elementQueue* lastQueue = NULL;

void enQueue(char ch) {
    struct elementQueue* temp = (struct elementQueue*)malloc(sizeof(struct elementQueue));
    if (temp == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    temp -> val = ch;
    temp -> next = NULL;

    if (firstQueue == NULL) {
        firstQueue = temp;
        lastQueue = temp;
    } 
    else {
        lastQueue -> next = temp;
        lastQueue = temp;
    }
    return;
}

void deQueueAll() {
    if(firstQueue == NULL) {
        printf("Queue empty!");
    }
    else {
        struct elementQueue* temp = firstQueue;
        while(firstQueue) {
            printf("%c ", firstQueue -> val);
            temp = firstQueue;
            firstQueue = firstQueue -> next;
            free(temp);
        }
        printf("\n");
    }
    return;
}

//testing functions

void testStack() {
    printf("Stack Elements: - \n");
    for(int i = 0; i < 10; i++) {
        printf("Add %c to Stack.\n", i + 65);
        pushStack(i + 65);
    }
    printf("\nPerforming Pop Stack (FILO): - \n");
    popStackAll();
    printf("\n");
    return;
}

void testQueue() {
    printf("Queue Elements: - \n");
    for(int i = 0; i < 10; i++) {
        printf("Add %c to Queue.\n", i + 65);
        enQueue(i + 65);
    }
    printf("\nPerforming DeQueue (FIFO): - \n");
    deQueueAll();
    printf("\n");
    return;
}

int main() {
    testStack();
    testQueue();
    return 0;
}