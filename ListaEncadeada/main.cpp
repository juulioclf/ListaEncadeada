#include <stdlib.h>
#include <new>
#include <iostream>
#include <string>

using namespace std;

struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;
};

void limparTela(){
    system("CLS");
}

int retornaTamanho(pessoa *ponteiroEncadeada){

    int tamanho = 0;
    pessoa *ponteiroAuxiliar = ponteiroEncadeada;

    while(ponteiroAuxiliar != NULL){
        ponteiroAuxiliar = ponteiroAuxiliar->proximo;

        tamanho++;
    }

    return tamanho;

}

int main(){

    pessoa *ponteiroEncadeada;

    //teste
    pessoa *testePessoaEncadeada = new pessoa;
    testePessoaEncadeada->nome = "julio";
    testePessoaEncadeada->rg = 127217821;
    testePessoaEncadeada->proximo = NULL;

    ponteiroEncadeada = testePessoaEncadeada;


    pessoa *testePessoaEncadeada2 = new pessoa;
    testePessoaEncadeada2->nome = "gabe";
    testePessoaEncadeada2->rg = 21211221;
    testePessoaEncadeada2->proximo = NULL;

    testePessoaEncadeada->proximo = testePessoaEncadeada2;

    int funcaoUsuario = 0;

    while(funcaoUsuario != 9){
        cout << "tamanho da lista: " << retornaTamanho(ponteiroEncadeada) << "\n\n";
        cout << "funcao 1: insercao de uma pessoa no inicio da lista\n";
        cout << "funcao 2: insercao de uma pessoa no final da lista\n";
        cout << "funcao 3: insercao de uma pessoa na posicao N\n";
        cout << "funcao 4: remocao de uma pessoa no inicio da lista\n";
        cout << "funcao 5: remocao de uma pessoa no final da lista\n";
        cout << "funcao 6: remocao de uma pessoa na posicao N\n";
        cout << "funcao 7: procurar um Nome pelo RG\n";
        cout << "funcao 8: mostrar a lista\n";
        cout << "funcao 9: sair do sistema\n";
        cout << "\ndigite a opcao desejada e pressione ENTER: ";
        cin >> funcaoUsuario;
        limparTela();

    }


    return 0;
}
