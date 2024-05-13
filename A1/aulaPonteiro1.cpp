#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int* ptrInt = nullptr; // definição de ponteiro vazio
    // int* ptrInt = NULL; 
    
    // Não melhor que null, mas pra certificar que não vai apontar pra algo aleatório fora do programa
    // int* ptrInt = 0; // com outros números nn funfa
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "=========================================" << endl;
    
    int iNumMagico = 42;
    cout << "Endereço de iNumMagico: " << &iNumMagico << endl;
    
    ptrInt = &iNumMagico;
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "=========================================" << endl;
    
    int iNumSagrado = 7;
    cout << "Endereço de iNumSagrado: " << &iNumSagrado << endl;
    
    ptrInt = &iNumSagrado;
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "Conteúdo de iNumSagrado: " << *ptrInt << endl; // *prtInt mata o ponteiro, pega o valor pra onde ele tá apontando
    cout << "=========================================" << endl;
    
    
    // Ao contrário da referência o ponteiro é resetável

    return 0;
}
