#ifndef tad_abb_h
#define tad_abb_h

    typedef struct Arvore{
        struct Arvore *direita;
        struct Arvore *esquerda;
        int *elemento;
    }No;
    
    void IniciaABB(No *root);
    void InsereABB(No *root);
    void TamanhoABB(No *root);
    void PesquisaABB(No *root);
    No *BalanceiaABB(No *root);
    void NiveisABB(No *root);
#endif
