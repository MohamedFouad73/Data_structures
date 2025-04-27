#include <iostream>
#include <cmath>
template <class t>
class Array {

private:
    int size; // reserved places
    t* accessing_ptr; //ptr for accessing data stored in heap
    int length; // number of assigned indexes

public:

    Array(int arrSize) {
        length = 0;
        this->size = arrSize;
        accessing_ptr = new t[arrSize];
        for (size_t i = 0; i < arrSize ; i++) {
            accessing_ptr[i] = t();
        }
    }

    ~Array() {
        delete[] accessing_ptr;
    }
    // setting a value
    void set(int index , t value) {
        accessing_ptr[index] = value;
        length ++;
    }
    // fetching a value
    t get(int index) {
        return accessing_ptr[index];
    }
    // removing a value by index
    void remove(int index) {
        accessing_ptr[index] = t();
        length--;
    }
    // gets the size reserved
    int getSize() const {
        return size;
    }
    // gets the number of values set
    int getLength() const {
        return length;
    }
    // Displaying the whole array in this format [val1 , val2 ... ]
    void display() const {

        std::cout<<"[";
        for (size_t i = 0; i < size; i++) {
            if (i == size - 1)
                std::cout<<accessing_ptr[i]<<"]"<<std::endl;
            else
                std::cout<<accessing_ptr[i]<<" , ";
        }

    }
    // Merges two arrays of the same type
    Array merge(const Array<t>& arr2) {

        int mergedSize = this->size + arr2.getSize();
        Array merged(mergedSize);

        for (size_t i = 0; i < this->size; i++) {
            merged.set(i, this->get(i));
        }

        for (size_t i = 0; i < arr2.getSize(); i++) {
            merged.set(this->size + i, arr2.get(i));
        }

        return merged;
    }






int main() {
    Array<int> arr1(5);
    arr1.display();
    arr1.set(0 , 5);
    std::cout<<arr1.get(0)<<std::endl;
    std::cout<<arr1.getLength();

}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.