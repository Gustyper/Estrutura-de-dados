#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main ()
{
    //TIPO NOME TAMANHO
    int x[100] = { 0 }; //400 bytes pra esse vetor
    cout << "x[0] = " << x[0] << ", endereC'o: " << &x[0] << endl;
    cout << "x[1] = " << x[1] << ", endereC'o: " << &x[1] << endl;
    cout << "x[99] = " << x[99] << ", endereC'o: " << &x[99] << endl;
    cout << "Tamanho de = " << sizeof (x) / sizeof (x[0]) << endl;
    cout << "--------------------------------------------------" << endl;

    int array[4];

    array[0] = 8;
    array[1] = 64;
    array[2] = 256;
    array[3] = 512;
    array[4] = 4646; //WTF

    // quando o copilador lC* "array[4]". Ele lC* "endereC'o do array + 16", por isso nC#o dC! erro, ele sC3 coloca na memC3ria lC!. O programador que sabe tlgd
    // offset => array + (index * sizeof(elemento));

    cout << "array[0] = " << array[0] << ", endereC'o: " << &array[0] << endl;
    cout << "array[1] = " << array[1] << ", endereC'o: " << &array[1] << endl;
    cout << "array[2] = " << array[2] << ", endereC'o: " << &array[2] << endl;
    cout << "array[3] = " << array[3] << ", endereC'o: " << &array[3] << endl;
    cout << "array[4] = " << array[4] << ", endereC'o: " << &array[4] << endl;
    cout << "Tamanho de x = " << sizeof (array) / sizeof (array[0]) << endl;

    if (&array[0] == array)
	{
	    cout << "Faz Sentido!" << endl;
	}

    cout << "--------------------------------------------------" << endl;
  
    // Array com duas linhas e tres colunas
  
    //Row Major
    int arriTest1[2][3] = {2,4,5,9,0,19}; 
    int arriTest2[2][3] = {{2,4,5},{9,0,19}};
  
    // Vai ter uma questao que vai dar um rowMajor ???? e vai pedir pra fzr funções como se fossse ColumnMajor????
  
    cout << "---------- Testando Array 1 ------------" << endl;
  
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Array 1 em [" << i << "][" << j << "] = " << arriTest1[i][j]
            << ", Endereço: " << &arriTest1[i][j] << endl;
        }
    }
  
    cout << "---------- Testando Array 2 ------------" << endl;
  
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j]
            << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
  
    cout << "---------- Aluno com TDAH (trocou linha e coluna) ------------" << endl;
  
    // Matriz_m_n em (i,j) = (i*n + j) * sizeof(elemento)
    // Matriz [2,3] em (1,0) = (1*3 + 0) * 4
  
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j]
            << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }

    cout << "---------- Aluno com Transtorno psicótico ------------" << endl;
  
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j]
            << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
  
    return 0;
}
