#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {

    int i = 0, ch;
    char name[32], buffer[64], last[] = "passed the challange!\n";

    printf("What's your name? ");
    
    while((ch = getchar()) != '\n') {
        name[i++] = ch;
        if(i == 31)
            break;
    }
    name[i] = '\0';

    strcpy(buffer, name);
    strcat(buffer, " ");
    strcat(buffer, last);

    i = 0;
    while(putchar(buffer[i++]));

    return(0);

}