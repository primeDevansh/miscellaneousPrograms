#include <stdio.h>
#include <stdlib.h>

void spellOnesDigit(char ch) {
    switch(ch) {
        case '1':
            printf("one ");
            break;
        case '2':
            printf("two ");
            break;
        case '3':
            printf("three ");
            break;
        case '4':
            printf("four ");
            break;
        case '5':
            printf("five ");
            break;
        case '6':
            printf("six ");
            break;
        case '7':
            printf("seven ");
            break;
        case '8':
            printf("eight ");
            break;
        case '9':
            printf("nine ");
            break;
    }
    return;
}

void spellTensDigit(char ch) {
    switch(ch) {
        case '1':
            printf("ten ");
            break;
        case '2':
            printf("twenty ");
            break;
        case '3':
            printf("thirty ");
            break;
        case '4':
            printf("forty ");
            break;
        case '5':
            printf("fifty ");
            break;
        case '6':
            printf("sixty ");
            break;
        case '7':
            printf("seventy ");
            break;
        case '8':
            printf("eighty ");
            break;
        case '9':
            printf("ninety ");
            break;
    }
    return;
}

void spellEleven(char ch) {
    switch(ch) {
        case '1':
            printf("eleven ");
            break;
        case '2':
            printf("twelve ");
            break;
        case '3':
            printf("thirteen ");
            break;
        case '4':
            printf("fourteen ");
            break;
        case '5':
            printf("fifteen ");
            break;
        case '6':
            printf("sixteen ");
            break;
        case '7':
            printf("seventeen ");
            break;
        case '8':
            printf("eighteen ");
            break;
        case '9':
            printf("nineteen ");
            break;
    }
    return;
}

void NoToWo(int no) {
    if(no > 999999999) {
        printf("Number out of Range! Cannot Convert!\n");
        return;
    }
    if(no == 0) {
        printf("zero ");
        return;
    }
    char str[16], temp;
    int i = 0, j = 0, k = 0;
    int strSize = 0;

    if(no < 0) {
        no *= -1;
        printf("minus ");
    }
    // str[i++] = '-';
    while(no) {
        str[i++] = (no % 10) + 48;
        no /= 10;
    }
    str[i] = '\0';
    strSize = i;

    //reverse the string to get actual number
    for(j = i - 1, k = 0; k <= j; j--, k++) {
        temp = str[k];
        str[k] = str[j];
        str[j] = temp;
    }

    for(i = 0; str[i] != '\0'; i++) {
        j = strSize - i; //j is the face value
        switch(j) {
            case 1:
                spellOnesDigit(str[i]);
                break;
            case 2:
            //48 is the ASCII value of 0; str > 48 => str > '0'
                if(str[i] == '1' && str[i + 1] > 48) {
                    spellEleven(str[++i]);
                    continue;
                }
                spellTensDigit(str[i]);
                break;
            case 3:
                spellOnesDigit(str[i]);
                printf("hundred ");
                break;
            case 4:
                spellOnesDigit(str[i]);
                printf("thousand ");
                break;
            case 5:
                if(str[i] == '1' && str[i + 1] > 48) {
                    spellEleven(str[++i]);
                    printf("thousand ");
                    continue;
                }
                spellTensDigit(str[i]);
                spellOnesDigit(str[++i]);
                printf("thousand ");
                break;
            case 6:
                spellOnesDigit(str[i]);
                printf("lakh ");
                break;
            case 7:
                if(str[i] == '1' && str[i + 1] > 48) {
                    spellEleven(str[++i]);
                    printf("lakh ");
                    continue;
                }
                spellTensDigit(str[i]);
                spellOnesDigit(str[++i]);
                printf("lakh ");
                break;
            case 8:
                spellOnesDigit(str[i]);
                printf("crore ");
                break;
            case 9:
                if(str[i] == '1' && str[i + 1] > 48) {
                    spellEleven(str[++i]);
                    printf("crore ");
                    continue;
                }
                spellTensDigit(str[i]);
                spellOnesDigit(str[++i]);
                printf("crore ");
                break;
            default: 
                continue;
        }
    }
    return;
}

int main() {
    int no;
    printf("Enter a number: ");
    scanf(" %d", &no);

    printf("%d in words is: ", no);
    NoToWo(no);
    printf("\n");
    return 0;
}