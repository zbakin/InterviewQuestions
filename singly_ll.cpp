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
    if(head == nullptr) return *head;
    node_t* even_n = new node_t;
    node_t* curr_original = *head;
    node_t* curr_even = even_n;
    if(curr_original->v % 2 == 0) {
        even_n->v = curr_original->v;
    } else {
        curr_even = curr
    }
    while(curr_original->next != nullptr) {
        if(curr_original->next->v % 2 == 0) {
            node_t *nn = new node_t;
            nn->v = curr_original->next->v;
            curr_even->next = nn;
            curr_even = curr_even->next;
        }
        curr_original = curr_original->next;
    }
    return even_n;
}


int main() {

    node_t *head = new node_t;
    node_t *curr = head;
    curr->v = 1;
    for(int i = 0; i < 2; i++) {
        node_t *nn = new node_t;
        nn->v = 2;
        curr->next = nn;
        curr = curr->next;
    }
    node_t *nn = new node_t;
    nn->v = 3;
    curr->next = nn;
    curr = curr->next;
    
    nn = new node_t;
    nn->v = 2;
    curr->next = nn;
    curr = curr->next;
//    while(head != nullptr) {
//        cout << head->v << endl;
//        head = head->next;
//    }
    node_t* nodes = even_nodes(&head);
    while(nodes != nullptr) {
        cout << nodes->v << endl;
        nodes = nodes->next;
    }
    return 0;
}
