#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include <time.h>

void stressTest(PtDeque deque, int testSize);

int main() {
    srand(time(NULL));

    PtDeque d = dequeCreate();
    if(d == NULL) return EXIT_FAILURE;

    dequeAddFront(d, 1); 
    dequeAddFront(d, 13);

    // TODO Begin: Insert requested code after this line.
    

    // TODO End. Insert reqeusted code before this line.

    /*  Stress-test for the chosen implementation at compile-time.
        This can take several seconds */
    stressTest(d, 100000);

    dequeDestroy(&d);

    return EXIT_SUCCESS;
}

void stressTest(PtDeque deque, int testSize) {
    int elem, rear, errorCode;

    printf("\nStress testing with %d elements...  Please wait.\n", testSize);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    /* Do the work. */
    for(int i=0; i<testSize; i++) {
        elem = 1+ rand() % 1000;
        errorCode = dequeAddFront(deque,elem);
        if(errorCode != DEQUE_OK) {
            printf("Stopping because an error ocurred... Code: %d \n", errorCode);
            break;
        }
    }
 
    while (!dequeIsEmpty(deque)) {
        dequeRear(deque, &rear);
        errorCode = dequeRemoveRear(deque,&elem);
        if(errorCode != DEQUE_OK) {
            printf("Stopping because an error ocurred... Code: %d \n", errorCode);
            break;
        }

        if(elem != rear) {
            printf("Stopping because there is a mismatch between dequeRear and dequeRemoveRear. They are not the same! \n");
            break;
        }        
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;    
    printf("-- Time taken: %lf seconds \n", cpu_time_used);

}