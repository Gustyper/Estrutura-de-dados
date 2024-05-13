#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int iContador = 0;
    
    while (iContador <= 5)
    {
        cout << iContador << "\n";
        iContador++;
    }
    
    iContador = 42;
    
    do {
        cout << iContador << "\n";
        iContador++;
    }
    while(iContador <= 5);
    
    for (int k=0; k < 10; k++)
    {
        for (int i=0; i < 10; i++)
        {
            for (int j=0; j < 10; j++)
            {
                cout << k << i << j << "\n";
            }
        }
    }

    return 0;
}
