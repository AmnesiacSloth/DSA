#include "asVector.h"

static const int ERROR_FLAG = -1;
static const float DOUBLE = 2.0;
static const float HALF = 0.5;
static const int MINIMUM_CAPACITY = 16;
    asVector::asVector() {
        data = new int[INIT_SIZE];
        capacity = INIT_SIZE;
        size = 0;
    }
    asVector::~asVector(){
        delete[] data;
    }

    bool asVector::resize(float factor) {
        capacity = (size_t)((float)capacity*factor); // cast after float op
        int* tmp = new int[capacity];
        for (size_t i = 0; i < size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
        return true;
    }
    int asVector::getSize() const {
        return size;
    }

    int asVector::getCapacity() const {
        return capacity;
    }

    bool asVector::isEmpty() const{
        return (getSize() == 0);
    }

    int asVector::at(int idx) {
        // check for mem boundaries
        if (idx >= 0  && idx < getSize()) {
            return data[idx];
        }
        else {
            std::cout<< "invalid index!" << std::endl;
            return ERROR_FLAG;
        }
    }

    bool asVector::push(int element) {
        if (getSize() >= getCapacity()/2) { // == MUST MATCH, >= account for going over capacity, whether by 1 or 50
            resize(DOUBLE);
        }
        data[size] = element;
        size++;
        if (getSize() >= getCapacity()/2) {
            resize(DOUBLE);
        }
        return true;
    }

    bool asVector::insert(int element, int idx) {
        // Seg fault check
        if (idx < 0 || idx >= getCapacity()) {
            return false;
        }
        size++; // update new elem count since we know insertion will succeed, and account for resizing
        if (getSize() >= getCapacity()/2) {
            resize(DOUBLE);
        }
        // reverse iterate through rest of the array pushing everything to the "right"
        for (size_t i = size-1; i > idx; i--) {
            data[i] = data[i-1];
        }
        // now insert in empty position
        data[idx] = element;
        return true; // success!
    }

    bool asVector::prepend(int element) {
        return insert(element, 0);
    }

    /**
     * Size must be < capacity-1 for this to function correctly
     * Otherwise we are at risk of accessing out of bounds?
     */
    int asVector::pop() {
        // if empty
        if (isEmpty()) {
            return -1;
        }
        int tmp = data[0];
        size--;
        // Ensures that array doesn't shrink below 16 elements
        if (getSize() <= getCapacity()/4 && getCapacity() > MINIMUM_CAPACITY ) {
            resize(HALF);
        }
        for (int i = 0; i < getSize(); i++) {
            data[i] = data[i+1];
        }
        data[size] = 0; // everything got pushed up so remove data from the old "last" element's index
        return tmp;
    }

    bool asVector::deleteAt(int idx) {
        // Seg fault check
        if (idx < 0 || idx >= getSize()) {
            return false;
        }

        for (int i =idx; i < getSize();i++) {
            data[i] = data[i+1];
        }
        size--;
        if (getSize() <= getCapacity()/4) { // Issue if capacity ever reaches like 1 or 2?
            resize(HALF);
        }
        data[getSize()] = 0;

        return true;
    }

    // How to fix so that array elements stay contiguous?
    int asVector::remove(int element) {
        int removeCount = 0;
        int found = find(element);
        // while still elements to remove
        while(found != -1) {
            // edge case, found last element, remove and data stays contiguous
            if (found == getSize()-1) {
                data[found] = 0;
                size--;
                removeCount++;
                return removeCount;
            }
            // from found -> end of array, shift elements over to the left once
            for (int i = found; i < getSize(); i++) {
                data[i] = data[i+1];
            }
            // update count since elements have now been removed
            size--;
            removeCount++;
            found = find(element); // update found var
        }
        // check if we need to resize
        if (getSize() <= getCapacity()/4) {
            resize(HALF);
        }
        return removeCount;
    }

    int asVector::find(int element) {
        for (size_t i = 0; i<getSize();i++) {
            if (data[i] == element) {
                return (int)i;
            }
        }
        return ERROR_FLAG;
    }