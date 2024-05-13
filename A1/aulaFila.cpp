#include <iostream>

using std::cout;
using std::endl;

// FIFO
// FI First in 
// FO First out

// FCFS
// FC First come
// FS First served

// LIFO
// LCFS
// Pilha -> Pilha de pratos, o último a entrar é o primeiro a ser lavado

typedef struct Node
{
    int iData;
    Node* next;
    // E1 -> E2
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

//////////////////////

Queue* newQueue(); 
Node* newNode(int); 
void enQueue(Queue* const, int);
void ShowFirstElement(Queue*);
void ShowLastElement(Queue*);
void ShowElements(Queue*);
void deQueue(Queue*);

int main()
{
    // 1. Estrutura de um nó
    // 2. Estrutura de uma fila
    // 3. Função que cria uma fila
    // 4. Função que cria um nó
    // 5. Função que enfileira um nó
    // 6. Função que exibe o primeiro elemento
    // 7. Função que exibe o primeiro elemento
    // 8. Função que exibe todos os elementos
    // 9. Função que remove um elemento da fila
    
    Queue* queue = newQueue();
    ShowFirstElement(queue);
    ShowLastElement(queue);
    cout << "---" << endl;
    ShowElements(queue);
    deQueue(queue);
    
    cout << "===================" << endl;
    
    enQueue(queue, 0);
    ShowFirstElement(queue);
    ShowLastElement(queue);
    cout << "---" << endl;
    ShowElements(queue);
    
    cout << "===================" << endl;
    
    enQueue(queue, 3);
    enQueue(queue, 7);
    enQueue(queue, 13);
    enQueue(queue, 42);
    ShowFirstElement(queue);
    ShowLastElement(queue);
    cout << "---" << endl;
    ShowElements(queue);
    
    cout << "===================" << endl;
    
    deQueue(queue);

    return 0;
}

Queue* newQueue()
{
    // Pedindo memória pro windows
    // Ele retorna um ponteiro pra void (void*), ent nós mudamos p (Queue*)
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    
    // Acessar elemento de dados de uma estrutura "->" POR PONTEIRO
    temp->front = nullptr;
    temp->rear = nullptr;
    
    return temp;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->next = nullptr;
    
    return temp;
}

void enQueue(Queue* const queue, int iValue)
{
    Node* temp = newNode(iValue);
    
    if (queue->rear == nullptr)
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        (queue->rear)->next = temp;
        queue->rear = temp;
    }
}

void ShowFirstElement(Queue* const queue)
{
    cout << "Primeiro Elemento: " << ( (queue->front != NULL) ? (queue->front)->iData  : -1 ) << endl;
}

void ShowLastElement(Queue* const queue)
{
    cout << "Último Elemento: " << ( (queue->rear != NULL) ? (queue->rear)->iData  : -1 ) << endl;
}

void ShowElements(Queue* const queue)
{
    if (queue->front == nullptr) //NULL = nullptr (0 pode variar, mas em geral NULL = 0)
    {
        cout << "Fila Vazia" << endl;
        return;
    }
    
    Node* current = queue->front;
    
    while (current != nullptr)
    {
        cout << "Elemento: " << current->iData << endl;
        current = current->next;
    }
    
}

void deQueue(Queue* const queue)
{
    // CASOS ESPEIAIS A SEREM TESTADOS: (não só nessa func, mas no geral)
    // 1) fila Vazia
    if (queue->front == nullptr)
    {
        cout << "Fila Vazia" << endl;
        return;
    }
    
    Node* temp = queue->front;
    
    cout << "Elemento Removido: " << temp->iData << endl;
    
    queue->front = queue->front->next;
    
    // 2) Fila com só um elemento
    if (queue->front == nullptr)
    {
        queue->rear = nullptr;
    }
    
    free(temp); // Calcula o tamanho de um Node (x) e vai apagar da memória (x) bytes a partir do ponteiro
}