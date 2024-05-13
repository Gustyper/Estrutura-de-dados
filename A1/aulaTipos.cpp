// #DEFINE false 0 // Dá pra definir um valor pra m termo. Provavelmnte em uma bibkioteca base de C++ tem um define true 1 e false 0.

# include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    // int iNum1 = 42, iNum2, iNum3 = 17; //NÃO FZR ISSO
    // Quando tu declara uma variável sem colocar um valor, ele pega o valor que tá na memória
    
    //-2,147,483,648 a -2,147,483,647
    //4 bytes
    int iNum1 = 42;
    int iNum2 = 0;
    int iNum3 = 17; // SIM!!
    
    
    cout << "iNum1: " << iNum1 << "\nTamanho de iNum1: " << sizeof(iNum1) << endl;
    cout << "iNum2: " << iNum2 << "\nTamanho de iNum1: " << sizeof(iNum2) << endl;
    cout << "iNum3: " << iNum3 << "\nTamanho de iNum1: " << sizeof(iNum3) << endl;
    
    
    //-32,768 até 32,767
    //2 bytes
    short sNum = 17;
    cout << "sNum: " << iNum1 << "\nTamanho de sNum: " << sizeof(sNum) << endl;
    
    
    //-9,223,372,036,854,775,808 a -9,223,372,036,854,775,807
    //2 bytes
    long lNum = 18;
    cout << "lNum: " << lNum << "\nTamanho de lNum: " << sizeof(lNum) << endl;
    
    // pode fazer um long long, e dependendo o compilador ele aceita que terá mais que 8 bytes. Aqui no GDB vai ter só 8
    
    float fNum = 42.123456789;
    double dNum = 42.123456789;
    long double ldNum = 42.123456789;
    
    cout << "fNum: " << fNum << "\nTamanho de fNum: " << sizeof(fNum) << endl;
    cout << "dum: " << dNum << "\nTamanho de dNum: " << sizeof(dNum) << endl;
    cout << "ldNum: " << ldNum << "\nTamanho de ldNum: " << sizeof(ldNum) << endl;
    
    char cValue = 'E';
    
    cout << "cValue: " << cValue << "\nTamanho de cValue: " << sizeof(cValue) << endl;
    cout << "(int) cValue: " << int(cValue) << endl;
    
    char cPalavraPreferida_1 = 77;
    char cPalavraPreferida_2 = 0x41;
    char cPalavraPreferida_3 = 0b1110000;
    
    cout << cValue;
    cout << cPalavraPreferida_1;
    cout << cPalavraPreferida_2;
    cout << cPalavraPreferida_3 << endl;
    
    string strValue_1 = "Eu adoro a";
    string strValue_2 = "EMAp";
    
    cout << "strValue_1: " << strValue_1 << "\nTamanho de strValue_1: " << sizeof(strValue_1) << endl;
    cout << "strValue_2: " << strValue_2 << "\nTamanho de strValue_2: " << sizeof(strValue_2) << endl;
    
    bool bValue_1 = true;
    bool bValue_2 = false;
    bool bValue_3 = 42;
    bool bValue_4 = 0;
    
    cout << "bValue_1: " << bValue_1 << "\nTamanho de bValue_1: " << sizeof(bValue_1) << endl;
    cout << "bValue_2: " << bValue_2 << "\nTamanho de bValue_2: " << sizeof(bValue_2) << endl;
    cout << "bValue_3: " << bValue_3 << "\nTamanho de bValue_3: " << sizeof(bValue_3) << endl;
    cout << "bValue_4: " << bValue_4 << "\nTamanho de bValue_4: " << sizeof(bValue_4) << endl;
    
    // É tudo 1 e 0, sendo 0 = false. E tudo que não é 0 é simplesmente (not false)
    
    const int iNUMERO = 42;
    // iNUMERO = 111; // Erro, iNUMERO é uma variável apenas de leitura (constante).
    
    cout << "iNUMERO: " << iNUMERO << "\nTamanho de iNUMERO: " << sizeof(iNUMERO) << endl;
    
    unsigned short usNum = 42000;
    
    cout << "usNum: " << usNum << "\nTamanho de usNum: " << sizeof(usNum) << endl;
    
    unsigned long long int ulliNum = 42;
    long unsigned int long ulliNum_2 = 42; //Isso funciona mas é feio, pinho nn gosta
    cout << "ulliNum: " << ulliNum << "\nTamanho de ulliNum: " << sizeof(ulliNum) << endl;
}