#include"list.h"

/* ---------------------- ALLOCATE --------------------- */
/* Function: allocate memory to new item				 */
/* Arguments: void										 */
/* Return: 												 */
/*	- SUCCESS = address of new item						 */
/*	- FAILURE = NULL						 			 */
LIST *allocate(void) {
    
    LIST *p;

    p = (LIST *)malloc(sizeof(LIST)*1);
    if(p == NULL) {
        printf("Unable to allocate!");
        exit(1);
    }
    
    return p;
}

/* ------------------------ PUT ------------------------ */
/* Function: insert value into "data" field of new item	 */
/* Arguments: integer value								 */
/* Return: void											 */
void put(int n) {

    LIST *p = allocate();

	// List is empty, insert first element
    if(head == NULL) {
        p->id = count++;
        p->data = n;
        p->next = NULL;
        tail = head = p;
	// List is not empty, insert element to the tail
    } else {    
        p->id = count++;
        p->data = n;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

/* ------------------------ GET ------------------------ */
/* Function: delete item by its order in the list		 */
/* Arguments: integer value								 */
/* Return: void											 */
void get(int n) {

	LIST *temp = head;

	// List is empty, prompt error message
	if(temp == NULL)
		printf("Empty list!\n");
	// Position inserted is out of range
	else if((n-1 < 0) || (n-1 > count))
		printf("Entry not valid!\n");
	// Search entire list until item is found
	else {
		while(temp != NULL) {
			if(temp->id == (n-1)) {
				printf("%d\n", temp->data);
				break;
			}
			temp = temp->next;
		}
	}

}

/* ------------------------ LIST ----------------------- */
/* Function: list all itens								 */
/* Arguments: void 										 */
/* Return: void											 */
void list(void) {

	LIST *temp = head;

	// List is empty, prompt error message
	if(temp == NULL)
		printf("Empty list!\n");
	// Print "data" field of every item
	else {
		while(temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
	
}

/* ------------------------ FIRST ---------------------- */
/* Function: retrieve first item						 */
/* Arguments: void 										 */
/* Return: void											 */
void first(void) {

	// List is empty, prompt error message
	if(head == NULL)
		printf("Empty list!\n");
	// Prompt "data" field of head item
	else
		printf("%d\n", head->data);

}

/* ------------------------ LAST ----------------------- */
/* Function: retrieve last item							 */
/* Arguments: void 										 */
/* Return: void											 */
void last(void) {

	// List is empty, prompt error message
	if(head == NULL)
		printf("Empty list!\n");
	// Prompt "data" field of tail item
	else
		printf("%d\n", tail->data);

}

/* ------------------------ CLEAN ---------------------- */
/* Function: delete entire list							 */
/* Arguments: void 										 */
/* Return: void											 */
void clean(void) {

	LIST *next, *temp = head;

	// List is empty, prompt error message
	if(head == NULL)
		printf("Empty list!\n");
	// Free allocated memory for every item
	else {
		while (temp != NULL) {
			next = temp->next;
			free(temp);
			temp = next;
		}
	}
	// Reset auxiliar pointers
	head = NULL;
	tail = NULL;

}

/* ----------------------- DELETE ---------------------- */
/* Function: delete item by its order in the list		 */
/* Arguments: integer value								 */
/* Return: void											 */
void delete(int n) {

	LIST *temp, *aux;
	
	int i;

	// List is empty, prompt error message
	if(head == NULL)
		printf("Empty list!\n");
	// Position inserted is out of range
	else if((n-1 < 0) || (n-1 >= count))
		printf("Entry not valid!\n");
	else {
		count--;
		// Single element list, just clean
		if ((n == 1) && (head->next == NULL)) 
			clean();
		// Delete head element and make next new head 
		else if ((n == 1) && (head->next != NULL)) {
			count = 0;
			temp = head->next;
			free(head);
			head = temp;
			while (temp != NULL) {
				temp->id = count++;
				temp = temp->next;
			}
		// Delete tail element and make previous new tail
		} else if (tail->id == n-1) {
			temp = head;
			while (temp->next != tail)
				temp = temp->next;
			temp->next = NULL;
			free(tail);
			tail = temp;
		// Other elements, delete and rearrange
		} else {
			temp = aux = head;
			while(temp->id != n-1)
				temp = temp->next;
			while (aux->next != temp)
				aux = aux->next;
			count = aux->id;
			aux->next = temp->next;
			free(temp);
			while (aux != NULL) {
				aux->id = count++;
				aux = aux->next;
			}
		}
	}

}

/* ------------------------ SORT ----------------------- */
/* Function: print list in ascending order				 */
/* Arguments: void 										 */
/* Return: void											 */
void sort(void) {

	LIST *temp = head;
	int buffer[256], aux, size = 0, i, j;

	// List is empty, prompt error message
	if(head == NULL)
		printf("Empty list!\n");
	// Single element list, prompt error message
	else if (head->next == NULL)
		printf("Single element list!\n");
	else {
		// Retrieve data from entire list to a buffer
		// OBS.: this command prints ordered data, list
		// 		 should remained untouched
		while (temp != NULL) {
			buffer[size++] = temp->data;
			temp = temp->next;
		}
		// Sort itens in the buffer by ascending order
		// OBS.: simple bubble sort is performed
		for(i=0; i<size-1; i++) {
			for(j=i+1; j<size; j++) {
				if(buffer[i] > buffer[j]) {
					aux = buffer[i];
					buffer[i] = buffer[j];
					buffer[j] = aux;
				}
			}
		}
		// Print buffer data
		for(i=0; i<size; i++)
			printf("%d ", buffer[i]);
		printf("\n");
	}
}

/* -------------------- PRINT ENTRY -------------------- */
/* Function: error message of command not found		     */
/* Arguments: any string 								 */
/* Return: void											 */
void print_entry(char *entry) {
	printf("Command not found: %s", entry);
}

/* -------------------- FIND NUMBER -------------------- */
/* Function: find the digits in the command line and     */
/* 			 convert in into an integer value		     */
/* Arguments: any string 								 */
/* Return: integer value								 */
int find_number(char *str) {
	
    int i, k;
    char buffer[32];

    k = 0;

	// Search for the entire string leght for digits
	for(i = 0; i<=(int)strlen(str); i++) {
		if (isdigit(str[i]))
			// Store digit into buffer
		    buffer[k++] = str[i];
	}

	//Convert to integer
	return atoi(buffer);
}
