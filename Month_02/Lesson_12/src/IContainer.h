#pragma once

template <typename T>
class IContainer {
public:
    virtual ~IContainer() = default;

    virtual void push_back(T value) = 0;
    virtual void insert(T value, int idx) = 0;
    virtual void erase(int idx) = 0;
    virtual int size() = 0;
    virtual T& operator[](int idx) = 0;

private:
    T*  m_region;
    int m_size;
};