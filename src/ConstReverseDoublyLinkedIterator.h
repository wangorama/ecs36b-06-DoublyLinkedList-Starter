//
// Created by mfbut on 11/24/2019.
//

#ifndef DLLPROJECT_CONSTREVERSEDOUBLYLINKEDITERATOR_H
#define DLLPROJECT_CONSTREVERSEDOUBLYLINKEDITERATOR_H

#include <iterator>
#include "DoublyLinkedNode.h"

template<typename T>
class ConstReverseDoublyLinkedListIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using iterator_concept = std::bidirectional_iterator_tag;
    using value_type = T;
    using reference = const value_type&;
    using pointer = const value_type*;
    using difference_type = ptrdiff_t;

    //are the two iterators equal?
    bool operator==(const ConstReverseDoublyLinkedListIterator<T> &rhs) const {
        return this->curNode == rhs.curNode;
    }

    //are the two iterators different?
    bool operator!=(const ConstReverseDoublyLinkedListIterator<T> &rhs) const {
        return this -> curNode != rhs.curNode;
    }

    //is the iterator safe to dereference?
    explicit operator bool() const {
        return curNode != nullptr;
    }

    //go to the next element
    ConstReverseDoublyLinkedListIterator<T> &operator++() {
        curNode = curNode->prev;
        return *this;
    }

    //pre
    const ConstReverseDoublyLinkedListIterator<T> operator++(int) {
        curNode = curNode->prev;
        return *this;
    }

    //post

    //go to the previous element
    ConstReverseDoublyLinkedListIterator<T> &operator--() {
        curNode = curNode->next;
        return *this;
    }

    //pre
    const ConstReverseDoublyLinkedListIterator<T> operator--(int) {
        curNode = curNode->next;
        return *this;
    }

    //post

    //get a reference to the value
    [[nodiscard]] reference operator*() const {
        return *curNode;
    }

private:
    DoublyLinkedNode<T>* curNode;
};

#endif //DLLPROJECT_CONSTREVERSEDOUBLYLINKEDITERATOR_H
