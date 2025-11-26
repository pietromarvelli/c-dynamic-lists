#include <stdio.h>
#include <stdlib.h>

typedef struct node_{
	int value;
	struct node_ *next;
} node_t;

void append(node_t *head, int value); // ok
void printList(node_t *head); // ok
void insert(node_t **head, int value); // ok
void insertPos(node_t **head, int pos, int value); // ok
void insertAfter(node_t **head, int before, int value); // ok
void removeEnd(node_t *head); // ok
void removeHead(node_t **head); // ok
void removeVal(node_t **head, int val); // ok
void removePos(node_t **head, int pos); // ok
node_t *reverse_list(node_t *head); // ok

int main(void) {
	node_t *head;
	node_t *reverse;
	head = (node_t*) malloc(sizeof(node_t));
	if(head == NULL) {
		printf("Errore di allocazione. ");
		return 1;
	}

	append(head, 1);
	insert(&head, -1);
	append(head, 2);
	append(head, 3);
	insert(&head, 0);
	append(head, 4);
	printf("-- LISTA INIZIALE --\n");
	printList(head);


	printf("\n--REVERSE LIST--\n");
	reverse = reverse_list(head);
	printList(reverse);

	removeEnd(head);

	printf("\n--REMOVE END--\n");
	
	printList(head);

	printf("\n--REMOVE HEAD--\n");

	removeHead(&head);

	printList(head);

	printf("\n--INSERT POS 1--\n");

	insertPos(&head, 1, 10);

	printList(head);

	printf("\n--INSERT POS 6--\n");
	
	insertPos(&head, 6, 10);

	printf("\n--INSERT 11 AFTER 10--\n");

	insertAfter(&head, 10, 11);

	printList(head);

	printf("\n--INSERT 13 AFTER 12--\n");
	insertAfter(&head, 12, 13);

	printf("\n--REMOVE 10--\n");

	removeVal(&head, 10);

	printList(head);

	printf("\n--REMOVE 18--\n");
	removeVal(&head, 18);

	printf("\n--REMOVE POS 2--\n");
	removePos(&head, 2);
	printList(head);

	printf("\n--REMOVE POS 3--\n");
	removePos(&head, 3);
	printList(head);

	printf("\n--REMOVE POS 3--\n");
	removePos(&head, 3);

	printf("\n--REMOVE POS 18--\n");
	removePos(&head, 18);

	printf("\n--REVERSE LIST--\n");
	reverse = reverse_list(head);
	printList(reverse);
	
	return 0;
}


void insert(node_t **head, int value) {
	node_t *newNode;
	newNode = (node_t *)malloc(sizeof(node_t));
	if(newNode == NULL) {
		printf("Errore di allocazione.");
		return;
	}
	newNode -> value = value;
	newNode -> next = *head;
	*head = newNode;
	
}

node_t *reverse_list(node_t *head) {
	node_t *current = head, *reverse;
	reverse = NULL;
	while(current -> next != NULL) {
		insert(&reverse, current->next->value);
		current = current->next;
	}
	//removeEnd(reverse);

	insert(&reverse, current->value);

	return reverse;
}


void removePos(node_t **head, int pos) {
	node_t *current = *head, *temp;
	temp = (node_t *) malloc(sizeof(node_t));
	if(temp == NULL) {
		printf("Errore di allocazione.");
		return;
	}
	
	while(pos != 0 && current->next != NULL) {
		current = current -> next;
		pos--;
	}
	if(current -> next == NULL || pos > 0) {
		printf("Lista troppo corta\n");
		return;
	}
	if(current->next->next == NULL) {
		removeEnd(*head);
		return;
	}
	temp = current->next->next;
	free(current->next);
	current->next = temp;
	
}

void removeVal(node_t **head, int val) {
	node_t *current = *head, *temp;
	temp = (node_t *) malloc(sizeof(node_t));
	if(temp == NULL) {
		printf("Errore di allocazione.");
		return;
	}

	while (current->next != NULL && current->next->value != val) {
	    current = current->next;
	}

	if (current->next == NULL) {
	    printf("Il valore %d non è presente nella lista.\n", val);
	    return;
	}

	temp = current->next->next;
	free(current->next);
	current->next = temp;
}

void insertAfter(node_t **head, int before, int value) {
	node_t *current = *head, *newNode;

	newNode = (node_t *) malloc(sizeof(node_t));
	if(newNode == NULL) {
		printf("Errore di allocazione.");
		return;
	}

	newNode -> value = value;
	while(current->value != before) {
		current = current->next;
		if(current->next == NULL) {
			printf("Il valore %d non è presente nella lista.\n", before);
			return;
		}
	}

	newNode -> next = current -> next;
	current -> next = newNode;

	
}

void insertPos(node_t **head, int pos, int value) {
	node_t *current = *head, *newNode;
	newNode = (node_t *) malloc(sizeof(node_t));
	if(newNode == NULL) {
		printf("Errore di allocazione.");
		return;
	}
	newNode -> value = value;
	while(pos != 0 && current->next != NULL) {
		current = current -> next;
		pos--;
	}
	if(pos != 0) {
		printf("Lista troppo corta\n");
		return;
	}
	newNode -> next = current -> next;
	current -> next = newNode;
}

void removeHead(node_t **head) {
	node_t *temp;
	temp = (node_t *) malloc(sizeof(node_t));
	if(temp == NULL) {
		printf("Errore di allocazione.");
		return;
	}

	temp  = (*head)->next->next;
	free((*head)->next);
	(*head)->next = temp;
}

void removeEnd(node_t *head) {
	node_t *current = head;
	while(current -> next -> next != NULL) {
		current = current->next;
	}
	current -> next = NULL;	
	
}


void append(node_t *head, int value) {
	node_t *current = head;
	while(current -> next != NULL) {
		current = current->next;
	}

	current -> next = (node_t *) malloc(sizeof(node_t));
	current -> next -> value = value;
	current -> next -> next = NULL;
}

void printList(node_t *head) {
	while(head->next != NULL) {
		printf("%d\n", head->next->value);
		head = head -> next;
	}
}
