#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename t>
class StaticArray {
private:
    int size;
    int capacity;
    t a[];

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
    t& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("ERROR: Invalid index");
        }
        return a[index];  // return the element at index
    }

    StaticArray(int capacity) : capacity(capacity), size(0) {
        a[capacity];
    }

    StaticArray(const StaticArray<t> &b) {
        a[b.capacity];
        size = b.size;
        capacity = b.capacity;
        for (int i = 0; i < size; ++i) {
            a[i] = b[i];
        }
    }

    void append(t element) {
        if(size == capacity) {
            throw std::out_of_range("ERROR: Array is full");
        }

        a[size] = element;
        size++;
    }

    void insert(t element, int index) {
        if(size == capacity) {
            throw std::out_of_range("ERROR: Array is full");
        }
        if(index > size) {
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
    }

    void delete_at(int index) {
        for(int i = index; i < size-1; i++) {
            a[i] = a[i+1];
        }

        size--;
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

    int linearSearch(t element){
        for(int i = 0; i < size; i++){
            if(a[i] == element){
                return i;
            }
        }
        return -1;
    }

    void displayArray() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << a[i] << ", ";
        }
        cout << "]" << endl;
    }
};

#endif //ARRAY_H
