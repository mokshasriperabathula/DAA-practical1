
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

// Manual Swap
void swapElements(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Max Heap
void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swapElements(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swapElements(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Min Heap
void minHeapify(vector<int> &arr, int n, int i)
{
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swapElements(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swapElements(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    for (int i = 0, j = n - 1; i < j; i++, j--)
        swapElements(arr[i], arr[j]);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
        original[i] = rand() % 100000;

    vector<int> maxHeapArray = original, minHeapArray = original;

    auto startMax = high_resolution_clock::now();
    maxHeapSort(maxHeapArray);
    auto endMax = high_resolution_clock::now();

    auto startMin = high_resolution_clock::now();
    minHeapSort(minHeapArray);
    auto endMin = high_resolution_clock::now();

    auto nanoMax = duration_cast<nanoseconds>(endMax - startMax);
    auto microMax = duration_cast<microseconds>(endMax - startMax);
    auto milliMax = duration_cast<milliseconds>(endMax - startMax);
    duration<double> secMax = endMax - startMax;

    auto nanoMin = duration_cast<nanoseconds>(endMin - startMin);
    auto microMin = duration_cast<microseconds>(endMin - startMin);
    auto milliMin = duration_cast<milliseconds>(endMin - startMin);
    duration<double> secMin = endMin - startMin;

    cout << "\n========== MAX HEAP SORT ==========\n"
         << "Nanoseconds  : " << nanoMax.count() << " ns\n"
         << "Microseconds : " << microMax.count() << " us\n"
         << "Milliseconds  : " << milliMax.count() << " ms\n"
         << "Seconds      : " << secMax.count() << " s\n";

    cout << "\n========== MIN HEAP SORT ==========\n"
         << "Nanoseconds  : " << nanoMin.count() << " ns\n"
         << "Microseconds : " << microMin.count() << " us\n"
         << "Milliseconds  : " << milliMin.count() << " ms\n"
         << "Seconds      : " << secMin.count() << " s\n";

    return 0;
}
