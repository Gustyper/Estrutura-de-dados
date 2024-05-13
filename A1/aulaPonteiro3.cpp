#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int arriValores[5] = {0,7,13,42,666};
    cout << "Endereço de [0]: " << arriValores << endl;
    
    int* ptrArrayValores1 = arriValores; // Como isso funfa, claramente um vetor é um ponteiro pra inteiro. dããhr?
    cout << "PTR: " << ptrArrayValores1 << endl;
    
    int* ptrArrayValores2 = &arriValores[0]; 
    cout << "PTR: " << ptrArrayValores2 << endl;
    
    cout << "===============================================\n" << endl;
    
    ptrArrayValores1++;
    // ponteiro + 1 -> pega o proximo 
    cout << "Valor de ptrArrayValores1[1]: " << *(ptrArrayValores1) << endl;
    cout << "Endereço de ptrArrayValores1[1]: " << (ptrArrayValores1) << endl;
    
    ptrArrayValores2+=4;
    // ponteiro + 1 -> pega o proximo 
    cout << "Valor de ptrArrayValores1[0]: " << *(ptrArrayValores2) << endl;
    cout << "Endereço de ptrArrayValores1[0]: " << (ptrArrayValores2) << endl;
    
    // quantos inteiros um tem a mais que o outro?
    cout << "Valor de ptrArrayValores1 - ptrArrayValores2: " << (ptrArrayValores2 - ptrArrayValores1) << endl;
    
    return 0;
}
