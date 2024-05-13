#include <iostream>

using std::cout;
using std::endl;
using std::string; 

int main()
{
    cout << "====================================================================\n" << endl;
    
    enum Streaming {AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, Netflix, Max};
    
    Streaming streamingSubscription = CrunchyRoll;
    
    switch (streamingSubscription)
    {
        case AppleTV:
            cout << "Nunca usei... Não sei como é... [" << streamingSubscription << "]" << endl;
            break;
        case CrunchyRoll:
            cout << "Muito bom... [" << streamingSubscription << "]" << endl;
            break;
        default:
        cout << "NADA" << endl;
    }
    
    cout << "====================================================================\n" << endl;
    
    enum Meses {JANEIRO = 10, FEVEREIRO, MARCO, ABRIL, MAIO};
    
    Meses mesProvas = MAIO;
    cout << mesProvas << endl;
    
    enum Semana {Segunda = 10, Terça = 1, Quarta = -3};
    
    Semana diaPalestra = Quarta;
    cout << diaPalestra << endl;
    
    return 0;
}