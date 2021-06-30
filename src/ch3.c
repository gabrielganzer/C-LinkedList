#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE_ARRAY  10
#define SIZE_BUFFER 32

int main(int argc, char *argv[]) {

    char *array[SIZE_ARRAY], buffer[SIZE_BUFFER];
    int i;

    for(i=0; i<SIZE_ARRAY; i++) {

        printf("Enter fruit %d: ", i+1);
        fgets(buffer,SIZE_BUFFER,stdin);

        array[i] = (char*)malloc(strlen(buffer)+1);
        if (array[i] == NULL) {
            printf("Unable to allocate!");
            exit(1);
        }

        strcpy(array[i], buffer);
    }

    for(i=0; i<SIZE_ARRAY; i++) {
        printf("#%d Fruit: %s", i+1, *(array+i));
    }

    return(0);
}