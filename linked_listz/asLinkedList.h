#ifndef DSA_ASLINKEDLIST_H
#define DSA_ASLINKEDLIST_H
#include <iostream>
/**
* AmnesiacSloth custom implementation of mutable linked list with tail pointer
*/
template <typename Data> class asLinkedList {
private:
    /**
     * Simple internal node that my linked list implementation is composed of
     */
    struct Node {
        Data data;
        Node* next;

        Node(Data element, Node* next); // constructor
        ~Node(); // destructor
    };
public:
    /**
     * Constructor & Destructor
     */
    asLinkedList();
    ~asLinkedList();
    /**
     * Getter function for number of elements in the linked list
     * @return current number of elements in the Linked list
     */
    size_t getSize() const;

    /**
     * Tests whether or not a list has any elements in it
     * @return true if empty
     */
    bool isEmpty() const;
    /**
     * Retrieves element that is currently at the specified index
     * @param idx index to retrieve element from
     * @return data held in the node at given position
     */
    Data valueAt(size_t idx) const;

    /**
     * Retrieves element at the front of the list
     * @param value to be assigned as the first element in the list
     */
    void pushFront(Data element);

    /**
     * Retrieves and removes the first element in the list
     * @return the removed element
     */
    Data popFront();

    /**
     * Creates node holding data and inserts it to the back of the list
     * @param value to be inserted
     */
    void push_back(Data value);
    /**
     * Retrieves data and removes the last node in the list
     * @return data in the last node in the list
     */
    Data popBack();
    /**
     * Retrieves data held in the first node but does not remove node
     * @return data in the first node
     */
    Data front();
    /**
     * Retrieves data held in the last node but does not remove i
     * @return data in the last node
     */
    Data back();
    /**
     * Creates and inserts a node with given data at specified index
     * @param idx location to insert node
     * @param data to insert into node
     */
    void insert(size_t idx, Data value);
    /**
     * Erases and removes node in the list from specified address
     * @param idx to remove element from
     */
    void erase(size_t idx);
    /**
     * Returns data in node N positions from end of the list
     * @param n number of positions from end of the list
     * @return data in found node
     */
    Data valueNFromEnd(size_t n);
    /**
     * Reverses the ordering of elements in the list
     */
    void reverse();
    /**
     * Finds and removes first instance of data in the list
     * @param element to remove from list
     */
    void removeValue(Data value);
}; // asLinkedList

#endif //DSA_ASLINKEDLIST_H