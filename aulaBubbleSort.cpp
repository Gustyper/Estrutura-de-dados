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
void bubbleSort(int[], int);
void optimizedBubbleSort(int[], int);

int main()
{
    int arriNumbers[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    int iArraySize = 10;
    
    cout << "Array original: ";
    printArray(arriNumbers, iArraySize);
    
    // time_point<std::chrono::high_resolution_clock> -> o tipo
    auto timeStart = high_resolution_clock::now();
    bubbleSort(arriNumbers, iArraySize);
    auto timeStop = high_resolution_clock::now();
    
    cout << "Array ordenado: ";
    printArray(arriNumbers, iArraySize);
    
    auto TimeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << TimeDuration.count() << " nanosegundos." << endl;
    cout << "==================================" << endl;
    
    int arriNumbers2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    
    cout << "Array original 2: ";
    printArray(arriNumbers2, iArraySize);
    
    // time_point<std::chrono::high_resolution_clock> -> o tipo
    timeStart = high_resolution_clock::now();
    optimizedBubbleSort(arriNumbers2, iArraySize);
    timeStop = high_resolution_clock::now();
    
    cout << "Array ordenado: ";
    printArray(arriNumbers2, iArraySize);
    
    TimeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << TimeDuration.count() << " nanosegundos." << endl;
    cout << "==================================" ;
    
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

void bubbleSort(int arriNumbers[], int iLength)
{
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        for (int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop++)
        {
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
            {
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
            }
        }
    }
}

void optimizedBubbleSort(int arriNumbers[], int iLength)
{
    bool bUnordered = false;
    
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        bUnordered = false;
        
        for (int iInnerLoop = 0; iInnerLoop < iLength - 1 - iOuterLoop; iInnerLoop++)
        {
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
                {
                    swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
                    bUnordered = true;
                }
        }
        
        if (!bUnordered) break;
    }
}


// void OptmizedBubbleSort(LinkedList* lista)
// {
//     int iLength = 0;
//     Node* temp = lista->ptrFirst;
    
//     // Calculate the length of the linked list
//     while (temp != nullptr)
//     {
//         iLength++;
//         temp = temp->ptrNext;
//     }

//     // Perform bubble sort
//     for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
//     {
//         Node* current = lista->ptrFirst;
//         Node* prev = nullptr;
        
//         for (int iInnerLoop = 0; iInnerLoop < iLength - 1 - iOuterLoop; iInnerLoop++)
//         {
//             Node* nextNode = current->ptrNext;
            
//             // Check if the current node's value is greater than the next node's value
//             if (current->iData > nextNode->iData)
//             {
//                 // Swap the nodes
//                 if (prev != nullptr)
//                 {
//                     prev->ptrNext = nextNode;
//                 }
//                 else
//                 {
//                     // If prev is null, it means current node is the first node, so update lista->ptrFirst
//                     lista->ptrFirst = nextNode;
//                 }
                
//                 current->ptrNext = nextNode->ptrNext;
//                 nextNode->ptrNext = current;
                
//                 // Update prev to point to the nextNode
//                 prev = nextNode;
//             }
//             else
//             {
//                 // No need to swap, move to the next nodes
//                 prev = current;
//                 current = current->ptrNext;
//             }
//         }
//     }
// }