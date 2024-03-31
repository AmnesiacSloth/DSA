#include "asLinkedList.h"
#include <exception>
#include <stack> // for use in reversal
template <typename Data>
asLinkedList<Data>::Node::Node(Data element, asLinkedList::Node *nodePtr) {
    data = element;
    next = nodePtr;
}
template <typename Data>
asLinkedList<Data>::Node::~Node() = default;

template <typename Data>
asLinkedList<Data>::~asLinkedList(){
    Node *current = Head;
    while (current!=nullptr) {
        Node *toDelete = current;
        current = current->next;
        delete toDelete;
    }
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
    return ptr->data;
}

template <typename Data>
void asLinkedList<Data>::pushFront(Data element) {
    Head = new Node(element, Head); // set head to new node while still preserving order
    if (Tail == nullptr) { // empty list case, head and tail both point to the single element in the list
        Tail = Head;
    }
   count++;
}

template <typename Data>
Data asLinkedList<Data>::popFront() {
    Node *ptr = Head;
    // empty cases
    if (ptr == nullptr) {
        throw std::out_of_range("No element to pop!");
    }
    Head = Head->next;
    // one element case
    if (Head == nullptr) {
        Tail = nullptr;
    }
    // multiple element case
    Data deepCopy = ptr->data;
    delete ptr;
    count--;
    return deepCopy;

}

template <typename Data>
void asLinkedList<Data>::pushBack(Data value) {
    Node *ptr = new Node( value, nullptr );
    // case empty
    if (isEmpty()) {
        Head = ptr;
        Tail = ptr;
        count++;
        return;
    }
    // set old tail to point to newly inserted node
    Tail->next = ptr;
    Tail = ptr; // tail now points to actual last elem in list
    count++;
}


template <typename Data>
Data asLinkedList<Data>::popBack() {
    if (isEmpty()) {
        throw std::out_of_range("No elements to pop!");
    }
    //case 1 elem
    if (Tail == Head) {
        Data returnVal = Tail->data;
        count--;
        delete Tail;
        Tail = nullptr;
        Head = nullptr;
        return returnVal;
    }
    // find 2nd to last node
    Node *ptr = Head;
    while (ptr->next != Tail) {
        ptr = ptr->next;
    }
    Data deep = Tail->data;
    count--;
    delete Tail;
    Tail = ptr;
    Tail->next = nullptr;
    return deep;
}

template <typename Data>
Data asLinkedList<Data>::front() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty!");
    }
    return Head->data;
}

template <typename Data>
Data asLinkedList<Data>::back() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    return Tail->data;
}

template <typename Data>
void asLinkedList<Data>::insert(size_t idx, Data value) {
    // out of bounds
    if (idx > getSize()) {
        throw std::out_of_range("invalid index! No node at specified index");
    }
    // insert at front
    if (idx == 0) {
        pushFront(value);
        return;
    }
    // insert as the last element or in middle
    Node *current = Head;
    // idx -1 is safe here because we handle 0 case, size_t variable will not underflow
    // iterate till position right before insertion point
    for (size_t i = 0; i < idx-1;  i++) {
        current = current->next;
    }
    // instantiate node and set up next pointers
    Node *ptr = new Node(value,current->next);
    current->next = ptr;
    // if our index is meant to be the last element, then set up tail pointer
    if (idx == getSize()) {
        Tail = ptr;
    }
    count++;
}


template <typename Data>
void asLinkedList<Data>::erase(size_t idx) {
    if (idx >= getSize()) {
        throw std::out_of_range("Invalid index!");
    }
    if (idx == 0) {
        popFront();
        return;
    }
    Node *ptr = Head;
    for (size_t i = 0; i < idx-1; i++) {
        ptr = ptr->next;
    }
    Node *toDelete = ptr->next;
    ptr->next = ptr->next->next;
    // If deleting current tail, align new tail
    if (Tail == toDelete) {
        Tail = ptr;
    }
    delete toDelete;
    count--;
}

template <typename Data>
Data asLinkedList<Data>::valueNFromEnd(size_t n) {
    if (n >= getSize()) {
        throw std::out_of_range("Impossible to traverse " + std::to_string(n) + " positions from end!");
    }
    // implement two pointer technique!
    /*
     *  The two-pointer technique is often highlighted for its versatility, particularly in problems where maintaining
     *  a specific gap or relationship between two elements as you traverse the list is beneficial. It's a pattern
     *  widely used in various linked list problems, such as detecting cycles, finding the middle element, or in this
     *  case, accessing an element a certain distance from the end without explicitly calculating its distance from
     *  the start.
     */
    Node *first = Head;
    Node *second = Head;
    // create a gap of n-1 nodes between both pointers
    // or a gap of n movement operations
    for (size_t i = 0; i < n; i++) {
        second = second->next;
    }
    // while 2nd pointer hasnt reached end, keep moving both pointers!
    while (second->next != nullptr) {
        first = first->next;
        second = second->next;
    }
    // first should point to element N positions away from
    return first->data;
}

template <typename Data>
void asLinkedList<Data>::reverse() {
    std::stack<Node*> reversalStack;
    Node *current = Head;
    for (size_t i = 0; i < getSize(); i++) {
        reversalStack.push(current);
        current = current->next;
    }
    // pop first element and set it as new head
    current = reversalStack.top();
    reversalStack.pop();
    Head = current;
    // keep setting next pointers and popping from stack
    while (!reversalStack.empty()) {
        current->next = reversalStack.top();
        reversalStack.pop();
        current = current->next;
    }
    current->next = nullptr; // must set tails pointer to nullptr !!!
    Tail = current; // final element is popped, trivially must be the new tail of the list;
}

template <typename Data>
void asLinkedList<Data>::removeValue(Data value) {
    Node *current = Head;
    Node *prev = nullptr;
    if (Head == nullptr) {
        throw std::invalid_argument("List is empty!");
    }
    // edge case
    if (Head->data == value) {
        popFront();
        return;
    }
    // middle / end of list case
    while(current != nullptr) {
        // found value
        if (current->data == value) {
            // keep link integrity
            prev->next = current->next;
            // last element in list
            if (current == Tail) {
                Tail = prev;
            }
            // fix instance variables and free memory
            delete current;
            count--;
            return;
        }
        // continue iterating
        prev = current;
        current = current->next;
    }
    throw std::invalid_argument("Value does not exist in list!");
}