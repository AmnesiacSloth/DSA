#include "asLinkedList.h"
#include <exception>
template <typename Data>
asLinkedList<Data>::Node::Node(Data element, asLinkedList::Node *nodePtr) {
    data = element;
    next = nodePtr;
}

// dont define destructor for node its trivial
// NO SENTINEL NODE IN THIS IMPLEMENTATION
template<typename Data>
asLinkedList<Data>::asLinkedList() {
    Head = nullptr;
    Tail = nullptr;
    count = ZERO;
}

template<typename Data>
size_t asLinkedList<Data>::getSize() const{
    return count;
}

template<typename Data>
bool asLinkedList<Data>::isEmpty() const {
    return (count == ZERO);
}

template<typename Data>
Data asLinkedList<Data>::valueAt(size_t idx) const {
    // bounds check
    // cool aside, size_t is unsigned integer, can never be < 0!!!
    if (idx >= getSize()) {
        throw std::out_of_range("Invalid index passed!");
    }
    Node *ptr = Head;
    for (size_t i = 0; i < idx; i++) {
        ptr = ptr->next;
    }
    return ptr.data;
}

template <typename Data>
void asLinkedList<Data>::pushFront(Data element) {
    head = new Node(element, head); // set head to new node while still preserving order
    if (tail == nullptr) { // empty list case, head and tail both point to the single element in the list
        tail = head;
    }
   count++;
}

template <typename Data>
Data asLinkedList<Data>::popFront() {
    Node *ptr = head;
    // empty cases
    if (ptr == nullptr) {
        throw std::range_error("No element to pop!");
    }
    head = head->next;
    // one element case
    if (head == nullptr) {
        tail = nullptr;
    }
    // multiple element case
    Data deepCopy = ptr->data;
    delete ptr;
    count--;
    return deepCopy;

}






