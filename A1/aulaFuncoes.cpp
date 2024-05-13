#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int soma(int, int);
int soma(int, int, int); //Protótipo de função. Conta para o compilador que essa função existe mesmo quando não declarada ainda

void frasePreferida()
{
    cout << "Eu adoro a EMAp!" << endl;
}

void montaFrase(char chArtigo = 'a', string strPalavra = "EMAp")
{
    cout << "Eu adoro " << chArtigo << " " << strPalavra << "!" << endl;
}

////////////////////////////////////////////////////////////////////////////////

int potenciacao(int iBase, int iExpoente)
{
    return pow(iBase, iExpoente);
}

float modulo(float fValor)
{
    return fabs(fValor);
}

////////////////////////////////////////////////////////////////////////////////

void minhaFuncao(int arriNumeros[], int iTamanhoVetor)
{
    for(int i = 0; i < iTamanhoVetor; i++)
    {
        cout << arriNumeros[i] << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////

int main()
{
    frasePreferida();
    
    cout << "=====================================================================================================================" << endl;
    
    
    montaFrase(); 
    montaFrase('a'); // Funciona, já que char é o primeiro arg
    
    // montaFrase("EMAp"); 
    // Não funciona. Não tem algo que nem em python pra colocar (strPalavra = "EMAp"). Tem que ser em ordem da esquerda p direita
    
    montaFrase('o', "Pinho"); // entre '' é um CARACTERE, entre "" é uma STRING
    
    cout << "=====================================================================================================================" << endl;
    
    
    cout << "potenciacao(2,10): " << potenciacao(2,10) << endl;
    cout << "potenciacao(3,5): " << potenciacao(3,5) << endl;
    
    cout << "modulo(-2): " << modulo(-2) << endl;
    cout << "modulo(-2.5): " << modulo(-2.5) << endl; //Caso a função trabalhasse somente com int, ia funcionar tbm, mas ia truncar o nmr
    
    cout << "=====================================================================================================================" << endl;
    
    
    // int arriNumeros[] = {0, 7, 13, 42, 666} // Funciona, mas é uma prática melhor passar o tamanho do vetor
    int arriVetorTeste[5] = {0, 7, 13, 42, 666};
    int iTamanhoVetor = sizeof(arriVetorTeste)/sizeof(arriVetorTeste[0]); // Tamaho total do array (X bytes) / Tamanho dos elementos (Y bytes) então acha a quantidade de elementos
    
    minhaFuncao(arriVetorTeste,iTamanhoVetor);
    
    cout << "=====================================================================================================================" << endl;
    
    int iNum1 = 10;
    int iNum2 = 20;
    int iNum3 = 30;
    
    cout << soma(iNum1, iNum2) << endl;
    cout << soma(iNum1, iNum2, iNum3) << endl;
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//FUNFA MESMO DEPOIS DE DECLARANDO DPS POR CONTA DO PROTÓTIPO

int soma(int iValor1, int iValor2) //Assinatura da função: soma(int, int) ORDEM DOS PARÂMETROS IMPORTA
{
    return iValor1 + iValor2;
}

int soma(int iValor1, int iValor2, int iValor3) //Assinatura da função: soma(int, int, int)
{
    return iValor1 + iValor2 + iValor3;
}

// A função soma é SOBRECARREGADA - sobrecarga

//float soma (int iValor1, int iValo2) não funcionaria, pois numa situação

// soma(a, b) o compilador não saberia qual usar. Não pode ambiguidade no contexto de programação