#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

template<typename t>
class DynamicArray {
private:
    int size;
    int capacity;
    t *a;

    void resize(int newCapacity) {
        t *b = new t[newCapacity];

        for (int i = 0; i < size; i++) {
            b[i] = a[i];
        }
        delete[] a;
        a = b;
        capacity = newCapacity;
    }

    void swap(t &x, t &y) {
        t temp = x;
        x = y;
        y = temp;
    }

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        t L[n1]; t R[n2];

        for (int i = 0; i < n1; ++i)
            L[i] = a[left + i];
        for (int i = 0; i < n2; ++i)
            R[i] = a[mid + 1 + i];

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                a[k] = L[i];
                ++i;
            } else {
                a[k] = R[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            a[k] = L[i];
            ++i;
            ++k;
        }

        while (j < n2) {
            a[k] = R[j];
            ++j;
            ++k;
        }
    }

    void mergeSortHelper(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSortHelper(left, mid);
            mergeSortHelper(mid + 1, right);

            merge(left, mid, right);
        }
    }

public:
    // Non-const version (already exists)
    t& operator[](int index) {
        if (index >= size || index < 0) {
            throw std::out_of_range("Array index out of range");
        }
        return a[index];
    }

    // Const version (add this)
    const t& operator[](int index) const {
        if (index >= size || index < 0) {
            throw std::out_of_range("Array index out of range");
        }
        return a[index];
    }

    DynamicArray<t>& operator=(const DynamicArray<t>& other) {
        if (this != &other) {
            delete []a;

            size = other.size;
            capacity = other.capacity;
            a = new t[capacity];
            for (int i = 0; i < size; ++i) {
                a[i] = other[i];
            }
        }
        return *this;
    }


    DynamicArray(int capacity = 2) : capacity(capacity), size(0) {
        a = new t[capacity];
    }

    ~DynamicArray() {
        delete []a;
    }

    DynamicArray(const DynamicArray<t>& other) {
        size = other.size;
        capacity = other.capacity;
        a = new t[capacity];
        for (int i = 0; i < size; ++i) {
            a[i] = other[i];
        }
    }


    void append(t element) {
        if(size == capacity) {
            resize(2 * capacity);
        }

        a[size] = element;
        size++;
    }

    void insert(t element, int index) {
        if(size == capacity) {
            resize(2 * capacity);
        }
        if(index >= size) {
            throw std::out_of_range("ERROR: Invalid index");
        }

        for(int i = size-1; i >= index; i--) {
            a[i+1] = a[i];
        }

        a[index] = element;
        size++;
    }


    void delete_end() {
        size--;

        if(size <= capacity/4) {
            resize(capacity/2);
        }
    }

    void delete_at(int index) {
        if(size <= capacity/4) {
            resize(capacity/2);
        }
        for(int i = index; i < size-1; i++) {
            a[i] = a[i+1];
        }

        size--;
    }

    void clearAll() {
        size = 0;
        resize(2);
    }


    t getElement(int index) {
        return a[index];
    }

    int getSize() const {
        return size;
    }

    void reverse() {
        int l = 0, r = size - 1;
        while(l < r) {
            swap(a[l], a[r]);
            l++; r--;
        }
    }

    void mergeSort() {
        mergeSortHelper(0, size - 1);
    }

    int linear_search(t element) {
        for(int i = 0; i < size; i++) {
            if(a[i] == element) {
                return i;
            }
        }
        return -1;

    }

    int binary_search(t element) {
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] == element) {
                return mid;
            } else if (a[mid] < element) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;  // Return -1 if element is not found
    }

    string getCuttedElements() {
        string elements = "";
        elements += a[0];
        if(size > 1) elements += ", ...";
        return elements;
    }

    string getFullElements() {
        string elements = "";
        for(int i = 0; i < size; i++) {
            elements += a[i] + ", ";
        }
        return elements;
    }

    void displayList() {
        if(size == 0) {
            cout << "No Elements Have Been Added Yet! Try Adding a one or loading them from a file." << endl;
        }
        for (int i = 0; i < size; ++i) {
            cout << left << "| " << setw(3) << i << a[i] << endl;
        }
    }
};

#endif //ARRAY_H
