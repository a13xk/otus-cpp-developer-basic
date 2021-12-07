#include "IContainer.h"

// Template class declaration
template <typename T>
class Sequence : public IContainer<T>{
public:
    Sequence();
    ~Sequence() override;
    void push_back(T value) override;
    int size() override;
    T& operator[](int idx) { return m_region[idx]; };
private:
    int m_size;
    T* m_region;
};

// Template class definition
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
 * Get size of sequence container
 * @tparam T Type of container elements
 */
template<typename T>
int Sequence<T>::size() {
    return m_size;
};
