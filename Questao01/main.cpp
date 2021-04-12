#include <iostream>
#include <vector>

using namespace std;

void ordenaInsercao(vector<int> &vetor) {

    for (int i = 1; i < vetor.size(); i++) {
		int item = vetor[i];
		int j = i - 1;

		while ((j >= 0) && (vetor[j] > item)) {
			vetor[j + 1] = vetor[j];
			j--;
		}

		vetor[j + 1] = item;
	}
}

void imprimeArray(vector<int> &vetor){

    cout << "Vetor ordenado: {";
    for (int i = 0; i < vetor.size(); i++) {
		cout << vetor[i] << ",";
    }
    cout << "}";
}


int main()
{
    vector<int> Array;
    int i;
    int tamanho;
    int elemento;

    cout << "Digite o tamanho do vetor:";
    cin >> tamanho;

    for(i=0; i<tamanho; i++){
        cout << "Digite o elemento da " << i << " posicao:";
        cin >> elemento;
        Array.push_back(elemento);
    }

    ordenaInsercao(Array);
    imprimeArray(Array);

    return 0;
}
