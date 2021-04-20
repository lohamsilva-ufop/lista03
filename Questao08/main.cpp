#include <iostream>
#include <vector>
#include <algorithm>

//faça com base na explicação: https://medium.com/olxbrasiltech/mediana-de-um-array-66ad96a07f3f

using namespace std;

void encontraMediana(int inicio, int fim, vector <int> med){

    vector <int> v_final;

    sort(inicio, fim, med);
    int meio = med/2;
    v_final(med[meio]);

    //depois ordenar v_final

      //pega o vetor retornado
    vector <int> v = encontraMediana();

    //ordena e encontra a mediana de novo
    sort(inicio, fim, v);
    int meio = med/2;
    v_final(med[meio]);

}

int divideVetor (vector <int> vet){
    int divisao = vet.size()/3;
    vector <int> v;

    for(int i=0; i<vet.size(); i = i + divisao){
        for (int j=i; j< i = i + divisao; j++){
                v.push_back(vet[j]);
                encontrMediana(i,i+divisao,v);
        }
    }



}

int main()
{
    vector <int> mediana {3,2,4,15,5,9,1,15,8,10,0,11,7,6,13};



    return 0;
}
