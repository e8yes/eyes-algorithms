#ifndef ARRAY_H
#define ARRAY_H


/**
 * @brief The Array class
 * Dynamically sized array container.
 * Type: element type.
 */
template<typename Type>
class Array
{
public:
        Array();
        Array(Array<int> const& other);
        ~Array();

        // TODO: Implement the following iterator class.
        class Iterator
        {
        public:
                Iterator(Iterator const& other);
                ~Iterator();

                /**
                 * @brief operator =: Assignment (copy) operator.
                 * @param other
                 * @return Tterator after assignment.
                 */
                Iterator& operator=(Iterator const& other);

                /**
                 * @brief operator +: Move forward the iterator.
                 * @param offset: The amount of offset to move forward.
                 * @return The moved iterator.
                 */
                Iterator operator+(unsigned offset) const;

                /**
                 * @brief operator -: Move backward the iterator.
                 * @param offset: the amount of offset to move backward.
                 * @return The moved iterator.
                 */
                Iterator operator-(unsigned offset) const;

                /**
                 * @brief operator ++: Move foward the iterator by exactly one position
                 * (Postfix increment, i.e. ++it).
                 * @return The moved iterator.
                 */
                Iterator& operator++();

                /**
                 * @brief operator --: Move backward the iterator by exactly one position
                 * (Postfix decrement, i.e. --it).
                 * @return The moved iterator.
                 */
                Iterator& operator--();

                /**
                 * @brief operator ==: Iterator equality.
                 * @param other: The other iterator to compare.
                 * @return *this == other.
                 */
                bool operator==(Iterator const& other) const;

                /**
                 * @brief operator !=: Iterator inequality.
                 * @param other: The other iterator to compare.
                 * @return *this != other.
                 */
                bool operator!=(Iterator const& other) const;

                /**
                 * @brief operator *: Deferencing the iterator will extract the element
                 * at current iterator position.
                 * @return element at current iterator position.
                 */
                Type& operator*();

        protected:
                /**
                 * @brief Iterator: Constructor is protected because
                 * Iterator can only be constructed by Begin() or End().
                 */
                Iterator(/* Add necessary arguments to construct this iterator */);
        };

        /**
         * @brief Append: Append element to the end of the array.
         * @param new_element: element to be added
         */
        void            Append(Type const& new_element);

        /**
         * @brief Pop: Remove the last element from the array.
         * @return the last element before the removal.
         */
        Type            Pop();

        /**
         * @brief operator []: Random element access.
         * @param index: element position.
         * @return reference to the element at the specified position.
         */
        Type&           operator[](unsigned index);
        Type const&     operator[](unsigned index) const;

        // TODO: Implement the following methods.
        /**
         * @brief Front
         * @return Reference to the first element in the array.
         */
        Type&           Front();
        Type const&     Front() const;

        /**
         * @brief Back
         * @return Reference to the last element in the array.
         */
        Type&           Back();
        Type const&     Back() const;

        /**
         * @brief Erase: Remove element at the iterator position.
         * @param it: the iterator position.
         * @return next valid iterator position after the removal.
         */
        Iterator        Erase(Iterator const& it);

        /**
         * @brief Begin
         * @return an iterator pointing at the beginning of the array.
         */
        Iterator        Begin() const;

        /**
         * @brief End
         * @return an iterator pointing after the ending of the array.
         */
        Iterator        End() const;

private:
        bool            HasEnoughSpace(unsigned new_len) const;
        void            Resize(unsigned new_len);

        Type*           data_;
        unsigned        len_;
        unsigned        actual_len_;
};

template<typename Type>
Array<Type>::Array() :
        data_(nullptr),
        len_(0),
        actual_len_(0)
{
}

template<typename Type>
Array<Type>::Array(Array<int> const& other) : Array()
{
        if (other.actual_len_ == 0)
                return;

        data_ = new Type [other.actual_len_];
        for (int i = 0; i < other.actual_len_; i ++) {
                data_[i] = other.data_[i];
        }
        len_ = other.len_;
        actual_len_ = other.actual_len_;
}

template<typename Type>
Array<Type>::~Array()
{
        delete [] data_;
}

template<typename Type>
bool
Array<Type>::HasEnoughSpace(unsigned new_len) const
{
        return new_len <= actual_len_;
}

template<typename Type>
void
Array<Type>::Resize(unsigned new_len)
{
        Type* tmp = new Type [new_len];
        for (int i = 0; i < len_; i ++) {
                tmp[i] = data_[i];
        }
        delete [] data_;
        data_ = tmp;
}

template<typename Type>
void
Array<Type>::Append(Type const& new_element)
{
        if (!HasEnoughSpace(len_ + 1)) {
                Resize(actual_len_*2 + 1);
        }
        data_[len_] = new_element;
        len_ ++;
}

template<typename Type>
Type
Array<Type>::Pop()
{
}

template<typename Type>
Type&
Array<Type>::operator[](unsigned index)
{
}

template<typename Type>
Type const&
Array<Type>::operator[](unsigned index) const
{
}


template<typename Type>
Type&
Array<Type>::Front()
{
}

template<typename Type>
Type const&
Array<Type>::Front() const
{
}

template<typename Type>
Type&
Array<Type>::Back()
{
}

template<typename Type>
Type const&
Array<Type>::Back() const
{
}


template<typename Type>
typename Array<Type>::Iterator
Array<Type>::Erase(Array<Type>::Iterator const& it)
{
}


template<typename Type>
typename Array<Type>::Iterator
Array<Type>::Begin() const
{
}

template<typename Type>
typename Array<Type>::Iterator
Array<Type>::End() const
{
}

template<typename Type>
Array<Type>::Iterator::Iterator(/* Add necessary arguments to construct this iterator */)
{
}

template<typename Type>
Array<Type>::Iterator::Iterator(Iterator const& other)
{
}

template<typename Type>
Array<Type>::Iterator::~Iterator()
{
}

template<typename Type>
typename Array<Type>::Iterator&
Array<Type>::Iterator::operator=(Iterator const& other)
{
}

template<typename Type>
typename Array<Type>::Iterator
Array<Type>::Iterator::operator+(unsigned offset) const
{
}

template<typename Type>
typename Array<Type>::Iterator
Array<Type>::Iterator::operator-(unsigned offset) const
{
}

template<typename Type>
typename Array<Type>::Iterator&
Array<Type>::Iterator::operator++()
{
}

template<typename Type>
typename Array<Type>::Iterator&
Array<Type>::Iterator::operator--()
{
}

template<typename Type>
bool
Array<Type>::Iterator::operator==(Iterator const& other) const
{
}

template<typename Type>
bool
Array<Type>::Iterator::operator!=(Iterator const& other) const
{
}

template<typename Type>
Type&
Array<Type>::Iterator::operator*()
{
}

#endif // ARRAY_H
