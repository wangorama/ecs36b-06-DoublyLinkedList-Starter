//
// Created by mfbut on 11/24/2019.
//

#ifndef DLLPROJECT_DOUBLYLINKEDLISTITERATOR_H
#define DLLPROJECT_DOUBLYLINKEDLISTITERATOR_H

#include <iterator>
#include "DoublyLinkedNode.h"

template <typename T>
class DoublyLinkedListIterator {
 public:
  using iterator_category = std::bidirectional_iterator_tag;
  using iterator_concept  = std::bidirectional_iterator_tag;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using difference_type = ptrdiff_t;



 DoublyLinkedListIterator(DoublyLinkedNode<T>* node):curNode(node){}

  //are the two iterators equal?
  bool operator==(const DoublyLinkedListIterator<T> &rhs) const {
   return this->curNode == rhs.curNode; //is my current position
  }

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T> &rhs) const {
   return not (*this == rhs);
  }

  //is the iterator safe to dereference?
  explicit operator bool() const {
   return this->curNode != nullptr;
  }

  //go to the next element
  DoublyLinkedListIterator<T> &operator++() {
   curNode = curNode->next;
   return *this;
  }

  //pre
  const DoublyLinkedListIterator<T> operator++(int) {
  DoublyLinkedListIterator<T> temp = *this; //temp variable is the current
  ++(*this); //then the actual original gets the changed by decrement
  return temp; //but because temp remains unchanged, the post decrement will return this
  //yet on the next iteration, it will finally show the decremented list
  }

  //post

  //go to the previous element
  DoublyLinkedListIterator<T> &operator--() {
   curNode = curNode->prev;
   return *this;
  }

  //pre
  const DoublyLinkedListIterator<T> operator--(int) {
  DoublyLinkedListIterator<T> temp = *this;
  --(*this);
  return temp;
  }

  //post

  //get a reference to the value
  [[nodiscard]] const_reference operator*() const {
   if (curNode == nullptr) {throw DoublyLinkedListOutOfBoundsError();}
   return (*curNode).value;
  }

  [[nodiscard]] reference operator*() {
   if (curNode == nullptr) {throw DoublyLinkedListOutOfBoundsError();}
   return (*curNode).value;
  }

  DoublyLinkedNode<T> *&getCurNode() {
    return curNode;
  }

  const DoublyLinkedNode<T> *&getCurNode() const {
   return curNode;
  }

 private:
  DoublyLinkedNode<T>* curNode;
};



#endif //DLLPROJECT_DOUBLYLINKEDLISTITERATOR_H
