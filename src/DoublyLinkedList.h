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
    explicit DoublyLinkedList(const std::vector<T> &values): head(nullptr), tail(nullptr), size_of_list(0) {
        for (const auto& val : values) {
            push_back(val);
        }
    }

    //create an empty DoublyLinkedList
    DoublyLinkedList(): head(nullptr), tail(nullptr), size_of_list(0) {
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
        size_of_list = 0;
    }

    //get a reference to the front element in the list
    const T &front() const {
        if (empty()) {throw DoublyLinkedListEmptyError();}
        return head -> value;
    }

    T &front() {
        if (empty()) {throw DoublyLinkedListEmptyError();}
        return head -> value;
    }

    //get a reference to the last element in the list
    [[nodiscard]] const T &back() const {
        if (empty()) throw DoublyLinkedListEmptyError();
        return tail -> value;
    }

    [[nodiscard]] T &back() {
        if (empty()) throw DoublyLinkedListEmptyError();
        return tail -> value;
    }

    //add a value to the front of the list
    void push_front(const T &value) {
        Node_Ptr newNode = new DoublyLinkedNode<T>(value);
        if (empty()) {
            tail = newNode;
            head = newNode;
        }
        else {
            newNode -> next = head;
            newNode -> prev = nullptr;
            head -> prev = newNode;
            head = newNode;
        }
        size_of_list++;

    }

    //add a value to the back of the list
    void push_back(const T &value) {
        Node_Ptr newNode = new DoublyLinkedNode<T>(value);
        if (empty()) {
            tail = newNode;
            head = newNode;
        } else {
            newNode -> prev = tail;
            newNode -> next = nullptr;
            tail -> next = newNode;
            tail = newNode;
        }
        size_of_list++;
    }

    void pop_front() {
        if (empty()) {throw DoublyLinkedListEmptyError();}
        if (size_of_list == 1) {
            Node_Ptr temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        else {
            //the head is now the previous
            Node_Ptr temp = head;
            head = head -> next;
            head -> prev = nullptr;
            delete temp;
        }

        size_of_list--;
    }

    void pop_back() {
        if (empty()) {throw DoublyLinkedListEmptyError();}
        if (size_of_list == 1) {
            Node_Ptr temp = tail;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        else {
            Node_Ptr temp = tail;
            tail = tail -> prev;
            tail -> next = nullptr;
            delete temp;

        }
        size_of_list--;
    }

    //is the list empty?
    [[nodiscard]] bool empty() const {
        return tail == nullptr;
    }

    //return the number of elements in the list
    [[nodiscard]] int size() const {
        return size_of_list;
    }

    //return a constant bidirectional iterator to the front of the list
    [[nodiscard]] const_iterator begin() const {
        return const_iterator(head);
    }

    [[nodiscard]] const_iterator end() const {
        return const_iterator(nullptr);
    }

    //return a nonconstant bidirectional iterator to the front of the list
    [[nodiscard]] iterator begin() {
        return iterator(head);
    }

    [[nodiscard]] iterator end() {
        return iterator(nullptr);
    }

    [[nodiscard]] const_reverse_iterator crbegin() const {
        return const_reverse_iterator(tail);
    }

    [[nodiscard]] const_reverse_iterator crend() const {
        return const_reverse_iterator(nullptr);
    }

    [[nodiscard]] reverse_iterator rbegin() {
        return reverse_iterator(tail);
    }

    [[nodiscard]] reverse_iterator rend() {
        return reverse_iterator(nullptr);
    }

    //insert the value at the position in the list
    //I promise not to use the iterator again after the insertion is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And the iterator was pointing to the 9 and we wanted to
    //insert -22 the result would be
    //1 <-> 22 <-> 9 <-> 17
    void insert(iterator &position, const T &value) {
        if (empty()) {push_back(value);}
        else if (position.getCurNode() == head) push_front(value);
        else if (position.getCurNode() == nullptr) push_back(value);
        else {
            Node_Ptr newNode = new DoublyLinkedNode<T>(value, position.getCurNode(), position.getCurNode()->prev);
            position.getCurNode()->prev->next = newNode;
            position.getCurNode()->prev = newNode;
            size_of_list++;
        }
    }

    //remove the element at the position pointed to
    //by the iterator.
    //I promise not to use the iterator again after the erase is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And when the wanted to erase the iterator was at the 9
    //1 <-> 17
    void erase(iterator &position) {
        if (empty()) {throw DoublyLinkedListEmptyError();}
        if (position.getCurNode() == head) pop_front();
        else if (position.getCurNode() == tail) pop_back();
        else {
            Node_Ptr temp = position.getCurNode();
            temp->next->prev = temp -> prev;
            temp->prev->next = temp -> next;
            delete temp;
            size_of_list--;
        }
    }


private:
    // your class members
    DoublyLinkedNode<T>* head;
    DoublyLinkedNode<T>* tail;
    int size_of_list =0;

};


//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream &operator<<(std::ostream &out, const DoublyLinkedList<T> &doublyLinkedList) {
    bool first = true;
    for (const auto& val : doublyLinkedList) {
        if (!first) out << " ";
        out << val;
        first = false;
    }
    return out;
}

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream &operator>>(std::istream &in, DoublyLinkedList<T> &doublyLinkedList) {
    T value;
    while (in.good() && in.peek() != '\n') {
        if (in >> value) {
            doublyLinkedList.push_back(value);
        } else {
            break;
        }
    }

    if (in.peek() == '\n') in.ignore();
    return in;

}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H