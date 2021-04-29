#include <stdlib.h>
#include <new>
#include <iostream>

using namespace std;

void limparTela(){
    system("CLS");
}

int main(){

    int funcaoUsuario = 0;

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

    }


    return 0;
}
