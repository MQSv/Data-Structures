#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct LinkedListStruct {
    struct LinkedListStruct* nextNode;
    int value;
};

typedef struct LinkedListStruct* LinkedList;

LinkedList createLinkedList (int element) {
    LinkedList newLinkedList = (LinkedList) malloc(sizeof(struct LinkedListStruct));

    newLinkedList -> value = element;
    newLinkedList -> nextNode = NULL;

    return newLinkedList;
}

LinkedList returnLastNode (LinkedList listRoot) {
    while (listRoot -> nextNode != NULL) listRoot = listRoot -> nextNode;

    return listRoot;
}

LinkedList iterateToLastNode (LinkedList listRoot, void (*voidFunction)(LinkedList)) {
    do voidFunction(listRoot);
    while ((listRoot = listRoot -> nextNode) != NULL);
}

int takeElement (LinkedList list) { return list -> value; }

void link (LinkedList linker, LinkedList linked) { linker -> nextNode = linked; }

void printElement (LinkedList list) { printf("%d / ", list -> value); }

void popConnection (LinkedList list) { free(list); }

void freeList (LinkedList listNode) {
    LinkedList nextNode;

    do {
        nextNode = listNode -> nextNode;
        free(listNode);
    }
    while ((listNode = nextNode) != NULL);
}

int main (void) {
    LinkedList rootLink = createLinkedList(10);
    LinkedList link2 = createLinkedList(20);
    LinkedList link3 = createLinkedList(30);

    link(rootLink, link2);
    //Connect link2 to link3;
    link(returnLastNode(rootLink), link3);

    iterateToLastNode(rootLink, printElement);

    freeList(rootLink);
    return 0;
}
