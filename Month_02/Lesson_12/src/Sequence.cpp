#include <iostream>
#include "IContainer.h"

// Template class declaration
template <typename T>
class Sequence : public IContainer<T>{
public:
    Sequence();
    ~Sequence() override;
    void push_back(T value) override;
    void insert(T value, int idx) override;
    void erase(int idx) override;
    int size() const override;
    T operator[](int idx) const override;
private:
    int m_size;
    T* m_region;
};

/**
 * Send all elements of Sequence<T> container to output stream separating them with space
 * @tparam T Type of container elements
 * @param os Output stream
 * @param sequence Sequence container
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Sequence<T>& sequence)
{
    for (int i = 0; i < sequence.size(); ++i) {
        os << sequence[i] << " ";
    }
    return os;
}

// Template class definition
/**
 * Return value by given index
 * @tparam T Type of container elements
 * @param idx Index of element
 */
template <typename T>
T Sequence<T>::operator[](int idx) const {
    return m_region[idx];
};
/**
 * Default constructor
 * @tparam T Type of container elements
 */
template<typename T>
Sequence<T>::Sequence() : m_size(0), m_region(nullptr) {};

/**
 * Trivial destructor
 * @tparam T Type of container elements
 */
template<typename T>
Sequence<T>::~Sequence() = default;

/**
 * Add new element to container
 * @tparam T New element type
 * @param value New element value
 */
template<typename T>
void Sequence<T>::push_back(T value) {
    T* new_region = new T[m_size + 1];  // allocate new memory
    for (int i = 0; i < m_size; ++i) {
        new_region[i] = m_region[i];    // copy existing elements
    }
    new_region[m_size] = value;         // add new element
    delete [] m_region;                 // delete old allocated memory
    m_region = new_region;              // save new allocated memory in class member
    m_size += 1;                        // update container size
};
/**
 * Insert element to container by given index
 * @tparam T Type of container elements
 * @param value New value to be inserted
 * @param idx Index of new element to be inserted
 */
template<typename T>
void Sequence<T>::insert(T value, int idx) {
    if (m_size < 0) {
        std::cout << "Container has invalid size";
        return;
    }
    T* new_region = new T[m_size + 1];
    // Insert element in the beginning of sequence
    if (idx == 0) {
        new_region[0] = value;
        for (int i = 0; i < m_size; ++i) {
            new_region[i+1] = m_region[i];
        }
    }
    // Insert element in the end of sequence
    if (idx == m_size-1) {
        for (int i = 0; i < m_size; ++i) {
            new_region[i] = m_region[i];
        }
        new_region[m_size] = value;
    }
    // Insert element somewhere in the middle of sequence
    if (0 < idx && idx < m_size-1) {
        for (int i = 0; i < idx; ++i) {
            new_region[i] = m_region[i];
        }
        new_region[idx] = value;
        for (int i = idx; i < m_size; ++i) {
            new_region[i+1] = m_region[i];
        }
    }
    // Insert element after the end of sequence
    if (idx == m_size) {
        new_region = new T[idx+1];
        for (int i = 0; i < m_size; ++i) {
            new_region[i] = m_region[i];
        }
        new_region[idx] = value;
    }
    // Insert element at index out of range of sequence
    if (idx > m_size) {
        new_region = nullptr;
        T* another_region = new T[idx + 1];
        for (int i = 0; i < m_size; ++i) {
            another_region[i] = m_region[i];
        }
        // Fill new indexes with zeros
        for (int i = m_size; i < idx; ++i) {
            another_region[i] = 0;
        }
        another_region[idx] = value;
        delete [] m_region;
        m_region = another_region;
        m_size = idx+1;
        return;
    }
    delete [] m_region;
    m_region = new_region;
    m_size += 1;
};
/**
 * Remove element from container by given index
 * @tparam T Type of container elements
 * @param idx Index of element to be deleted
 */
template<typename T>
void Sequence<T>::erase(int idx) {
    if (m_size <= 0) {
        std::cout << "Container has invalid size";
        return;
    }
    if (m_size == 1) {
        delete [] m_region;
        m_size = 0;
    }
    if (m_size >= 2) {
        T* new_region = new T[m_size - 1];

        // Erase first element
        if (idx == 0) {
            for (int i = 0; i < m_size-1; ++i) {
                new_region[i] = m_region[i+1];
            }
        }
        // Erase last element
        if (idx == m_size-1) {
            for (int i = 0; i < m_size-1; ++i) {
                new_region[i] = m_region[i];
            }
        }
        // Erase element somewhere in the middle of sequence
        if (0 < idx && idx < m_size-1) {
            for (int i = 0; i < idx; ++i) {
                new_region[i] = m_region[i];
            }
            for (int i = idx+1; i < m_size; ++i) {
                new_region[i-1] = m_region[i];
            }
        }
        // Do not allow erasing by index out of range
        if (idx >= m_size) {
            std::cout << "Invalid index: " << idx << std::endl;
            return;
        }
        delete [] m_region;
        m_region = new_region;
        m_size -= 1;
    }
};

/**
 * Get size of sequence container
 * @tparam T Type of container elements
 */
template<typename T>
int Sequence<T>::size() const {
    return m_size;
};
