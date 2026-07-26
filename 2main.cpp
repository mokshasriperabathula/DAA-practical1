#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to perform Linear Search
int linearSearch(vector<int> numbers, int target)
{
    int size = numbers.size();

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == target)
        {
            return i;
        }
    }

    return -1;
}

// Function to perform Binary Search
int binarySearch(vector<int> numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == target)
        {
            return middle;
        }
        else if (numbers[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}

int main()
{
    int size = 100000;
    vector<int> numbers(size);

    // Store values from 1 to 100000
    for (int i = 0; i < size; i++)
    {
        numbers[i] = i + 1;
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int position;

    // Measure Linear Search Time
    auto begin = high_resolution_clock::now();
    position = linearSearch(numbers, target);
    auto end = high_resolution_clock::now();

    cout << "\n----- Linear Search -----\n";

    if (position >= 0)
    {
        cout << "Element found at index: " << position << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    cout << "Execution Time: "
         << duration_cast<microseconds>(end - begin).count()
         << " microseconds\n";

    // Measure Binary Search Time
    begin = high_resolution_clock::now();
    position = binarySearch(numbers, target);
    end = high_resolution_clock::now();

    cout << "\n----- Binary Search -----\n";

    if (position >= 0)
    {
        cout << "Element found at index: " << position << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    cout << "Execution Time: "
         << duration_cast<microseconds>(end - begin).count()
         << " microseconds\n";

    return 0;
}
