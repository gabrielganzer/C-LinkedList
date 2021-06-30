#include"../lib/ch1.h"

int main(int argc, char *argv[]) {

    printf("\n--------------------- Before ---------------------\n");
    show(president);
    
    swap(president[1], president[2]);

    printf("--------------------- After ---------------------\n");
    show(president);

    return(0);

}

struct person *allocate(void){

    struct person *p;

    p = (struct person *)malloc(sizeof(struct person));
    if(p == NULL){
        perror("Unable to allocate!\n");
        exit(1);
    }
    return(p);
    
}

void swap(struct person p1, struct person p2) {

    struct person *temp;

    temp = allocate();
    
    *temp = p2;
    p2 = p1;
    p1 = *temp;

    free(temp);
}

void show(struct person p[]) {
    
    int i;

    for(i=0;i<SIZE;i++)
        printf("President %s took office in %d/%d/%d.\n", p[i].name, p[i].tookoffice.day, p[i].tookoffice.month, p[i].tookoffice.year);

}