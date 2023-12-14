#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;    //o marcador de uso das funções padrão de C++

int main() {
    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhação *" << endl;
    cout << "*************************************" << endl;

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio(M) ou Difícil (D)" << endl;

    char nivel;
    cin >> nivel;

    int numeroTentativas = 0;
    if(nivel == 'F'){
        numeroTentativas = 15;
    }
    else if(nivel == 'M'){
        numeroTentativas = 10;
    }
    else if(nivel == 'D'){
        numeroTentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    cout << "O número secreto é "<< NUMERO_SECRETO << ". Não conte para niguém! " << endl;

    bool naoAcertou = true;
    int tentativas = 0;
    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numeroTentativas; tentativas++){
        int chute;
        cout << "Tentativa: " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "O valor do chute é " << chute << endl;

        double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontosPerdidos;

        bool acertou = chute == NUMERO_SECRETO ;
        bool maior = chute > NUMERO_SECRETO ;

        if (acertou){
            cout << "Parabéns! Você acertou!" << endl;
            naoAcertou = false;
            break;
        }
        else if (maior){
            cout << "Seu chute foi maior que o número secreto." << endl;
        }
        else {
            cout << "Seu chute foi menor que o número secreto." << endl;
        }
    }
    cout << "Fim de jogo." << endl;
    if(naoAcertou){
        cout << "Você perdeu, tente novamente!" << endl;
    }
    else{
        cout << "Você acertou o número secreto em " << tentativas << "tentativas" << endl;
        cout.precision(2);  // número de casa depois da vigula
        cout << fixed;      // fixa a vigula em sua origem, para garantir que o número não aparecerá em notação científica
        cout << "Pontação final: " << pontos << endl;
    }

}
