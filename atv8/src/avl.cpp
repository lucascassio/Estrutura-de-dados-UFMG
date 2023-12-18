#include "../include/avl.hpp"
#include <iostream>

int Avl::Max(int a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}

int Avl::altura(TipoNo* no) {
    if (no == nullptr) {
        return 0;
    } 
    int resultado = 1 + Max(altura(no->dir), altura(no->esq));
    return resultado;
}

int Avl::fatorBalanceamento(TipoNo* no) {
    if (no == nullptr) return 0;
    int balanceamento = altura(no->dir) - altura(no->esq);
    return balanceamento;
}

TipoNo* Avl::rotacaoDir(TipoNo* x) {
    TipoNo* y = x->esq;
    TipoNo* T2 = y->dir;

    y->dir = x;
    x->esq = T2;

    x->altura = altura(x);
    y->altura = altura(y);

    return y;
}

TipoNo* Avl::rotacaoEsq(TipoNo* x) {
    TipoNo* y = x->dir;
    TipoNo* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = altura(x);
    y->altura = altura(y);

    return y;
}

TipoNo* Avl::inserir(TipoNo* no, Key indice) {
    if (no == nullptr) {
        TipoNo* NovoNo = new TipoNo();
        NovoNo->dir = nullptr;
        NovoNo->esq = nullptr;
        NovoNo->altura = 1;  // Um novo nó tem altura 1
        NovoNo->paginas[0] = indice.pagina;
        NovoNo->numPags++;
        NovoNo->palavra = indice.palavra;
        return NovoNo;
    }

    if (indice.palavra < no->palavra) {
        no->esq = inserir(no->esq, indice);
    } else if (indice.palavra > no->palavra) {
        no->dir = inserir(no->dir, indice);
    } else {
        bool paginaExistente = false;
        for (int i = 0; i < no->numPags; ++i) {
            if (no->paginas[i] == indice.pagina) {
                paginaExistente = true;
                break;
            }
        }

        if (!paginaExistente) {
            int i = no->numPags - 1;
            while (i >= 0 && indice.pagina < no->paginas[i]) {
                no->paginas[i + 1] = no->paginas[i];
                i--;
            }
            no->paginas[i + 1] = indice.pagina;

            no->numPags++;
        }
    }

    no->altura = altura(no);
    int balanceamento = fatorBalanceamento(no);

    if (balanceamento > 1 && indice.palavra > no->dir->palavra){ 
        return rotacaoEsq(no);  
    }

    if (balanceamento < -1 && indice.palavra < no->esq->palavra){
        return rotacaoDir(no);  
    }

    if (balanceamento > 1 && indice.palavra < no->dir->palavra){  
        no->dir = rotacaoDir(no->dir);  
        return rotacaoEsq(no);  
    }  
   
    if (balanceamento < -1 && indice.palavra > no->esq->palavra){  
        no->esq = rotacaoEsq(no->esq);  
        return rotacaoDir(no);  
    }  

    return no;
}


TipoNo* Avl::pesquisa(string palavra, TipoNo* no) {
    if (no == nullptr || palavra == no->palavra) {
        return no;
    } 
    else if (palavra < no->palavra) {
        return pesquisa(palavra, no->esq);
    } 
    else {
        return pesquisa(palavra, no->dir);
    }
}

void Avl::caminhamentoEmOrdem(TipoNo* no) {
    if (no != nullptr) {
        caminhamentoEmOrdem(no->esq);
        std::cout << no->palavra << " ";
        for (int i = 0; i < no->numPags; ++i) {
            std::cout << no->paginas[i] << " ";
        }
        std::cout << std::endl;
        caminhamentoEmOrdem(no->dir);
    }
}