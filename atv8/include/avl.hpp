#include <string>
using namespace std;

const int MAX_NUM_PAGINAS = 1000000;

struct TipoNo {
    string palavra;
    int* paginas;
    int altura;
    TipoNo* esq;
    TipoNo* dir;
    TipoNo* pai;
    int numPags;

    TipoNo() : paginas(new int[MAX_NUM_PAGINAS]), altura(0), esq(nullptr), dir(nullptr), pai(nullptr), numPags(0) {}

    ~TipoNo() {
        delete[] paginas;
    }
};

struct Key {
    string palavra;
    int pagina;
};

class Avl {
public:
    TipoNo* inserir(TipoNo* no, Key indice);
    TipoNo* pesquisa(string palavra, TipoNo* no);
    void caminhamentoEmOrdem(TipoNo* no);
private:
    int Max(int a, int b);
    int altura(TipoNo* no);
    int fatorBalanceamento(TipoNo* no);
    TipoNo* rotacaoDir(TipoNo* no);
    TipoNo* rotacaoEsq(TipoNo* no);
};
