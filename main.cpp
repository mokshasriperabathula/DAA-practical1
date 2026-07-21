#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int> &num)
{
    int n = num.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (num[j] > num[j + 1])
                swap(num[j], num[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &num)
{
    int n = num.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (num[j] < num[minPos])
                minPos = j;
        }
        swap(num[i], num[minPos]);
    }
}

// Insertion Sort
void insertionSort(vector<int> &num)
{
    int n = num.size();
    for (int i = 1; i < n; i++)
    {
        int key = num[i];
        int j = i - 1;

        while (j >= 0 && num[j] > key)
        {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = key;
    }
}

// Merge Function
void merge(vector<int> &num, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftPart(n1), rightPart(n2);

    for (int i = 0; i < n1; i++)
        leftPart[i] = num[left + i];

    for (int j = 0; j < n2; j++)
        rightPart[j] = num[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftPart[i] <= rightPart[j])
            num[k++] = leftPart[i++];
        else
            num[k++] = rightPart[j++];
    }

    while (i < n1)
        num[k++] = leftPart[i++];

    while (j < n2)
        num[k++] = rightPart[j++];
}

// Merge Sort
void mergeSort(vector<int> &num, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(num, left, mid, right);
    }
}

// Partition Function
int partition(vector<int> &num, int low, int high)
{
    int pivot = num[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (num[j] <= pivot)
        {
            i++;
            swap(num[i], num[j]);
        }
    }

    swap(num[i + 1], num[high]);
    return i + 1;
}

// Quick Sort
void quickSort(vector<int> &num, int low, int high)
{
    if (low < high)
    {
        int pi = partition(num, low, high);
        quickSort(num, low, pi - 1);
        quickSort(num, pi + 1, high);
    }
}

// Display first 10 elements
void display(vector<int> &num)
{
    for (int i = 0; i < 10; i++)
        cout << num[i] << " ";
    cout << endl;
}

int main()
{
    const int n = 200;
    vector<int> num(n), temp;

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        num[i] = rand() % 500;

    cout << "Number of Elements : " << n << endl;
    cout << "Sample Data : ";
    display(num);

    auto start = high_resolution_clock::now();
    temp = num;
    bubbleSort(temp);
    auto stop = high_resolution_clock::now();
    cout << "Bubble Sort Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " us" << endl;

    start = high_resolution_clock::now();
    temp = num;
    selectionSort(temp);
    stop = high_resolution_clock::now();
    cout << "Selection Sort Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " us" << endl;

    start = high_resolution_clock::now();
    temp = num;
    insertionSort(temp);
    stop = high_resolution_clock::now();
    cout << "Insertion Sort Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " us" << endl;

    start = high_resolution_clock::now();
    temp = num;
    mergeSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    cout << "Merge Sort Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " us" << endl;

    start = high_resolution_clock::now();
    temp = num;
    quickSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    cout << "Quick Sort Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " us" << endl;

    return 0;
}
