#include <iostream>
#include "IContainer.h"
template <typename T>
struct Node {
    Node* next;         // pointer to the next List element (node)
    Node* prev;         // pointer to the previous List element (node)
    T element_value;    // list element value
};
/**
 * Implementation of IContainer template class
 * Elements are connected with each other using pointers
 */

// Template class declaration
template <typename T>
class List : public IContainer<T> {
public:

    List();
    ~List() override;
    void push_back(T value) override;
    int size() const override;
    T& operator[](int idx) override;
    const T& operator[](int idx) const override;
private:
    Node<T>* m_last;
    int m_size;
};

/**
 * Send all elements of List<T> container to output stream separating them with space
 * @tparam T Type of container elements
 * @param os Output stream
 * @param list List container
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list)
{
    for (int i = 0; i < list.size(); ++i) {
        os << list[i] << " ";
    }
    return os;
}

// Template class definition
/**
 * Return value by given index
 * @tparam T Type of container elements
 * @param idx Index of element
 */
template<typename T>
T &List<T>::operator[](int idx) {
    Node<T>* last = m_last;
    int last_index = m_size-1;
    while (last_index > 0) {
        if (idx == last_index) {
            return last->element_value;
        }
        last_index--;
        last = last->prev;
    }
    return last->element_value;
}

template<typename T>
const T &List<T>::operator[](int idx) const {
    Node<T>* last = m_last;
    int last_index = m_size-1;
    while (last_index > 0) {
        if (idx == last_index) {
            return last->element_value;
        }
        last_index--;
        last = last->prev;
    }
    return last->element_value;
}
/**
 * Default constructor
 * @tparam T Type of container elements
 */
template <typename T>
List<T>::List() : m_last(nullptr), m_size(0) {};
/**
 * Trivial destructor
 * @tparam T Type of container elements
 */
template<typename T>
List<T>::~List() = default;
/**
 * Add new element to container
 * @tparam T New element type
 * @param value New element value
 */
template<typename T>
void List<T>::push_back(T value) {
    Node<T>* new_node = new Node<T>{};  // create new node
    new_node->prev = m_last;            // the last element in container becomes previous
    new_node->next = nullptr;           // there is no next element yet
    new_node->element_value = value;    // store element value
    if (m_size > 0) {
        Node<T>* last = m_last;
        last->next = new_node;
    }
    m_last = new_node;              // update pointer to the last element
    m_size += 1;                    // update container size
};
/**
 * Get size of list container
 * @tparam T Type of container elements
 */
template<typename T>
int List<T>::size() const {
    return m_size;
};
