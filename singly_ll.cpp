// Given:
// struct node_t
// {
// unsigned v;
// struct node_t* next;
// };
// A singly linked list of nodes is referred to by a pointer to the head node (the head pointer will be
// NULL in the case of an empty list).
// Write a function:
// struct node_t* even_nodes(struct node_t**)
// which is passed a pointer to the head pointer of a list. It should remove all nodes with even
// values from the indicated list, putting them in a new list, which is returned.
#include <iostream>
using std::cout;
using std::endl;

struct node_t
{
    unsigned v;
    struct node_t* next = nullptr;
};

node_t* even_nodes(node_t** head) {
    // if empty head
    if(head == nullptr) return *head;
    node_t* even_n = *head;
    // while first even is not found, set even_n to even_n->next
    while(even_n->v % 2 != 0 && even_n->next != nullptr) {
        even_n = even_n->next;
    }
    node_t* curr = even_n;
    while(curr->next != nullptr) {
        if(curr->next->v % 2 == 1) {
            curr = curr->next->next;
        }
    }
    return even_n;
}


int main() {

    node_t *head = new node_t;
    node_t *curr = head;
    curr->v = 1;
    for(int i = 0; i < 4; i++) {
        node_t *nn = new node_t;
        nn->v = 2;
        curr->next = nn;
        curr = curr->next;
    }
    node_t *nn = new node_t;
    nn->v = 3;

    node_t* nodes = even_nodes(&head);
    while(nodes != nullptr) {
        cout << nodes->v << endl;
        nodes = nodes->next;
    }
    return 0;
}