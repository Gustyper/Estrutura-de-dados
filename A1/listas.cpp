#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct{
    string NomeDia;
    string PrimeiroHorario;
    string SegundoHorario;
    string TerceiroHorario;
} Dia;

void PrintHorario(Dia&);
void MudarHorario(Dia&);

int main()
{
    Dia Segunda;
    Segunda.NomeDia = "Segunda";
    Segunda.PrimeiroHorario = "ED";
    Segunda.SegundoHorario = "Prob";
    Segunda.TerceiroHorario = "MI";
    
    Dia& refSegunda = Segunda;
    
    Dia Terca;
    Terca.NomeDia = "Terça";
    Terca.PrimeiroHorario = "livre";
    Terca.SegundoHorario = "ALN";
    Terca.TerceiroHorario = "TACD";
    
    Dia& refTerca = Terca;
    Dia Quarta;
    Quarta.NomeDia = "Quarta";
    Quarta.PrimeiroHorario = "ED";
    Quarta.SegundoHorario = "Prob";
    Quarta.TerceiroHorario = "MI";
    
    Dia& refQuarta = Quarta;
    
    Dia Quinta;
    Quinta.NomeDia = "Quinta";
    Quinta.PrimeiroHorario = "livre";
    Quinta.SegundoHorario = "ALN";
    Quinta.TerceiroHorario = "livre";
    
    Dia& refQuinta = Quinta;
    
    Dia Sexta;
    Sexta.NomeDia = "Sexta";
    Sexta.PrimeiroHorario = "livre";
    Sexta.SegundoHorario = "Prob";
    Sexta.TerceiroHorario = "TACD";
    
    Dia& refSexta = Sexta;
    
    int input1;
    int input2;
    
    while (true)
    {
        cout << "===== Escolha uma opção ======\n";
        cout << "1 - Ver horários\n";
        cout << "2 - Alterar horários\n" << endl;
        
        cin >> input1;
        
        cout << "===========";
        cout << "Escolha um dia da semana:!\n";
        cout << "Segunda = 1;\n";
        cout << "Terca = 2;\n";
        cout << "Quarta = 3;\n";
        cout << "Quinta = 4;\n";
        cout << "Sexta = 5;\n" << endl;
        
        cin >> input2;
        
        switch (input1)
        {
            case 1:
                switch (input2)
                {
                    case 1:
                        PrintHorario(refSegunda);
                        break;
                    case 2:
                        PrintHorario(refTerca);
                        break;
                    case 3:
                        PrintHorario(refQuarta);
                        break;
                    case 4:
                        PrintHorario(refQuinta);
                        break;
                    case 5:
                        PrintHorario(refSexta);
                        break;
                    
                    default:
                        cout << "Eita, não é dia isso aí não boy" << endl;
                }
                break;
                
            case 2:
                switch (input2)
                {
                    case 1:
                        MudarHorario(refSegunda);
                        break;
                    case 2:
                        MudarHorario(refTerca);
                        break;
                    case 3:
                        MudarHorario(refQuarta);
                        break;
                    case 4:
                        MudarHorario(refQuinta);
                        break;
                    case 5:
                        MudarHorario(refSexta);
                        break;
                    
                    default:
                        cout << "Eita, não é dia isso aí não boy" << endl;
                }
                break;
        }
        
        
    }

    return 0;
}

void PrintHorario(Dia& dia)
{
    cout << "Horários de " << dia.NomeDia << ":";
    cout << "\n7:30: " << dia.PrimeiroHorario;  
    cout << "\n9:20: " << dia.SegundoHorario;  
    cout << "\n11:10: " << dia.TerceiroHorario << endl;  
}

void MudarHorario(Dia& dia)
{
    PrintHorario(dia);
    cout << "\n Novo horário 7:30: " << endl; 
    cin >> dia.PrimeiroHorario;
    cout << "\n Novo horário 9:20: " << endl; 
    cin >> dia.SegundoHorario;
    cout << "\n Novo horário 11:10: " << endl; 
    cin >> dia.TerceiroHorario;
    cout << "\n Horário alterado!! " << endl; 
}



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

float calculaRaiz(int, int, int);

int main()
{
    int a, b, c;
    
    cout << "Digite a, depois b e depois c." << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    
    int delta = b*b - 4*a*c;
    
    if (delta < 0) 
    {
        cout << "Não tem raiz real." << endl;
    } 
    else if (delta == 0) 
    {
        cout << "Tem uma raiz real:" << endl;
        float raiz = calculaRaiz(delta, a, b);
        cout << raiz << endl;
    } 
    else 
    {
        cout << "Tem duas raízes reais." << endl;
        float raiz1, raiz2 = calculaRaiz(delta, a, b);
        cout << raiz1 << " " << raiz2 << endl;
    }

    return 0;
}

float calculaRaiz(int delta, int a, int b)
{
    if(delta) // Se for 0 ele dá false
    {
        float x1 = (-b + sqrt(delta))/2*a;
        float x2 = (-b - sqrt(delta))/2*a;
        
        return x1, x2;
    }
    else
    {
        float x = -b/2*a;
        return x; 
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

typedef struct Aluno
{   
    int iMatricula;
    Aluno* ptrproxAluno;
} Aluno;

struct LinkedList
{
    Aluno* primeiroAluno;
};

LinkedList* newLinkedList();
Aluno* newAluno(int);

void printList(LinkedList* const);
void addElement(LinkedList* const, int);
void removeAluno(LinkedList* const, int);
void trocaUltimoPrimeiro(LinkedList* const);

LinkedList* MatriculasComuns(LinkedList* const, LinkedList* const);

bool temCiclo(LinkedList* const);

int main()
{
    LinkedList* Matriculas = newLinkedList();
    
    addElement(Matriculas, 1);
    addElement(Matriculas, 2);
    addElement(Matriculas, 3);
    addElement(Matriculas, 4);
    
    LinkedList* Matriculas2 = newLinkedList();
    
    addElement(Matriculas2, 10);
    addElement(Matriculas2, 2);
    addElement(Matriculas2, 3);
    addElement(Matriculas2, 4);
    
    LinkedList* repetidos = MatriculasComuns(Matriculas, Matriculas2);
    
    addElement(Matriculas, 5);
    addElement(Matriculas2, 5);
    
    repetidos = MatriculasComuns(Matriculas, Matriculas2);
    
    trocaUltimoPrimeiro(Matriculas);
    printList(repetidos);
    
    return 0;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->primeiroAluno = nullptr;
    
    return temp;
}

Aluno* newAluno(int iMatricula)
{
    Aluno* temp = (Aluno*) malloc(sizeof(Aluno));
    temp->iMatricula = iMatricula;
    temp->ptrproxAluno = nullptr;
    return temp;
}

void addElement(LinkedList* const lista, int iMatricula)
{
    if(lista == nullptr)
    {
        cout << "Essa lista não existe" << endl;
        return;
    }
    
    Aluno* temp = newAluno(iMatricula);
    
    if(lista->primeiroAluno ==  nullptr)
    {
        lista->primeiroAluno = temp;
    }
    else
    {
        Aluno* current = lista->primeiroAluno;
        
        while(current->ptrproxAluno != nullptr)
        {
            if(current->iMatricula == iMatricula)
            {
                cout << "Não pode repetir matrícula!" << endl;
                return;
            }
            current = current->ptrproxAluno;
        }
        
        if(current->iMatricula == iMatricula)
        {
            cout << "Não pode repetir matrícula!" << endl;
            return;
        }
        
        current->ptrproxAluno = temp;
    }
}

void printList(LinkedList* const lista)
{
    if(lista == nullptr || lista->primeiroAluno == nullptr)
    {
        cout << "Essa lista não existe ou está vazia!" << endl;
        return;
    }
    
    cout << "====== Lista: =======\n";
    Aluno* current = lista->primeiroAluno;
    
    while(current != nullptr)
    {
        cout << "Aluno: " << current->iMatricula << "\n";
        current = current->ptrproxAluno;
    }
    cout << endl;
}

void removeAluno(LinkedList* const lista, int iMatriculaRemover)
{
    if(lista == nullptr || lista->primeiroAluno == nullptr)
    {
        cout << "Essa lista não existe ou está vazia!" << endl;
        return;
    }
    
    Aluno* current = lista->primeiroAluno;
    
    if(current->iMatricula == iMatriculaRemover)
    {
        lista->primeiroAluno = current->ptrproxAluno;
        free(current);
        return;
    }
    
    Aluno* prev = lista->primeiroAluno;;
    current = prev->ptrproxAluno;
    
    while(current != nullptr)
    {
        if(current->iMatricula == iMatriculaRemover)
        {
            prev->ptrproxAluno = current->ptrproxAluno;
            free(current);
            return;
        }
        
        prev = current;
        current = prev->ptrproxAluno;
    }
    
    cout << "Não tem essa matrícula!" << endl;
    
}

void trocaUltimoPrimeiro(LinkedList* const lista)
{
    if(lista == nullptr || lista->primeiroAluno == nullptr)
    {
        cout << "Essa lista não existe ou está vazia!" << endl;
        return;
    }
    
    Aluno* primeiro = lista->primeiroAluno;
    
    if(primeiro->ptrproxAluno == nullptr)
    {
        cout << "Essa lista só tem um aluno!" << endl;
        return;
    }
    
    Aluno* prev = primeiro;
    Aluno* last = primeiro->ptrproxAluno;
    
    while(last->ptrproxAluno != nullptr)
    {
        prev = last;
        last = last->ptrproxAluno;
    }
    
    prev->ptrproxAluno = primeiro;
    last->ptrproxAluno = primeiro->ptrproxAluno;
    primeiro->ptrproxAluno = nullptr;
    lista->primeiroAluno = last;
}

LinkedList* MatriculasComuns(LinkedList* const lista1, LinkedList* const lista2)
{
    LinkedList* Repetidos = newLinkedList();
    
    if(lista1 == nullptr || lista2 == nullptr || lista1->primeiroAluno == nullptr || lista2->primeiroAluno == nullptr)
    {
        cout << "Pelo menos uma das listas não existe ou é vazia!" << endl;
        return Repetidos;
    }
    
    Aluno* aluno1 = lista1->primeiroAluno;
    Aluno* aluno2 = lista2->primeiroAluno;
    
    while (aluno1 != nullptr)
    {
        while (aluno2 != nullptr)
        {
            if (aluno1->iMatricula == aluno2->iMatricula)
            {
                addElement(Repetidos, aluno1->iMatricula);
                break;
            }
            aluno2 = aluno2->ptrproxAluno;
        }
        aluno2 = lista2->primeiroAluno;
        aluno1 = aluno1->ptrproxAluno;
    }
    
    return Repetidos;
}

bool temCiclo(LinkedList* const lista)
{
    LinkedList* tempList = newLinkedList();
    
    Aluno* temp = lista->primeiroAluno;
    
    while (temp != nullptr)
    {
        Aluno* iter = tempList->primeiroAluno;
        
        while (iter !=  nullptr)
        {
            if (temp == iter)
            {
                cout << "Tem loop!" << endl;
                return true;
            }
            iter = iter->ptrproxAluno;
        }
        
        addElement(tempList, temp); //Teria que fazer um outra add element pra add um aluno direto
        
        temp = temp->ptrproxAluno;
    }
    
    cout << "Não tem loop!" << endl;
    
    return false;
    // dar um free na lista
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;


typedef struct Node
{
    string strName;
    Node* ptrNext;
} Node;

struct Fila
{
    string strNomeFila;
    Node* ptrFront;  
    Node* ptrLast;  
};

Fila* createFila(string);
Node* createNOde();
void addElement(Fila*, string);
void printElements(Fila*);

void inverteElementos(Fila*); //sheeeesh
void inverteElementos2(Fila*);

int main()
{
    Fila* fila = createFila("Fila maneira");
    
    addElement(fila, "Gustavo");
    addElement(fila, "Guilherme");
    addElement(fila, "João");
    addElement(fila, "Viniflop");
    addElement(fila, "Daniel");
    addElement(fila, "Guigas");
    
    printElements(fila);
    inverteElementos2(fila);
    addElement(fila, "Marciano");
    printElements(fila);
    
    
    
    return 0;
}

Fila* createFila(string strNomeFila)
{
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->ptrFront = nullptr;
    fila->ptrLast = nullptr;
    fila->strNomeFila = strNomeFila;
    return fila;
}

Node* createNode(string strNome)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->strName = strNome;
    node->ptrNext = nullptr;
    return node;
}

void addElement(Fila* lista, string strNome)
{
    if(lista == nullptr)
    {
        cout << "Essa fila nem existe pae!" << endl;
        return;
    }
    
    Node* temp = createNode(strNome);
    
    if(lista->ptrFront == nullptr)
    {
        lista->ptrFront = temp;
    }
    else
    {
        Node* current = lista->ptrFront;
        
        while (current->ptrNext != nullptr)
        {
            current = current->ptrNext;
        }
        current->ptrNext = temp;
    }
    
    lista->ptrLast = temp;
}

void printElements(Fila* lista)
{
    if(lista == nullptr || lista->ptrFront == nullptr)
    {
        cout << "Chama os brigadiano!!" << endl;
        return;
    }
    
    cout << "--Elementos de: " << lista->strNomeFila << "\n";
    Node* current = lista->ptrFront;
        
    while (current != nullptr)
    {
        cout << "-" << current->strName << "\n";
        current = current->ptrNext;
    }
    cout << endl;
}

void inverteElementos(Fila* fila)
{
    if(fila == nullptr || fila->ptrFront == nullptr || fila->ptrFront->ptrNext == nullptr)
    {
        cout << "Chama os brigadiano!!" << endl;
        return;
    }
    
    Node* primeiro = fila->ptrFront;
    
    fila->ptrFront = nullptr;
    
    Node* current = primeiro;
    Node* penultimo = nullptr;
    
    /////////////////////////
    
    while (fila->ptrLast != primeiro)
    {
        if (primeiro->ptrNext != nullptr)
        {
            while(current->ptrNext->ptrNext != nullptr)
            {
                current = current->ptrNext;
            }
            
            penultimo = current;
            current = current->ptrNext;
            
            penultimo->ptrNext = nullptr;
        }
        
        if (fila->ptrFront != nullptr)
        {
            Node* findLast = fila->ptrFront;
            
            while(findLast->ptrNext != nullptr)
            {
                findLast = findLast->ptrNext;
            }
            
            findLast->ptrNext = current;
        }
        else
        {
            fila->ptrFront = current;
        }
        
        fila->ptrLast = current;
        current = primeiro;
    }
}

void inverteElementos2(Fila* fila) {
    if (fila == nullptr || fila->ptrFront == nullptr || fila->ptrFront->ptrNext == nullptr) {
        cout << "Chama os brigadiano!!" << endl;
        return;
    }

    Node* previous = nullptr;
    Node* current = fila->ptrFront;
    Node* next = nullptr;

    fila->ptrLast = fila->ptrFront;

    while (current != nullptr) {
        next = current->ptrNext;
        current->ptrNext = previous;
        previous = current;
        current = next;
    }

    fila->ptrFront = previous;
}