#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void swapValue(int&, int&);
void printArray(int[], int);
void selectionSort(int[], int);
void optimizedSelectionSort(int[], int);

int main()
{   
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Testing selection sort
    auto timeStart = high_resolution_clock::now();
    selectionSort(arr, n);
    auto timeStop = high_resolution_clock::now();
    cout << "Array after selection sort: ";
    printArray(arr, n);
    auto timeTaken = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Time taken by selection sort: " << timeTaken.count() << " nanoseconds\n";

    // Reinitialize array for testing optimized selection sort
    int arr2[] = {64, 25, 12, 22, 11};
    cout << "Original array for optimized selection sort: ";
    printArray(arr2, n);

    // Testing optimized selection sort
    auto timeStartOptimized = high_resolution_clock::now();
    optimizedSelectionSort(arr2, n);
    auto timeStopOptimized = high_resolution_clock::now();
    cout << "Array after optimized selection sort: ";
    printArray(arr2, n);
    auto timeTakenOptimized = duration_cast<nanoseconds>(timeStopOptimized - timeStartOptimized);
    cout << "Time taken by optimized selection sort: " << timeTakenOptimized.count() << " nanoseconds\n";

    return 0;
}


void swapValue(int& iValue_1, int& iValue_2)
{
    int itemp = iValue_1;
    iValue_1 = iValue_2;
    iValue_2 = itemp;
}

void printArray(int arriNumbers[], int iLength)
{
    for (int i = 0; i < iLength; i++) cout << arriNumbers[i] << " ";
    cout << endl;
}

void selectionSort(int arriNumbers[], int iLength)
{
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iLength; iInnerLoop++)
        {
            if (arriNumbers[iOuterLoop] > arriNumbers[iInnerLoop])
            {
                swapValue(arriNumbers[iOuterLoop], arriNumbers[iInnerLoop]);
            }
        }
    }
}

void optimizedSelectionSort(int arriNumbers[], int iLength)
{
    int minValue = 0;
    int iSwapIndex = 0;
    
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        minValue = arriNumbers[iOuterLoop];
        iSwapIndex = iOuterLoop;
        
        for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iLength; iInnerLoop++)
        {
            if (minValue > arriNumbers[iInnerLoop])
            {
                minValue = arriNumbers[iInnerLoop];
                iSwapIndex = iInnerLoop;
            }
        }
        
        if (iSwapIndex != iOuterLoop)
        {
            swapValue(arriNumbers[iSwapIndex], arriNumbers[iOuterLoop]);
        }
    }
}