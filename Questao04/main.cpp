#include <iostream>
#include <vector>

using namespace std;

void geraSubconjuntos(vector <int> conj){
    int i;
    int j;

    cout << "{";
    for (i=0; i<conj.size(); i++){
            //cout << conj[i] << " , ";
        for (j=0; j<conj.size(); j++){
            if (conj[i] != conj[j]){
               cout << conj[i] <<" , " << conj[j];
            }
        }
    }
    cout << "}";
}

int main()
{
    vector <int> conjunto;
    int tamanho;
    int elemento;

    cout << "Quantos elementos terá o conjunto?";
    cin >> tamanho;

    for (int i=0;i<tamanho;i++){
        cout << "Insira o elemento " << i+1 << " do conjunto:";
        cin >> elemento;
        conjunto.push_back(elemento);
    }

    geraSubconjuntos(conjunto);



    return 0;
}
