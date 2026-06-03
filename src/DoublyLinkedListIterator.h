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



  //are the two iterators equal?
  bool operator==(const DoublyLinkedListIterator<T> &rhs) const {
   return this->curNode == rhs.curNode; //is my current position
  }

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T> &rhs) const {
   return this->curNode != rhs.curNode;
  }

  //is the iterator safe to dereference?
  explicit operator bool() const {
  }

  //go to the next element
  DoublyLinkedListIterator<T> &operator++() {
   return this->curNode = this->curNode->getNext();
  }

  //pre
  const DoublyLinkedListIterator<T> operator++(int) {
    return this->curNode = this->curNode->getNext();
  }

  //post

  //go to the previous element
  DoublyLinkedListIterator<T> &operator--() {
   return this->curNode = this->curNode->getPrevious();
  }

  //pre
  const DoublyLinkedListIterator<T> operator--(int); //post

  //get a reference to the value
  [[nodiscard]] const_reference operator*() const;
  [[nodiscard]] reference operator*();

  DoublyLinkedNode<T>*& getCurNode();
  const DoublyLinkedNode<T>*& getCurNode() const;

 private:
  DoublyLinkedNode<T>* curNode;
};



#endif //DLLPROJECT_DOUBLYLINKEDLISTITERATOR_H
