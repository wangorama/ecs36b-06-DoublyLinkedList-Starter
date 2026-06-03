//
// Created by mfbut on 11/24/2019.
//

#ifndef DLLPROJECT_CONSTDOUBLYLINKEDLISTITERATOR_H
#define DLLPROJECT_CONSTDOUBLYLINKEDLISTITERATOR_H

#include <iterator>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListOutOfBoundsError.h"

template<typename T>
class ConstDoublyLinkedListIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using iterator_concept = std::bidirectional_iterator_tag;
    using value_type = T;
    using reference = const value_type&;
    using pointer = const value_type*;
    using difference_type = ptrdiff_t;

    //are the two iterators equal?
    bool operator==(const ConstDoublyLinkedListIterator<T> &rhs) const {
    }

    //are the two iterators different?
    bool operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const;

    //is the iterator safe to dereference?
    explicit operator bool() const;

    //go to the next element
    ConstDoublyLinkedListIterator<T>& operator++(); //pre
    const ConstDoublyLinkedListIterator<T> operator++(int); //post

    //go to the previous element
    ConstDoublyLinkedListIterator<T>& operator--(); //pre
    const ConstDoublyLinkedListIterator<T> operator--(int); //post

    //get a reference to the value
    [[nodiscard]] reference operator*() const;
};

#endif //DLLPROJECT_CONSTDOUBLYLINKEDLISTITERATOR_H
