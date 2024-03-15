#ifndef DSA_ASVECTOR_H
#define DSA_ASVECTOR_H

static const int INIT_SIZE = 16;

/* AmnesiacSloth custom implementation of multable array with auto resizing */
class asVector {
private:
    int * data;
    size_t capacity;
    size_t size;

    // when capacity reached, resize to double
    // when popping an element, if this causes array to reach 1/4 load, resize to half
    bool resize(int factor);
public:
    asVector();
    ~asVector();

    // return number of data elems in the list
    int size();
    // returns total # of elements that can fit in this array
    int capacity();
    // true if true :)
    bool isEmpty();
    // returns element at given index
    int at(int idx);
    // insert element at end of the array
    bool push(int element);
    // insert element at supplied index
    bool insert(int element,int idx);
    // insert element at 0th index
    bool prepend(int element);
    // remove and return the 0th element
    int pop();
    // remove element at given index, shifts all remaining elements to left
    bool delete(int idx);
    // remove all instances of element, return num of elements removed
    int remove(int element);
    // return first instance of element, -1 if none found
    int find(int element);

};


#endif //DSA_ASVECTOR_H
