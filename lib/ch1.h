#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

struct date {
    int day;
    int month;
    int year;
};

struct person {
    char name[32];
    struct date tookoffice;
} president[SIZE] = {
    {"George Washington", {30, 4, 1789}},
    {"Thomas Jefferson", {4, 3, 1801}},
    {"Abraham Lincoln", {4, 3, 1861}}, 
    {"Theodore Roosevelt", {14, 9, 1901}}
};

struct person *allocate(void);
void show(struct person p[]);
void swap(struct person p1, struct person p2);