/*
 * To perform bitwise operation on strings containing binary values as absolute values.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

int main() {
    int size1 = 0, size2 = 0, size3 = 0;
    int i, j, k;
    char* str1 = (char*)malloc(MAX_SIZE * sizeof(char));
    char* str2 = (char*)malloc(MAX_SIZE * sizeof(char));
    char* str3 = (char*)malloc(MAX_SIZE * sizeof(char));
    printf("Enter binary string 1: ");
    scanf(" %s", str1);
    printf("Enter binary string 2: ");
    scanf(" %s", str2);

    while(str1[size1++]);
    while(str2[size2++]);

    size3 = size1;
    size3 = size1 > size2 ? size1 : size2;

    for(i = 0; str1[i] != '\0'; i++)
        str1 -= 48;
    for(i = 0; str2[i] != '\0'; i++)
        str2 -= 48;
    
    for(k = 0; str1[k] != '\0' && str2[k] != '\0'; k++) {
        str3[k] = str1[k] & str2[k];
    }

    if(k + 1 == size1)
        while(k < size2)
            str3[k++] = 0;
    else if(k + 1 == size2)
        while(k < size1)
            str3[k++] = 0;
    return 0;
}