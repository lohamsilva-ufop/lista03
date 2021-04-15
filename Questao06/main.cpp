#include <iostream>
#include <algorithm>
#include <vector>

/*

*/

using namespace std;

int interpolationSearch(vector <int> Array, int elemento){
    int inicio;
    int fim;
    int posicao;

    inicio = 0;
    fim = Array.size()-1;

    while ((inicio <= fim) && (elemento >= Array[inicio]) && (elemento <= Array[fim])){
        posicao = inicio + (((double)(fim - inicio)/(Array[fim] - Array[inicio])) * (elemento - Array[inicio]));

        if(Array[posicao] == elemento){
            return posicao;
        } else if(elemento > Array[posicao]){
            inicio = posicao + 1;
        } else{
            fim = posicao - 1;
        }
     }

}


int main()
{
    int tamanho;
    int i;
    int elemento;

    vector <int> vetor;
    cout << "Quantos elementos tera o vetor?";
    cin >> tamanho;

    for (int i=0;i<tamanho;i++){
        cout << "Insira o " << i+1 << " elemento:";
        cin >> elemento;
        vetor.push_back(elemento);
    }

    cout << "Qual elemento deseja encontrar?";
    cin >> elemento;

    sort(vetor.begin(), vetor.end());

    cout << "O elemento esta na posicao "<< interpolationSearch(vetor, elemento);

    return 0;
}
