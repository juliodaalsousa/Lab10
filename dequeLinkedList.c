/**
 * @file dequeLinkedList.c
 * 
 * @brief Provides an implementation of the ADT Deque with a 
 * doubly-linked list with sentinels as the underlying 
 * data structure.
 * 
 * @author Bruno Silva (bruno.silva@estsetubal.ips.pt)
 * @bug No known bugs.
 */

#include "deque.h" 
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node* PtNode;

typedef struct node {
	DequeElem element;
	PtNode prev;
	PtNode next;
} Node;

typedef struct dequeImpl {
	PtNode header;
	PtNode trailer;
	int size;
} DequeImpl;


PtDeque dequeCreate() {
	PtDeque deque = (PtDeque)malloc(sizeof(DequeImpl));
	if (deque == NULL) return NULL;

	deque->header = (PtNode)malloc(sizeof(Node));
	if (deque->header == NULL) {
		free(deque);
		return NULL;
	}
	deque->trailer = (PtNode)malloc(sizeof(Node));
	if (deque->trailer == NULL) {
		free(deque->header);
		free(deque);
		return NULL;
	}

	// TODO

	return deque;
}

int dequeDestroy(PtDeque *ptDeque) {
	PtDeque deque = *ptDeque;
	if (deque == NULL) { return DEQUE_NULL;	}

	// TODO Begin  Nível 5
	PtNode current = deque->header;
	while (current != NULL) {
		PtNode remove = current;
		current = current->next;
		free(remove);
	}

	// TODO End  Nível 5

	free(deque);

	*ptDeque = NULL;

	return DEQUE_OK;
}

int dequeAddFront(PtDeque deque, DequeElem elem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	// TODO

	return DEQUE_OK;
}
	
int dequeRemoveFront(PtDeque deque, DequeElem *ptElem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if (dequeIsEmpty(deque)) {return DEQUE_EMPTY;	}

	PtNode curFront = deque->header->next;
	*ptElem = curFront->element;

	PtNode newFront = curFront->next; //ou deque->header->next->next;

	deque->header->next = newFront;
	newFront->prev = deque->header;
	
	free(curFront);

	deque->size--;

	return DEQUE_OK;
}

int dequeFront(PtDeque deque, DequeElem *ptElem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if (dequeIsEmpty(deque)) {	return DEQUE_EMPTY;	}
	
	PtNode curFront = deque->header->next;
	*ptElem = curFront->element;
	
	return DEQUE_OK;
}

int dequeAddRear(PtDeque deque, DequeElem elem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	PtNode newRear = (PtNode)malloc(sizeof(Node));
	if (newRear == NULL) return DEQUE_NO_MEMORY;

	PtNode curRear = deque->trailer->prev;

	newRear->element = elem;
	newRear->next = deque->trailer;
	newRear->prev = curRear;

	deque->trailer->prev = newRear;
	curRear->next = newRear;

	deque->size++;

	return DEQUE_OK;
}

int dequeRemoveRear(PtDeque deque, DequeElem *ptElem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if (dequeIsEmpty(deque)) {return DEQUE_EMPTY;	}

	// TODO

	return DEQUE_OK;
}

int dequeRear(PtDeque deque, DequeElem *ptElem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if (dequeIsEmpty(deque)) {	return DEQUE_EMPTY;	}
	
	// TODO
	
	return DEQUE_OK;
}

int dequeSize(PtDeque deque, int *ptSize) {
	if (deque == NULL) return DEQUE_NULL;

	*ptSize = deque->size;
	
	return DEQUE_OK;
}

bool dequeIsEmpty(PtDeque deque) {
	if (deque == NULL) return 1;
	return (deque->header->next == deque->trailer) ? true : false;
}

int dequeClear(PtDeque deque) {
	if (deque == NULL) return DEQUE_NULL;
	
	DequeElem elem;
	while (!dequeIsEmpty(deque)) {
		dequeRemoveFront(deque, &elem);
	}

	//size is updated by removal operation

	return DEQUE_OK;
}

void dequePrint(PtDeque deque) {
	if (deque == NULL) {
		printf("(Deque NULL) \n");
	}
	else if (deque->header->next == deque->trailer) {
		printf("(Deque Empty) \n");
	}
	else {
		//imprimir do inicio para o fim da fila:
		printf("Deque contents (front to rear): \n");
		PtNode current = deque->header->next;
		while (current != deque->trailer) {
			dequeElemPrint(current->element);
			current = current->next;
		}
		printf("\n------------------------------ \n");
	}
}

