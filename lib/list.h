#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ------------------- Definitions and Types ------------------- */
typedef struct item {
	int id;
	int data;
	struct item *next;
} LIST;

/* ---------------------- Global Variables --------------------- */
LIST *head, *tail;
int count;

/* ---------------------- Prompt Functions --------------------- */
void print_entry(char *entry);
int find_number(char *str);

/* ----------------------- List Functions ---------------------- */
LIST *allocate(void);
void put(int n);
void get(int n);
void list(void);
void first(void);
void last(void);
void clean(void);
void delete(int n);
void sort(void);

#endif
