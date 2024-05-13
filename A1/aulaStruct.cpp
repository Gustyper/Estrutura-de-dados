#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


//UDT
struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
};

typedef struct Biblioteca
{
    string strNome;
    int iTamAcervo;
    struct Livro livros[1000];
};


struct Ponto
{
    unsigned short usRed;
    unsigned short usGreen;
    unsigned short usBlue;
};

// O typedef tem que estar antes.
// O typedef definiu o tipo biblioteca, igual na Unreal. Já o Livro precisa especificar que é um struct
void listarLivros(Biblioteca);
void adicionaLivros(Biblioteca&, struct Livro);

int main()
{
    struct
    {
        int iIdade;
        string strNome;
    } alunoEMAp1, alunoEMAp2; // Cria variáveis de um tipo anônimo
    
    alunoEMAp1.iIdade = 20;
    alunoEMAp1.strNome = "Antonio";
    
    alunoEMAp2.iIdade = 17;
    alunoEMAp2.strNome = "Henzo";
    
    cout << "\nIdade do alunoEMAp1: " << alunoEMAp1.iIdade << endl;
    cout << "Nome do alunoEMAp1: " << alunoEMAp1.strNome << endl;
    
    cout << "\nIdade do alunoEMAp2: " << alunoEMAp2.iIdade << endl;
    cout << "Nome do alunoEMAp2: " << alunoEMAp2.strNome << endl;
    
    
    cout << "\n===============================================================\n" << endl;
    
    
    struct Livro livro1;
    livro1.strTitulo = "Outliers: The Story of Success";
    livro1.strAutor = "Malcolm Gladwell";
    livro1.iPublicacao = 2008;
    
    struct Livro livro2;
    livro2.strTitulo = "How to Grow Old";
    livro2.strAutor = "Marus Tullius Cicero";
    livro2.iPublicacao = -44;
    
    cout << "Titulo 1: " << livro1.strTitulo << ", por " << livro1.strAutor << endl;
    cout << "Publicado em: " << livro1.iPublicacao << ".\n" << endl;

    cout << "Titulo 2: " << livro2.strTitulo << ", por " << livro2.strAutor << endl;
    cout << "Publicado em: " << livro2.iPublicacao << ".\n" << endl;
    
    
    cout << "\n===============================================================\n" << endl;
    
    
    struct Ponto telaComputador[640][640];
    telaComputador[0][0].usRed = 0;
    telaComputador[0][0].usGreen = 0;
    telaComputador[0][0].usBlue = 0;
    
    cout << "RGB [0,0] (" << telaComputador[0][0].usRed << "," << telaComputador[0][0].usGreen << "," << telaComputador[0][0].usBlue << ")" << endl;
    
    
    cout << "\n===============================================================\n" << endl;
    
    
    Biblioteca biblioteca;
    biblioteca.strNome = "Biblioteca do Palácio Botafogo";
    biblioteca.iTamAcervo = 0;
    
    adicionaLivros(biblioteca, livro1);
    adicionaLivros(biblioteca, livro2);
    
    struct Livro livro3;
    livro3.strTitulo = "1984";
    livro3.strAutor = "George Orwel";
    livro3.iPublicacao = 1949;
    
    adicionaLivros(biblioteca, livro3);
    
    listarLivros(biblioteca);
    
    return 0;
}

void listarLivros(Biblioteca biblioteca)
{
    if (biblioteca.iTamAcervo) 
    {
        cout << "\nLivros do Acerto da " << biblioteca.strNome << ":\n" << endl;
        
        for (int i = 0; i < biblioteca.iTamAcervo; i++)
        {
            cout << "Titulo: " << biblioteca.livros[i].strTitulo << ", por" << 
            biblioteca.livros[i].strAutor << ", publicado em " << biblioteca.livros[i].iPublicacao << endl;
        }
    }
    else {cout << "A bibliotca " << biblioteca.strNome << " está vazia.";}
}

void adicionaLivros(Biblioteca& biblioteca, struct Livro novoLivro)
{
    biblioteca.livros[biblioteca.iTamAcervo] = novoLivro;
    biblioteca.iTamAcervo += 1;
}