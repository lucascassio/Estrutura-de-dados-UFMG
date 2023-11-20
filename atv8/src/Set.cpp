#include "../include/Set.hpp"
#include <iostream>

StringSet::StringSet(int tamanho) {
    tamanhoConjunto = 0;
    tamanhoOriginal = tamanho;
    tamanhoTabela = tamanho;
    tabela = new ElementoTabela[tamanhoTabela];

    for (int i = 0; i < tamanhoTabela; i++) {
        tabela[i].retirada = false;
        tabela[i].vazio = true;
    }
}

StringSet::~StringSet() {
    delete[] tabela;
}

bool StringSet::Pertence(string s) {
    int pos = Hash(s);
    return (!tabela[pos].vazio && !tabela[pos].retirada) && tabela[pos].dado == s;
}

void StringSet::Inserir(string s) {
    if(Pertence(s)) {
        return;
    }

    int pos = Hash(s);

    if (tamanhoConjunto >= tamanhoTabela) {
        Rehash(pos);
        pos = Hash(s);
    }

    while (tabela[pos].vazio == false) {
        pos = (pos + 1) % tamanhoTabela;
    }

    tabela[pos].dado = s;
    tabela[pos].vazio = false;
    tabela[pos].retirada = false;

    tamanhoConjunto++;
}

void StringSet::Remover(string s) {
    int pos = Hash(s);

    if (!tabela[pos].vazio && tabela[pos].dado == s) {
        tabela[pos].retirada = true;
        tamanhoConjunto--;
    }
}

int StringSet::Hash(string s) {
    int tamanhostring = 0;
    for (char c : s) {
        tamanhostring++;
    }
    return tamanhostring % tamanhoTabela;
}

void StringSet::Rehash(int pos) {
    // Dobra o tamanho da tabela
    size_t tamanho = tamanhoTabela * 2;
    
    // Realiza o redimensionamento da tabela
    Resize(tamanho);
}

void StringSet::Resize(size_t tamanho) { 
    ElementoTabela* novaTabela = new ElementoTabela[tamanho];
    
    size_t tamanhoAtual = tamanhoTabela;
    tamanhoTabela = tamanho;
    
    for(size_t i = 0; i < tamanho; i++) {
        novaTabela[i].retirada = false;
        novaTabela[i].vazio = true;
    }

    for (size_t i = 0; i < tamanhoAtual; i++) {
        if (tabela[i].vazio == false && tabela[i].retirada == false) {
            int novaPos = Hash(tabela[i].dado);

            while (novaTabela[novaPos].vazio == false) {
                novaPos = (novaPos + 1) % tamanho;
            }

            novaTabela[novaPos] = tabela[i];
        }
    }
    delete[] tabela;
    tabela = novaTabela;
}

StringSet* StringSet::Intersecao(StringSet* S) {
    StringSet* Intersecao = new StringSet(1);

    for (int i = 0; i < S->tamanhoTabela; i++) {
        if (Pertence(S->tabela[i].dado)) {
            Intersecao->Inserir(tabela[i].dado);
        }
    }
    return Intersecao;
}

StringSet* StringSet::Uniao(StringSet* S) {
    StringSet* Uniao = new StringSet(1);

    for (int i = 0; i < tamanhoTabela; i++) {
        Uniao->Inserir(tabela[i].dado);
    }

    for (int i = 0; i < S->tamanhoTabela; i++) {
        if (!Uniao->Pertence(S->tabela[i].dado)) {
            Uniao->Inserir(S->tabela[i].dado);
        }
    }

    return Uniao;
}

StringSet* StringSet::DiferencaSimetrica(StringSet* S) {
    StringSet* Diferenca = new StringSet(1);

    for (int i = 0; i < tamanhoTabela; i++) {
        Diferenca->Inserir(tabela[i].dado);
    }

    for (int i = 0; i < S->tamanhoTabela; i++) {
        if (!Diferenca->Pertence(S->tabela[i].dado)) {
            Diferenca->Inserir(S->tabela[i].dado);
        }
    }

    for(int i = 0; i < tamanhoTabela; i++) {
        if(S->Pertence(tabela[i].dado)) {
            Diferenca->Remover(tabela[i].dado);
        }
    }
    
    return Diferenca;
}

void StringSet::Imprimir() {
    cout << "{ ";
    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            cout << tabela[i].dado;
            if (i < tamanhoTabela - 1) {
                cout << ", ";
            }
        }
    }
    cout << " }" << endl;
}