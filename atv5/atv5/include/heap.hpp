#ifndef HEAP_HPP
#define HEAP_HPP


class Heap{

    public:
        Heap(int maxsize);
        ~Heap();

        void Inserir(int x);
        int Remover();

        //Retorna true caso o heap esteja vazio, false caso contrário.
        bool Vazio();

        void getHeap();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);

        int tamanho;
        int* data;
};


#endif