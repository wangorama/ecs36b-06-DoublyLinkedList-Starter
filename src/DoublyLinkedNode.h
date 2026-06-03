//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.h"

template<typename T>
class DoublyLinkedNode {
    friend class DoublyLinkedList<T>;

 public:
    DoublyLinkedNode(T value): value(value), next(next), prev(prev) {}

 private:
    T value;
    DoublyLinkedNode<T>* next;
    DoublyLinkedNode<T>* prev;

};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
