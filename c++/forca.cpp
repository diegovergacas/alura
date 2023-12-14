#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>

using namespace std;    //o marcador de uso das funções padrão de C++

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;     // ideia de dicionario, faz um vetor c/ caracterios e boleanos
vector<char> chutes_errados;    // vetor dinâmico

bool letra_existe(char chute){
    // for(int i = 0; 1 < PALAVRA_SECRETA.size(); i++){
    //     if(chute == PALAVRA_SECRETA[i]){
    //         return true;
    //     }
    // }

    for(char letra : PALAVRA_SECRETA){     // isso só existe nas versões a cima de C++11
        if(chute == letra){                // para isso o copilador tem que ser avisado 
            return true;                   // g++ forca.cpp -o forca.out -std=c++11 --> -std=c++11 tem que ser colocado no final
        }
    }
    return false;
}

bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void cabecalho(){
    cout << "***********************************" << endl;
    cout << "*** Bem-vindos ao jogo da FORCA ***" << endl;
    cout << "***********************************" << endl;
    cout << endl;
}

void printErros(){
    cout << "Chutes errados: ";
        for(char letra : chutes_errados){
            cout << letra << " ";
        }
    cout << endl;
}

void printPalava(){
    for(char letra : PALAVRA_SECRETA){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
            }
        }
    cout << endl;
}

void chuta(){
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)){
        cout << "Você acertou." << endl;
    }
    else{
        cout << "Você errou." << endl;
        chutes_errados.push_back(chute);    // adiciona no final do vetor dinâmico
    }
    cout << endl;
}

int main(){
    cabecalho();

    while(nao_acertou() && nao_enforcou()){
        printErros();
        printPalava();
        chuta(); 
    }
    cout << "Fim de jogo!" << endl;
    if(nao_acertou()){
        cout << "Você perdru!" << endl;
    }
    else{
        cout << "Parabéns! Você ganhou." << endl;
    }
}