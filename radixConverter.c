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
        printf("0");
    }
    else {
        struct elementStack* temp = NULL;
        while(topStack) {
            printf("%c", topStack -> val);
            temp = topStack;
            topStack = topStack -> prev;
            free(temp);
        }
        topStack = NULL; //Reset topStack to NULL to signify an empty stack
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
            printf("%c", firstQueue -> val);
            temp = firstQueue;
            firstQueue = firstQueue -> next;
            free(temp);
        }
        firstQueue = lastQueue = NULL;
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

void decToBase_beforeRadixPoint(float no, int toBase) {
    //what to add to 'raw' digit to make it a visible 'char' variable = charOffset
    int charOffset;

    if(no == 0) {
        pushStack(48);
        popStackAll();
        return;
    }
    
    int copy = no;

    //stack comes into play
    while(copy) {
        // copy % ... will be greater than 9 only when toBase is 16, so no need for a condition check
        (copy % toBase > 9) ? (charOffset = 55) : (charOffset = 48);
        pushStack((copy % toBase) + charOffset);
        copy /= toBase;
    }
    return;
}

float fractionalPart(float x) {
    int integer = x;
    return (x - integer);
}

void decToBase_afterRadixPoint(float no, int toBase) {
    //to what degree of precision we need the result e.g. 0.1001 is a result till 4 degrees of precision
    int precisionRequired = 8;
    int precisionReached = 1;

    float frPt = fractionalPart(no);
    int charOffset;

    if(frPt == 0) {
        enQueue(48);
        return;
    }

    while((frPt != 0) && (precisionReached <= precisionRequired)) {
        ((int)(frPt * toBase) > 9) ? (charOffset = 55) : (charOffset = 48);
        enQueue(((int)(frPt = frPt * toBase)) + charOffset);
        frPt = fractionalPart(frPt);
        precisionReached++;
    }
    return;
}

//we can make it more abstract by introducing 'base' variable and performing all operations on 'base' instead of absolute values.
void decToBase(int toBase) {
    float no;
    printf("Enter base-10 number: ");
    scanf("%f", &no);

    printf("%f in base-%d is: ", no, toBase);
    decToBase_beforeRadixPoint(no, toBase);
    popStackAll();
    printf(".");
    decToBase_afterRadixPoint(no, toBase);
    deQueueAll();
    printf("\n");

    return;
}

int main() {
    decToBase(16);
    return 0;
}