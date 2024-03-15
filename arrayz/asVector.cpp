#include "asVector.h"

static const int ERROR_FLAG = -1;
static const float DOUBLE = 2.0;
static const float HALF = 0.5;
class asVector{
    asVector::asVector() {
        data = new int[INIT_SIZE];
        capacity = INIT_SIZE;
        size = 0;
    }
    asVector::~asVector(){
        delete data;
    }


    bool asVector::resize(int factor) {
        capacity = capacity*factor;
        int* tmp = new int[capacity];
        for (int i = 0; i < size; i++) {
            tmp[i] = data[i]
        }
        delete data;
        data = tmp;
    }
    int asVector::size(){
        return size;
    }

    int asVector::capacity() {
        return this->capacity;
    }

    bool asVector::isEmpty(){
        return (size == 0);
    }

    int asVector::at(int idx) {
        // check for mem boundaries
        if (idx >= 0  && idx < this->size) {
            return this->data[idx];
        }
        else {
            std::cout<< "invalid index!" << std::endl;
            return ERROR_FLAG;
        }
    }

    bool asVector::push(int element) {
        if (this->size == this->capacity) {
            resize();
        }
        this->data[size] = element;
        size++;
        return true;
    }

    bool asVector::insert(int element, int idx) {
        // Seg fault check
        if (idx < 0 || idx >=this->size) {
            return false;
        }
        size++; // update new elem count since we know insertion will succeed, and account for resizing
        if (this->size == capacity) {
            resize();
        }
        // reverse iterate through rest of the array pushing everything to the "right"
        for (int i = size; i >= idx; i--) {
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
        int tmp = data[0];
        size--;
        for (int i = 0; i < size; i++) {
            data[i] = data[i+1];
        }
        data[size] = 0; // everything got pushed up so remove data from the old "last" element's index
        return tmp;
    }

    bool asVector::delete(int idx) {
        // Seg fault check
        if (idx < 0 || idx >=this->size) {
            return false;
        }

        for (int i =idx; idx < size;i++) {
            data[i] = data[i+1];
        }
        size--;
        data[size] = 0;
        return true;
    }

    // How to fix so that array elements stay contiguous?
    int asVector::remove(int element) {
        int removeCount = 0;
        for (int i =0; i < size;i++) {
            if (data[i] == element) {
                data[i] = 0;
                removeCount++;
            }

        }
        size = size-removeCount;
        return removeCount;

    }

    int asVector::find(int element) {
        for (int i =0; i<size;i++) {
            if (data[i] == element) {
                return i;
            }
        }
        return ERROR_FLAG;
    }

};