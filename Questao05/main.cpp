#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int buscaBinaria(vector <int> A, int K){
    int i;
    int tamanho;

    tamanho = (A.size()/2);

    if (A[tamanho] == K){

        return tamanho;

    } else{

    if (K > A[tamanho]){

       for(i=tamanho; i<A.size(); i++){
            if (K == A[i] ){
                return i;
            }
       }
    } else{
            for(i=0; i<tamanho; i++){
                if (K == A[i] ){
                return i;
            }

       }
    }
}

}

int main()
{
    vector <int> Array;
    vector <int> Ordenado;
    int i;
    int chave;
    int total;
    int elemento;

    cout << "Qual e a quantidade de numeros do Array?";
    cin >> total;

    for (i=0; i<total; i++){
        cout << "Digite um elemento entre 0 e "<<total<<"que nao se repetiu:";
        cin >> elemento;
        Array.push_back(elemento);
    }

   sort(Array.begin(), Array.end());

   cout << "Vetor ordenado: ";
   for (i=0; i<total; i++){
         cout << Array[i] << ",";
    }


   cout << "Qual e a chave entre 1 e "<< total <<" ?";
   cin >> chave;


    cout << "A chave "<< chave << " esta na posicao:" << buscaBinaria(Array,chave);
    return 0;
}
