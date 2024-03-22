#include "asLinkedList.h"

template <typename Data>
asLinkedList<Data>::Node::Node(Data element, asLinkedList::Node *nodePtr) {
    data = element;
    next = nodePtr;
}

// dont define destructor for node its trivial
// NO SENTINEL NODE IN THIS IMPLEMENTATION
template<typename Data>
asLinkedList<Data>::asLinkedList() {
    head = nullptr;
    tail = nullptr;
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
    if (idx)
}





