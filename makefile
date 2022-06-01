arraylist:
	gcc -Wall -o prog -g main.c input.c dequeElem.c dequeArrayList.c 

linkedlist:
	gcc -Wall -o prog -g main.c input.c dequeElem.c dequeLinkedList.c 

clean:
	rm -f ./prog
