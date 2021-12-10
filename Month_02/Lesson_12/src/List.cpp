#include <iostream>
#include "IContainer.h"

/**
 * Implementation of IContainer template class
 * Elements are connected with each other using pointers
 */

// Template class declaration
template <typename T>
class ListContainer : public IContainer<T> {
public:
    struct Node {
        Node* next;         // pointer to the next ListContainer element (node)
        Node* prev;         // pointer to the previous ListContainer element (node)
        T element_value;    // list element value
    };
    ListContainer();
    ~ListContainer() override;
    void push_back(T value) override;
private:
    Node* m_last;
    int m_size;
};

// Template class definition
/**
 * Default constructor
 * @tparam T Type of container elements
 */
template <typename T>
ListContainer<T>::ListContainer() : m_last(nullptr), m_size(0) {};
/**
 * Trivial destructor
 * @tparam T Type of container elements
 */
template<typename T>
ListContainer<T>::~ListContainer() = default;
/**
 * Add new element to container
 * @tparam T New element type
 * @param value New element value
 */
template<typename T>
void ListContainer<T>::push_back(T value) {
    Node* new_node = new Node{};        // create new node
    new_node->prev = m_last;            // the last element in container becomes previous
    new_node->next = nullptr;           // there is no next element yet
    new_node->element_value = value;    // store element value
    m_last = new_node;                  // update pointer to the last element
    m_size += 1;                        // update container size обновляем размер
};