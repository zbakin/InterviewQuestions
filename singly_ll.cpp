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

node_t* even_nodes(struct node_t** head_ptr) {
    node_t *curr = *head_ptr; // original list iterator
    node_t *even_head = nullptr; // head of even values list
    node_t *even_it = nullptr; // iterator of even values list

    while (curr != nullptr) {
        if (curr->v % 2 == 0) {
            if (even_it == nullptr) { // add first even node
                even_head = curr;
                even_it = curr;
            } else { // if we have at least 1 node in new list, append even value
                even_it->next = curr;
                even_it = even_it->next;
            }
            // remove current node from original list(move pointer to next and pointer to next set to nullptr)
            *head_ptr = curr->next;
            curr->next = nullptr;
            curr = *head_ptr;
        } else { // if odd, just move to next node
            head_ptr = &curr->next; // move head_ptr to next node
            curr = curr->next;
        }
    }
    return even_head;
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

    node_t* even_list = even_nodes(&head);
    while(even_list != nullptr) {
        cout << even_list->v << endl;
        even_list = even_list->next;
    }
    
    while(head != nullptr) {
        cout << head->v << endl;
        head = head->next;
    }
    return 0;
}
