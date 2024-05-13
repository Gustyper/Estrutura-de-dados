#include <iostream>

using std::cout;
using std::endl;

// LIFO
typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Stack
{
    int iData;
    Node* ptrTop;
} Stack;

////////////////////////////////////////////
Stack* newStack();
Node* newNode(int);
void push(Stack*, int);
void showTopElement(Stack*);
void ShowElements(Stack*);
void pop(Stack* const);

int main()
{
    Stack* stack = newStack();
    cout << "---" << endl;
    ShowElements(stack);
    cout << "---" << endl;
    pop(stack);
    cout << "=======================" << endl;
    
    push(stack, 0);
    showTopElement(stack);
    push(stack, 3);
    showTopElement(stack);
    push(stack, 7);
    showTopElement(stack);
    push(stack, 10);
    showTopElement(stack);
    push(stack, 13);
    showTopElement(stack);
    push(stack, 42);
    showTopElement(stack);
    
    cout << "---" << endl;
    cout << "=======================" << endl;
    
    ShowElements(stack);
    cout << "---" << endl;
    pop(stack);
    pop(stack);
    cout << "---" << endl;
    ShowElements(stack);
    
    return 0;
}

Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp->ptrTop = nullptr;
    
    return temp;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->ptrNext = nullptr;
    
    return temp;
}

void push(Stack* const stack, int iValue)
{
    Node* temp = newNode(iValue);
    
    temp->ptrNext = stack->ptrTop; 
    stack->ptrTop = temp; 
}

void showTopElement(Stack* const stack)
{
    cout << "Topo da Pilha: " << ((stack-> ptrTop != nullptr) ? (stack->ptrTop)->iData : -1) << endl;
}

void ShowElements(Stack* const stack)
{
    if (stack->ptrTop == nullptr) 
    {
        cout << "Pilha Vazia" << endl;
        return;
    }
    
    Node* temp= stack->ptrTop;
    
    while (temp != nullptr)
    {
        cout << "Elemento: " << temp->iData << endl;
        temp = temp->ptrNext;
    }
    
}

void pop(Stack* const stack)
{
    if (stack->ptrTop == nullptr) 
    {
        cout << "Pilha Vazia" << endl;
        return;
    }
    
    cout << "Elemento Removido: " << (stack->ptrTop)->iData << endl;
    
    Node* temp = stack->ptrTop;
    
    stack->ptrTop = stack->ptrTop->ptrNext;
    
    free(temp);
    
}