#include <iostream>
#include "List.h"

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
    void insert(T value, int idx) override;
    void erase(int idx) override;
    int size() const override;
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
List<T>::List() : m_last(nullptr), m_size(0) {}
/**
 * Trivial destructor
 * @tparam T Type of container elements
 */
template<typename T>
List<T>::~List() {
    delete m_last;
}
/**
 * Add new element to container
 * @tparam T New element type
 * @param value New element value
 */
template<typename T>
void List<T>::push_back(T value) {
    auto* new_node = new Node<T>{};  // create new node
    new_node->prev = m_last;            // the last element in container becomes previous
    new_node->next = nullptr;           // there is no next element yet
    new_node->element_value = value;    // store element value
    if (m_size > 0) {
        Node<T>* last = m_last;
        last->next = new_node;
    }
    m_last = new_node;              // update pointer to the last element
    m_size += 1;                    // update container size
}
/**
 * Insert element to List container by given index
 * @tparam T Type of container elements
 * @param value New value to be inserted
 * @param idx Index of new element to be inserted
 */
template<typename T>
void List<T>::insert(T value, int idx) {
    if (m_size < 0) {
        std::cout << "Container has invalid size";
        return;
    }
    // Insert element in the end of list
    if (idx == m_size) {
        push_back(value);
        return;
    }
    // Insert element somewhere in the middle of list
    if (0 < idx && idx < m_size) {
        Node<T>* node = m_last;
        Node<T>* prev = node->prev;
        for (int i = m_size-1; i >=0 ; --i) {
            if (idx == i) {
                auto* new_node = new Node<T>{};
                new_node->next = node;
                new_node->prev = prev;
                new_node->element_value = value;
                node->prev = new_node;
                prev->next = new_node;
                m_size += 1;
                return;
            }
            node = prev;
            prev = node->prev;
        }
    }

    // Insert element in the beginning of list
    if (idx == 0) {
        Node<T>* node = m_last;
        while (node->prev != nullptr) {
            node = node->prev;
        }
        auto* new_node = new Node<T>{};
        new_node->prev = nullptr;
        new_node->next = node;
        new_node->element_value = value;
        node->prev = new_node;
        m_size += 1;
        return;
    }
}
/**
 * Remove element from List container by given index
 * @tparam T Type of container elements
 * @param idx Index of element to be deleted
 */
template<typename T>
void List<T>::erase(int idx) {
    if (m_size <= 0) {
        std::cout << "Container has invalid size";
        return;
    }
    if (m_size == 1) {
        delete m_last;
        m_last == nullptr;
        m_size = 0;
        return;
    }
    if (m_size >=2) {
        // Erase last element
        if (idx == m_size-1) {
            Node<T>* node = m_last->prev;
            delete m_last;
            m_last = node;
            m_size--;
            return;
        }
        // Erase element somewhere in the middle of list
        if (0 < idx && idx < m_size-1) {
            Node<T>* node = m_last;
            Node<T>* prev = node->prev;
            Node<T>* next = node->next;
            for (int i = m_size-1; i >=0 ; --i) {
                if (idx == i) {
                    prev->next = next;
                    next->prev = prev;
                    delete node;
                    m_size--;
                    return;
                }
                node = prev;
                prev = node->prev;
                next = node->next;
            }
        }
        // Erase first element
        if (idx == 0) {
            Node<T>* node = m_last;
            while (node->prev != nullptr) {
                node = node->prev;
            }
            Node<T>* next = node->next;
            next->prev = nullptr;
            delete node;
            m_size--;
            return;
        }
        // Do not allow erasing by index out of range
        if (idx >= m_size) {
            std::cout << "Invalid index: " << idx << std::endl;
            return;
        }
    }
}
/**
 * Get size of list container
 * @tparam T Type of container elements
 */
template<typename T>
int List<T>::size() const {
    return m_size;
}
