#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct LinkedListStruct {
    struct LinkedListStruct* next_node;
    int value;
};

typedef struct LinkedListStruct* LinkedList;

LinkedList create_linked_list (int element) {
    LinkedList new_linked_list = (LinkedList) malloc(sizeof(struct LinkedListStruct));

    new_linked_list -> value = element;
    new_linked_list -> next_node = NULL;

    return new_linked_list;
}

LinkedList return_last_node (LinkedList list_root) {
    while (list_root -> next_node != NULL) list_root = list_root -> next_node;

    return list_root;
}

void link (LinkedList linker, LinkedList linked) { linker -> next_node = linked; }

void print_element (LinkedList list) { printf("%d / ", list -> value); }

void pop_connection (LinkedList list) {
    list -> next_node = NULL;
    free(list);
}

int take_element (LinkedList list) { return list -> value; }

LinkedList create_by_vector (int* vector, unsigned vector_size) {
    const LinkedList const root = create_linked_list(vector[0]);
    LinkedList past_node = root;

    for (unsigned index = 1; index < vector_size; ++index) {
        LinkedList new_node = create_linked_list(vector[index]);
        link(past_node, new_node);
        past_node = new_node;
    }

    return root;
}

void iterate_to_last_node (LinkedList list_node, void (*void_function)(LinkedList)) {
    LinkedList next_node;

    do {
        next_node = list_node -> next_node;
        void_function(list_node);
    } while ((list_node = next_node) != NULL);
}

int main (void) {
    LinkedList root_link = create_linked_list(10),
    link2 = create_linked_list(20),
    link3 = create_linked_list(30);

    link(root_link, link2);

    //Connect link2 to link3;
    link(return_last_node(root_link), link3);

    iterate_to_last_node(root_link, print_element);

    int vector[5] = {1, 2, 3, 4, 5};

    printf("\nCreated by vector: ");
    LinkedList demo_list = create_by_vector(vector, 5);

    iterate_to_last_node(demo_list, print_element);

    //Freeing the lists;
    iterate_to_last_node(demo_list, pop_connection);
    iterate_to_last_node(root_link, pop_connection);
    return 0;
}

