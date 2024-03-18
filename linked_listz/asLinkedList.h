#ifndef DSA_ASLINKEDLIST_H
#define DSA_ASLINKEDLIST_H
#include <iostream>
/**
* AmnesiacSloth custom implementation of mutable linked list with tail pointer
*/
class asLinkedList {
private:
public:
    /**
     * @TODO
     * @return
     */
    size_t getSize() const;

    /**
     * @TODO
     * @return
     */
    bool isEmpty() const;
    /**
     * @TODO
     * @param idx
     * @return
     */
    int valueAt(size_t idx) const;

    /**
     * @TODO
     * @param value
     */
    void pushFront(int value);

    /**
     * @TODO
     * @return
     */
    int popFront();

    /**
     * @TODO
     * @param value
     */
    void push_back(int value);
    /**
     * @TODO
     * @return
     */
    int popBack();
    /**
     * @TODO
     * @return
     */
    int front();
    /**
     * @TODO
     * @return
     */
    int back();
    /**
     * @TODO
     * @param idx
     * @param value
     */
    void insert(size_t idx, int value);
    /**
     * @TODO
     * @param idx
     */
    void erase(size_t idx);
    /**
     * @TODO
     * @param n
     * @return
     */
    int valueNFromEnd(size_t n);
    /**
     * @TODO
     */
    void reverse();
    /**
     * @TODO
     * @param value
     */
    void removeValue(int value);
}; // asLinkedList

#endif //DSA_ASLINKEDLIST_H