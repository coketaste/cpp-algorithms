/*
    In the binary_search.cpp
    Algorithm: Binary Search
    yu.shao@amd.com

    Note of development:
*/
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

/*
template <typename T>: This line indicates the declaration of a C++ function template. It's a way to write a generic function that can work with different types (T). The angle brackets (< >) enclose the template parameters, and typename T defines a type parameter named T. This means you can use this function with any data type (int, double, string, etc.) when you call it.

int: This part of the function declaration specifies the return type of the function. In this case, the function returns an integer (int).

binary_search: This is the name of the function. It's the identifier you use to call the function later in your code.

(const std::vector<T> &list, const int &item): These are the function parameters enclosed in parentheses. Let's break them down further:

const std::vector<T> &list: This parameter is named list, and it's a reference (&) to a constant (const) std::vector of type T. 
This means you pass in a vector (std::vector) by reference, which is a way to avoid making a copy of the vector when you call the function. 
The const qualifier indicates that the vector should not be modified within the function.

const int &item: This parameter is named item, and it's a reference (&) to a constant (const) int. 
This is the target value you want to search for within the vector. By using a reference, you can access the value without making a copy, 
and const indicates that the value won't be modified within the function.

In summary, this function template binary_search is designed to perform a binary search on a std::vector of type T to find the specified item. 
It returns an integer index where the item is found in the vector (or -1 if not found). 
The use of templates makes this function flexible, allowing it to work with various data types for both the vector elements and the target item.

*/
template <typename T>
int binary_search(const std::vector<T> &list, const int &item)
{
    int low = 0;
    int high = list.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        T guess = list[mid];

        if (guess == item)
        {
            return mid;
        }

        if (guess > item)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

// this function returns pointer to the found element rather than array index
/*
This is a template function declaration in C++. Here's what each part of it means:

template <typename T>: This line indicates that we're declaring a template function. The <typename T> part specifies that T is a template type parameter. It means that this function can work with different data types (e.g., integers, floats, custom classes) based on what type is provided when the function is instantiated.

const T *: This is the return type of the function. It indicates that the binary_search2 function will return a pointer to a constant T. In other words, it will return a memory address pointing to an element of type T.

binary_search2: This is the name of the function. It's the identifier you use to call the function in your code.

(const std::vector<T> &list, const T &item): These are the function parameters enclosed within parentheses. They specify the input that the function expects. Let's break down each parameter:

const std::vector<T> &list: This is the first parameter. It is of type const std::vector<T> &, which means it's a reference to a constant vector of elements of type T. The list parameter represents the sorted list (or array) in which you want to perform a binary search.

const T &item: This is the second parameter. It is of type const T &, which means it's a reference to a constant element of type T. The item parameter represents the value you want to search for within the list.

In summary, this template function declaration specifies that it will take a sorted list (vector) of elements of type T and an element item of type T as input. It will return a pointer to a constant T. The function's purpose is to perform a binary search in the list for the specified item and return a pointer to the found element if found or a nullptr if not found. The use of templates allows this function to work with various data types, making it flexible and reusable. The use of references (&) indicates that the function will work with the original data without making unnecessary copies, and the const keyword ensures that the input parameters are not modified within the function.
*/
template <typename T>
const T *binary_search2(const std::vector<T> &list, const T &item)
{
    const T *low = &list.front();
    const T *high = &list.back();

    while (low <= high)
    {
        // "guess" is the element in the middle between "high" and "low"
        const T *guess = low + ((high - low) / 2);

        if (*guess == item)
            return guess;

        if (*guess > item)
        {
            high = guess - 1;
        }
        else
        {
            low = guess + 1;
        }
    }

    return nullptr;
}

int main()
{
    std::vector<int> my_list = {1, 3, 5, 7, 9};
    const int *binary_search2_result = binary_search2(my_list, 9);
    const int *binary_search2_null = binary_search2(my_list, 4); // test finding element that is not in the list

    cout << "Binary search for number 3: " << binary_search(my_list, 3) << endl;
    cout << "Binary search 2 for number 9 (memory address): " << binary_search2_result << endl;
    cout << "Binary search 2 for number 9 (value): " << *binary_search2_result << endl;

    if (binary_search2_null == nullptr)
    {
        cout << "4 was not found in the list" << endl;
    }

    return 0;
}
