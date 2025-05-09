/**
 * @file Vector.h
 * @author Khon Min Thite
 * @brief a wrapper class for std:vector
 * @version 0.1
 * @date 24-3-2024
 *
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <initializer_list>

/**
 * @class Vector
 * @brief A custom vector class template.
 * @tparam T The type of elements stored in the vector.
 *
 * This class provides a custom implementation of a vector, similar to the standard library's std::vector.
 * It includes constructors, assignment operators, element access, capacity, modifiers, and iterators.
 */
template<typename T>
class Vector
{
public:
    // Constructors
    /**
     * @brief Default constructor.
     */
    Vector() = default;

    /**
     * @brief Constructor that creates a vector with a specified size.
     * @param size The size of the vector.
     */
    Vector(size_t size);

    /**
     * @brief Constructor that creates a vector with a specified size and initial value.
     * @param size The size of the vector.
     * @param initial The initial value for all elements.
     */
    Vector(size_t size, const T& initial);

    /**
     * @brief Copy constructor.
     * @param v The vector to copy from.
     */
    Vector(const Vector<T>& v);

    /**
     * @brief Move constructor.
     * @param v The vector to move from.
     */
    Vector(Vector<T>&& v) noexcept;

    // Destructor
    /**
     * @brief Destructor.
     */
    ~Vector();

    // Assignment operators
    /**
     * @brief Copy assignment operator.
     * @param v The vector to copy from.
     * @return A reference to this vector.
     */
    Vector<T>& operator=(const Vector<T>& v);

    /**
     * @brief Move assignment operator.
     * @param v The vector to move from.
     * @return A reference to this vector.
     */
    Vector<T>& operator=(Vector<T>&& v) noexcept;

    // Element access
    /**
     * @brief Accesses the element at the specified index.
     * @param index The index of the element.
     * @return A reference to the element at the specified index.
     */
    T& operator[](size_t index);

    /**
     * @brief Accesses the element at the specified index (const version).
     * @param index The index of the element.
     * @return A const reference to the element at the specified index.
     */
    const T& operator[](size_t index) const;

    // Capacity
    /**
     * @brief Returns the number of elements in the vector.
     * @return The number of elements in the vector.
     */
    size_t size() const;

    /**
     * @brief Returns the capacity of the vector.
     * @return The capacity of the vector.
     */
    size_t capacity() const;

    /**
     * @brief Checks if the vector is empty.
     * @return True if the vector is empty, false otherwise.
     */
    bool empty() const;

    // Modifiers
    /**
     * @brief Adds an element to the end of the vector.
     * @param value The value to add.
     */
    void push_back(const T& value);

    /**
     * @brief Adds an element to the end of the vector.
     * @param value The value to add.
     */
    void push_back(T&& value);

    /**
     * @brief Removes the last element of the vector.
     */
    void pop_back();

    /**
    * @brief Inserts an element at a specified position.
    * @param index The position to insert the element.
    * @param value The value to insert.
    */
    void insert(size_t index, const T& value);

    /**
     * @brief Removes an element at a specified position.
     * @param index The position of the element to remove.
     */
    void erase(size_t index);

    /**
     * @brief Accesses the element at a specified index.
     * @param index The index of the element.
     * @return A reference to the element at the specified index.
     */
    T& at(size_t index);

    /**
     * @brief Accesses the element at a specified index (const version).
     * @param index The index of the element.
     * @return A const reference to the element at the specified index.
     */
    const T& at(size_t index) const;

    /**
     * @brief Reserves storage for at least the specified number of elements.
     * @param new_capacity The new capacity of the vector.
     */
    void reserve(size_t new_capacity);

    /**
     * @brief Changes the size of the vector.
     * @param new_size The new size of the vector.
     */
    void resize(size_t new_size);

    /**
     * @brief Changes the size of the vector and initializes new elements.
     * @param new_size The new size of the vector.
     * @param value The value to initialize new elements with.
     */
    void resize(size_t new_size, const T& value);

    // Iterators
    /**
     * @brief Returns an iterator pointing to the first element of the vector.
     * @return An iterator pointing to the first element.
     */
    typename std::vector<T>::iterator begin()
    {
        return m_data.begin();
    }

    /**
     * @brief Returns an iterator pointing to the past-the-end element of the vector.
     * @return An iterator pointing to the past-the-end element.
     */
    typename std::vector<T>::iterator end()
    {
        return m_data.end();
    }

    /**
     * @brief Returns a const iterator pointing to the first element of the vector.
     * @return A const iterator pointing to the first element.
     */
    typename std::vector<T>::const_iterator begin() const
    {
        return m_data.begin();
    }

    /**
     * @brief Returns a const iterator pointing to the past-the-end element of the vector.
     * @return A const iterator pointing to the past-the-end element.
     */
    typename std::vector<T>::const_iterator end() const
    {
        return m_data.end();
    }

    /**
     * @brief Returns a const iterator pointing to the first element of the vector.
     * @return A const iterator pointing to the first element.
     */
    typename std::vector<T>::const_iterator cbegin() const
    {
        return m_data.cbegin();
    }

    /**
     * @brief Returns a const iterator pointing to the past-the-end element of the vector.
     * @return A const iterator pointing to the past-the-end element.
     */
    typename std::vector<T>::const_iterator cend() const
    {
        return m_data.cend();
    }

    /**
     * @brief Constructor that initializes the vector with an initializer list.
     * @param init The initializer list.
     */
    Vector(std::initializer_list<T> init) : m_data(init) {}

private:
    std::vector<T> m_data;
};

template<typename T>
Vector<T>::Vector(size_t size) : m_data(size) {}

template<typename T>
Vector<T>::Vector(size_t size, const T& initial) : m_data(size, initial) {}

template<typename T>
Vector<T>::Vector(const Vector<T>& v) : m_data(v.m_data) {}

template<typename T>
Vector<T>::Vector(Vector<T>&& v) noexcept : m_data(std::move(v.m_data)) {}

template<typename T>
Vector<T>::~Vector() = default;

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if (this != &v)
    {
        m_data = v.m_data;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& v) noexcept
{
    if (this != &v)
    {
        m_data = std::move(v.m_data);
    }
    return *this;
}

template<typename T>
T& Vector<T>::operator[](size_t index)
{
    return m_data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return m_data[index];
}

template<typename T>
size_t Vector<T>::size() const
{
    return m_data.size();
}

template<typename T>
size_t Vector<T>::capacity() const
{
    return m_data.capacity();
}

template<typename T>
bool Vector<T>::empty() const
{
    return m_data.empty();
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
    m_data.push_back(value);
}

template<typename T>
void Vector<T>::push_back(T&& value)
{
    m_data.push_back(std::move(value));
}

template<typename T>
void Vector<T>::pop_back()
{
    m_data.pop_back();
}

template<typename T>
void Vector<T>::insert(size_t index, const T& value)
{
    m_data.insert(m_data.begin() + index, value);
}

template<typename T>
void Vector<T>::erase(size_t index)
{
    m_data.erase(m_data.begin() + index);
}

template<typename T>
T& Vector<T>::at(size_t index)
{
    return m_data.at(index);
}

template<typename T>
const T& Vector<T>::at(size_t index) const
{
    return m_data.at(index);
}

template<typename T>
void Vector<T>::reserve(size_t new_capacity)
{
    m_data.reserve(new_capacity);
}

template<typename T>
void Vector<T>::resize(size_t new_size)
{
    m_data.resize(new_size);
}

template<typename T>
void Vector<T>::resize(size_t new_size, const T& value)
{
    m_data.resize(new_size, value);
}

#endif
