#include <iostream>

using std::cout;
using std::endl;

namespace FGV
{
    int iValor = 666;
    
    void mockFunction()
    {
        cout << "Namespace FGV" << endl;
    }
    
    namespace EMAp
    {
        int iValor = 42;
        
        void mockFunction()
        {
            cout << "Namespace EMAp" << endl;
        }
    }
}

int iValor = 10; // Namespace global

//Comparando python:
// import FGV
// using namespace FVG; 

// from fgv.emap import mockfunction
using FGV::EMAp::mockFunction;

int main()
{
    int iValor = 1;
    
    cout << "Namespace Local: " << iValor << endl;
    cout << "Namespace Global: " << ::iValor << endl;
    cout << "Namespace FGV: " << FGV::iValor << endl;
    cout << "Namespace EMAp: " << FGV::EMAp::iValor << endl;
    
    cout << "-----------------" << endl;
    
    FGV::EMAp::mockFunction();
    FGV::mockFunction();

    cout << "-----------------" << endl;
    
    mockFunction();
    
    return 0;
}
