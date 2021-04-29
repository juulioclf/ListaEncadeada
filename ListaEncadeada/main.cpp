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

    if(ponteiroEncadeada->nome == ""){
        return 0;
    }

    int tamanho = 0;
    pessoa *ponteiroAuxiliar = ponteiroEncadeada;

    while(ponteiroAuxiliar != NULL){
        ponteiroAuxiliar = ponteiroAuxiliar->proximo;

        tamanho++;
    }

    return tamanho;

}

void imprimeLista(pessoa *ponteiroEncadeada){

    pessoa *ponteiroAuxiliar = ponteiroEncadeada;

    while(ponteiroAuxiliar != NULL){

        cout << ponteiroAuxiliar->nome << ", " << ponteiroAuxiliar->rg << "\n";

        ponteiroAuxiliar = ponteiroAuxiliar->proximo;
    }

}

void addComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){
    pessoa *novaPessoa = new pessoa;
    novaPessoa->nome = nome;
    novaPessoa->rg = rg;

    if(ponteiroEncadeada->nome== ""){
        novaPessoa->proximo = NULL;
    }else{
        novaPessoa->proximo = ponteiroEncadeada;
    }

    ponteiroEncadeada = novaPessoa;

}

void addFimEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *ponteiroAuxiliar = ponteiroEncadeada;

    while(ponteiroAuxiliar != NULL){

        if(ponteiroAuxiliar->proximo == NULL){
            ponteiroAuxiliar->proximo = novoValor;
            return;
        }

        ponteiroAuxiliar = ponteiroAuxiliar->proximo;
    }
}

int main(){

    int funcaoUsuario = 0, rg;
    string nome;
    pessoa *ponteiroEncadeada = new pessoa;

    while(funcaoUsuario != 9){

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

        switch(funcaoUsuario){
            case 1:

                cout << "\nfuncao 1: insercao de uma pessoa no inicio da lista\n";
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                addComecoEncadeada(ponteiroEncadeada, nome, rg);

                break;
            case 2:

                cout << "\nfuncao 1: insercao de uma pessoa no final da lista\n";
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                if(retornaTamanho(ponteiroEncadeada) == 0){
                    addComecoEncadeada(ponteiroEncadeada, nome, rg);
                }else{
                    addFimEncadeada(ponteiroEncadeada, nome, rg);
                }

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                cout << "\nfuncao 8: mostrar a lista\n";

                if(ponteiroEncadeada->nome == ""){
                    cout << "\nLista vazia, adicione numeros!\n";
                }else{
                    imprimeLista(ponteiroEncadeada);
                }

                break;

            case 9:

                cout << "\nSaindo do sistema..";

                break;

            default:
                cout << "\nPor favor, digite um numero valido!\n";

                break;
        }

    }

    return 0;
}
