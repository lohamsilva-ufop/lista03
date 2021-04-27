#include <iostream>
#include <vector>

/*
Autor: Loham Santos da Silva - UFOP PPGCC 2021/01
Questao 04 feita com base no vídeo sobre backtracking:
1) https://www.youtube.com/watch?v=cFLGgc6GDGA&ab_channel=MarcosCastro
2) https://www.youtube.com/watch?v=WFqUqWy2crM&t=452s&ab_channel=MarcosCastro
*/


using namespace std;

void imprimeConjunto(vector <int> conj){ //funcao que imprime o vetor de conjuntos
    for (int i=0; i<conj.size(); i++){
        cout << conj[i] << ",";
    }
    cout << endl;
}

void troca(vector <int> &conj, int atual, int proximo){ //funcao que troca os elementos do conjunto em posicoes determinadas
    int aux = conj[atual];
    conj[atual] = conj[proximo];
    conj[proximo] = aux;
}

void gerarSubconjuntos(int inicio, int fim, vector <int> &conj){ //funcao que gera os subconjuntos:
    if (inicio == fim){ //se inicio é igual a fim, significa que chegamos a um caso válido. Se é, imprima esse caso:
        imprimeConjunto(conj); //chama funcao que imprime conjunto
    } else{ //senao, testaremos o outro caso valido
        for (int i=inicio; i<=fim; i++){
            troca(conj, inicio, i); //chamamos a funcao que irá trocar os elementos do conjunto de posicao
            gerarSubconjuntos(inicio+1, fim, conj); //recursivamente, analisaremos o proximo caso
            troca(conj, inicio, i); //trocamos novamente
        }
    }
}

int main()
{
    vector <int> conjunto; //cria o vetor de conjuntos
    int tamanho; //variavel que irá captar o tamanho do vetor
    int elemento; //variável que captará o elemento do conjunto

    cout << "Quantos elementos tera o conjunto?";
    cin >> tamanho;

    for (int i=0;i<tamanho;i++){
        cout << "Insira o elemento " << i+1 << " do conjunto:";
        cin >> elemento;
        conjunto.push_back(elemento);
    }

    gerarSubconjuntos(0, conjunto.size()-1, conjunto); //chama a funcao que irá gerar as combinações de subcnjuntos

    return 0;
}
