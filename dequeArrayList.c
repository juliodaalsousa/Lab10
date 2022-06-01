/**
 * @file dequeArrayList.c
 * 
 * @brief Provides an implementation of the ADT Deque with an
 * array list as the underlying data structure.
 * 
 * @author Bruno Silva (bruno.silva@estsetubal.ips.pt)
 * @bug No known bugs.
 */

#include "deque.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 50

typedef struct dequeImpl {
	DequeElem *elements;
    int capacity;
	int size;
} DequeImpl;

static bool ensureCapacity(PtDeque deque) {
    if (deque->size == deque->capacity) {
        int newCapacity = deque->capacity * 2;
        DequeElem* newElements = (DequeElem*) realloc( deque->elements, 
                                newCapacity * sizeof(DequeElem) );
        
        if(newElements == NULL) return false; 

        deque->elements = newElements;
        deque->capacity = newCapacity;
    }
    
    return true;
}

PtDeque dequeCreate() {
	PtDeque deque = (PtDeque)malloc(sizeof(DequeImpl));
	if (deque == NULL) return NULL;

	// TODO

	return deque;
}

int dequeDestroy(PtDeque *ptDeque) {
	PtDeque deque = *ptDeque;
	if (deque == NULL) { return DEQUE_NULL;	}

	// TODO

	*ptDeque = NULL;

	return DEQUE_OK;
}

int dequeAddFront(PtDeque deque, DequeElem elem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if(!ensureCapacity(deque)) return DEQUE_NO_MEMORY;

    // TODO

	return DEQUE_OK;
}

int dequeRemoveFront(PtDeque deque, DequeElem *ptElem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if (dequeIsEmpty(deque)) {return DEQUE_EMPTY;	}

	// TODO

	deque->size--;

	return DEQUE_OK;
}

int dequeFront(PtDeque deque, DequeElem *ptElem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if (dequeIsEmpty(deque)) {	return DEQUE_EMPTY;	}
	
	// TODO
	
	return DEQUE_OK;
}
	
int dequeAddRear(PtDeque deque, DequeElem elem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if(!ensureCapacity(deque)) return DEQUE_NO_MEMORY;

	deque->elements[deque->size++] = elem;

	return DEQUE_OK;
}

int dequeRemoveRear(PtDeque deque, DequeElem *ptElem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if (dequeIsEmpty(deque)) {return DEQUE_EMPTY;	}

	*ptElem = deque->elements[ --deque->size ];

	return DEQUE_OK;
}

int dequeRear(PtDeque deque, DequeElem *ptElem) {
	if (deque == NULL) {return DEQUE_NULL;	}

	if (dequeIsEmpty(deque)) {	return DEQUE_EMPTY;	}
	
	*ptElem = deque->elements[ deque->size - 1 ];
	
	return DEQUE_OK;
}

int dequeSize(PtDeque deque, int *ptSize) {
	if (deque == NULL) return DEQUE_NULL;

	*ptSize = deque->size;
	
	return DEQUE_OK;
}

bool dequeIsEmpty(PtDeque deque) {
	if (deque == NULL) return true;
	return (deque->size == 0);
}

int dequeClear(PtDeque deque) {
	if (deque == NULL) return DEQUE_NULL;
	
	/*	When clearing, lets reallocated to the initial capacity.
		This will avoid keeping a, possibly, large allocated array when not needed. */
    deque->elements = (DequeElem*)realloc(deque->elements, INITIAL_CAPACITY * sizeof(DequeElem));
    deque->capacity = INITIAL_CAPACITY;
	deque->size = 0;

	return DEQUE_OK;
}

void dequePrint(PtDeque deque) {
	if (deque == NULL) {
		printf("(Deque NULL) \n");
	}
	else if (deque->size == 0) {
		printf("(Deque Empty) \n");
	}
	else {
		//imprimir do inicio para o fim da fila:
		printf("Deque contents (front to rear): \n");
		for(int i=0; i<deque->size; i++) {
			dequeElemPrint(deque->elements[i]);
		}
		printf("\n------------------------------ \n");
	}
}

