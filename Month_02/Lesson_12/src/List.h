#include "IContainer.h"
template <typename T>
struct Node {
    Node* next;         // pointer to the next List element (node)
    Node* prev;         // pointer to the previous List element (node)
    T element_value;    // list element value
//    Node() = default;
//    ~Node() { delete next; }
};