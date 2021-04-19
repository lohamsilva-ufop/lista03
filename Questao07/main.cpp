#include <iostream>
#include <vector>

/*Algoritmo feito com base na explicação: https://www.youtube.com/watch?v=8k-sJLUe0EE&ab_channel=EuclidesPiR2*/

using namespace std;

vector <int> pesagem(vector <int> peso, int quantidade){
    int moedas =  quantidade/3;
    int valor;
    int fim = 0;
    vector <int> copo;

    for(int i=0; i<quantidade; i = i + moedas){
            valor = 0;
            fim = fim + moedas;
            for (int j=i; j<fim; j++){
                    valor = valor + peso[j];
            }
         copo.push_back(valor);
         cout << valor << ",";
    }

return copo;
}

void balanca(vector <int> peso, int quantidade){
    vector <int> copo = pesagem(peso, quantidade);

    if(copo[0] == copo[1]){
        cout << "A balanca esta equilibrada. Esta no copo 3";
    } else{
        cout << "Algum dos copos estao em desequilibrio";
    }
}

int main()
{
    vector <int> peso;
    int quantidade;
    int valor;
    int peso_falsa;
    int posicao;

    cout << "Digite a quantidade de moedas:";
    cin >> quantidade;

    cout << "Digite o peso das moedas:";
    cin >> valor;

    cout << "Digite o peso da moedas falsa:";
    cin >> peso_falsa;

    posicao = rand() % quantidade;


    for (int i=0; i<quantidade; i++){
        if(i == posicao){
            peso.push_back(peso_falsa);
        } else{
            peso.push_back(valor);
        }
    }

    for (int i=0; i<quantidade; i++){
        cout << peso[i] << ",";
    }

    cout << endl;
  balanca(peso, quantidade);

    return 0;
}
