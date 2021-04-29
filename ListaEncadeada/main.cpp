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

void addPosicaoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg, int posicao){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *ponteiroAuxiliar = ponteiroEncadeada;

    int i = 0;

    while(i <= posicao){


        if(i == posicao - 1){

            pessoa *aux = new pessoa;

            aux->proximo = ponteiroAuxiliar->proximo;

            ponteiroAuxiliar->proximo = novoValor;

            novoValor->proximo = aux->proximo;

            free(aux);

        }

        ponteiroAuxiliar = ponteiroAuxiliar->proximo;

        i++;
    }

}

void popComecoEncadeada(pessoa *&ponteiroEncadeada){

    if(ponteiroEncadeada->proximo == NULL){

        pessoa *novoValor = new pessoa;
        novoValor->nome = "";
        novoValor->rg = 0;
        novoValor->proximo = NULL;

        ponteiroEncadeada = novoValor;
    }else{
        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }

}

void popFimEncadeada(pessoa *&ponteiroEncadeada){

    pessoa *ponteiroAuxiliar = new pessoa;
    pessoa *aux = new pessoa;

    ponteiroAuxiliar = ponteiroEncadeada;

    while(ponteiroAuxiliar->proximo != NULL){

        aux = ponteiroAuxiliar;
        ponteiroAuxiliar = ponteiroAuxiliar->proximo;
    }

    aux->proximo = NULL;
}

void popPosicaoEncadeada(pessoa *&ponteiroEncadeada, int posicao){

    pessoa *ponteiroAuxiliar = ponteiroEncadeada;

    int i = 0;

    while(i <= posicao){

        if(i == (posicao -1)){

            pessoa *aux = new pessoa;

            aux = ponteiroAuxiliar->proximo;

            ponteiroAuxiliar->proximo = aux->proximo;

            free(aux);

        }

        ponteiroAuxiliar = ponteiroAuxiliar->proximo;

        i++;
    }

}

string retornaNomeEncadeada(pessoa *&ponteiroEncadeada, int rg){

    string nome = "Nao encontrado";

    pessoa *ponteiroAuxiliar = ponteiroEncadeada;

    while(ponteiroAuxiliar != NULL){


        if(ponteiroAuxiliar->rg == rg){

            nome = ponteiroAuxiliar->nome;
            return nome;
        }

        ponteiroAuxiliar = ponteiroAuxiliar->proximo;
    }

    return nome;

}


int main(){

    int funcaoUsuario = 0, rg, posicao;
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

                cout << "funcao 3: insercao de uma pessoa na posicao N\n\n";
                cout << "Digite uma posicao: ";
                cin >> posicao;
                cout << "Digite um nome: ";
                cin >> nome;
                cout << "Digite um RG: ";
                cin >> rg;

                if(posicao == 0){

                    addComecoEncadeada(ponteiroEncadeada, nome, rg);

                }else if(posicao == retornaTamanho(ponteiroEncadeada) - 1){

                    addFimEncadeada(ponteiroEncadeada, nome, rg);
                }else{

                    addPosicaoEncadeada(ponteiroEncadeada, nome, rg, posicao);
                }

                break;
            case 4:

                cout << "funcao 4: remocao de uma pessoa no inicio da lista\n\n";

                popComecoEncadeada(ponteiroEncadeada);

                break;
            case 5:

                cout << "funcao 5: remocao de uma pessoa no final da lista\n\n";

                if(retornaTamanho(ponteiroEncadeada) == 0){

                    popComecoEncadeada(ponteiroEncadeada);
                }else{

                    popFimEncadeada(ponteiroEncadeada);
                }

                break;
            case 6:

                cout << "funcao 6: remocao de uma pessoa na posicao N\n\n";
                cout << "digite uma posicao: ";
                cin >> posicao;

                if(posicao == 0){

                    popComecoEncadeada(ponteiroEncadeada);

                }else if(posicao == retornaTamanho(ponteiroEncadeada) - 1){

                    popFimEncadeada(ponteiroEncadeada);
                }else{

                    popPosicaoEncadeada(ponteiroEncadeada, posicao);
                }

                break;
            case 7:

                cout << "funcao 7: procurar um Nome pelo RG\n\n";
                cout << "Digite um RG: ";
                cin >> rg;

                cout << "o nome do RG " << rg << " eh: "<< retornaNomeEncadeada(ponteiroEncadeada, rg) << "\n\n";

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
