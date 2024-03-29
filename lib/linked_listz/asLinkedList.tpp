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
    if (idx >= getSize() || idx < 0) {
        throw std::range_error("");
    }
    Node *ptr = Head;
    for (int i = 0; i < idx; i++) {
        ptr = ptr->next;
    }
}





