//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include <ranges>

#include "DoublyLinkedNode.h"
#include "DoublyLinkedListEmptyError.h"
#include "ConstDoublyLinkedListIterator.h"
#include "DoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedIterator.h"
#include "ReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
public:
    using Node_Ptr = DoublyLinkedNode<T>*;

    using iterator = DoublyLinkedListIterator<T>; //put the type of your iterator here
    using const_iterator = ConstDoublyLinkedListIterator<T>; //put the type of your const iterator here
    using reverse_iterator = ReverseDoublyLinkedListIterator<T>; //put the type of your reverse iterator here
    using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>;
    //put the type of your const reverse iterator here

    //create a Doubly Linked List that has the same values
    //as in the vector and in the same order
    explicit DoublyLinkedList(const std::vector<T>& values);

    //create an empty DoublyLinkedList
    DoublyLinkedList(): head(nullptr), tail(nullptr) {
        //nullptr means its pointing to nothing, soo really nullptr is another word for 0
    }

    virtual ~DoublyLinkedList() {
        clear();
    }

    //remove all of the elements from your list
    void clear() {
        Node_Ptr current = head;
        while (current != nullptr) {
            Node_Ptr next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    //get a reference to the front element in the list
    const T &front() const {
        if (head == nullptr) {throw DoublyLinkedListEmptyError();}
        return head -> value;
    }

    T &front() {
        if (head == nullptr) {throw DoublyLinkedListEmptyError();}
        return head -> value;
    }

    //get a reference to the last element in the list
    [[nodiscard]] const T &back() const {
        if (tail == nullptr) throw DoublyLinkedListEmptyError();
        return tail -> value;
    }

    [[nodiscard]] T &back() {
        if (tail == nullptr) throw DoublyLinkedListEmptyError();
        return tail -> value;
    }

    //add a value to the front of the list
    void push_front(const T &value) {

    }

    //add a value to the back of the list
    void push_back(const T &value) {
    }

    //is the list empty?
    [[nodiscard]] bool empty() const {

    }

    //return the number of elements in the list
    [[nodiscard]] int size() const {
    }

    //return a constant bidirectional iterator to the front of the list
    [[nodiscard]] const_iterator begin() const {
    }

    [[nodiscard]] const_iterator end() const {
    }

    //return a nonconstant bidirectional iterator to the front of the list
    [[nodiscard]] iterator begin() {
    }

    [[nodiscard]] iterator end() {
    }

    [[nodiscard]] const_reverse_iterator crbegin() const {
    }

    [[nodiscard]] const_reverse_iterator crend() const {
    }

    [[nodiscard]] reverse_iterator rbegin() {
    }

    [[nodiscard]] reverse_iterator rend() {
    }

    //insert the value at the position in the list
    //I promise not to use the iterator again after the insertion is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And the iterator was pointing to the 9 and we wanted to
    //insert -22 the result would be
    //1 <-> 22 <-> 9 <-> 17
    void insert(iterator &position, const T &value) {
    }

    //remove the element at the position pointed to
    //by the iterator.
    //I promise not to use the iterator again after the erase is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And when the wanted to erase the iterator was at the 9
    //1 <-> 17
    void erase(iterator &position) {
    }

private:
    // your class members
    DoublyLinkedNode<T>* head;
    DoublyLinkedNode<T>* tail;

};


//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream &operator<<(std::ostream &out, const DoublyLinkedList<T> &doublyLinkedList) {
}

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream &operator>>(std::istream &in, DoublyLinkedList<T> &doublyLinkedList) {
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
