#include <iostream>

using std::cout;
using std::endl;
using std::string; 

void troca(int&, int&);
int& trocaElemento(int, int[]);

int main()
{
    string strNome = "João Gomes";
    int iValor = 42;
    int iValorFuturo = 666;
    
    cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl;
    cout << "Valor do Inteiro: " << iValor << ". Endereço do Inteiro: " << &iValor << endl;
    cout << "====================================================================\n" << endl;
    
    int& irefValor = iValor;
    string& strrefNome = strNome;
    
    cout << "Valor da Ref.String: " << strrefNome << ". Endereço da RefString: " << &strrefNome << endl;
    cout << "Valor do Ref.Inteiro: " << irefValor << ". Endereço do RefInteiro: " << &irefValor << endl;
    cout << "====================================================================\n" << endl;
    
    strrefNome = "Viniflop";
    irefValor = iValorFuturo; // A referência não é resetável. Isso vai mudar irefValor para 666, mas a referência continua apontando para iValor
    //iValor = 666
    
    cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl;
    cout << "Valor do Inteiro: " << iValor << ". Endereço do Inteiro: " << &iValor << endl;
    cout << "====================================================================\n" << endl;
    
    int iNum1 = 7;
    int iNum2 = 42;
    
    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;
    
    troca(iNum1, iNum2);
    
    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;
    
    cout << "====================================================================\n" << endl;
    
    int arriVetor[5] = {0, 7, 13, 42, 666};
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }
    
    cout << "-----" << endl;
    
    trocaElemento(3, arriVetor) = 111;
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }
    
    return 0;
}

void troca(int& irefValor1, int& irefValor2) // Se não trabalhar com referência, o compilador só copia o valor das variáveis, e não troca fora do escopo
{
    int iTemp = irefValor1;
    irefValor1 = irefValor2;
    irefValor2 = iTemp;
    
    // 42, 7
    
    // Sem gastar mais memória
    // iValor1 = iValor1+iValor2; // 49
    // iValor2 = iValor1-iValor2; // 49 - 7 = 42
    // iValor1 = iValor1-iValor2; // 49 - 42 = 7
}

int& trocaElemento(int iElemento, int arriVetor[])
{
    return arriVetor[iElemento];
}