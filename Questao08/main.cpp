#include <iostream>
#include <vector>
#include <algorithm>
//Autor: Loham Santos da Silva - PPGCC UFOP 2021/01

//faça com base na explicação: https://medium.com/olxbrasiltech/mediana-de-um-array-66ad96a07f3f

using namespace std;

//funcao responsavel por mostrar o vetor
void mostraVetor(vector <int> v){
    cout << "{";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ",";
    }
    cout << "}" << endl;
}

//funcao que encontra a mediana, onde recebe um conjunto ou subconjunto como parametro
void encontraMediana(vector <int> med){
int mediana;

if ((med.size()%2) == 1){

cout << "Vetor : ";
mostraVetor(med);

//caso base: se mediana tem 3 elementos, pegue o do meio
    if(med.size() == 3){
        sort(med.begin(), med.end()); //ordena o vetor de tres elementos
        cout << "Vetor com as medianas restantes ordenadas: ";
        mostraVetor(med);
        mediana = med[1]; //pegue o do meio
       cout << "Nao ha mais valores para analisar, Portanto, a mediana do conjunto principal e: " << mediana << endl;
    } else { //senao, divide o vetor em 3 e repita o passo ate encontrar o elemento do meio.

    vector <int> vet1; //declaração da 1ª parte do vetor
    vector <int> vet2; //declaração da 2ª parte do vetor
    vector <int> vet3; //declaração da 3ª parte do vetor
    vector <int> v_med; //declaração do vetor que pega todas as medianas encontradas
    int divisao = med.size()/3; //pega a quantidade de itens que terá cada vetor
    int meio; //variavel que pega o elemento do meio
    int fim_vet1 = divisao; //encontra o fim do vetor 1
    int inicio_vet2 = fim_vet1; //encontra o inicio do vetor 2
    int fim_vet2 = inicio_vet2+divisao; //encontra o fim do vetor 2
    int inicio_vet3 = fim_vet2; //encontra o inicio do vetor 3
    int fim_vet3 = med.size();//encontra o fim do vetor 3


     for (int i=0; i<fim_vet1; i++){
        vet1.push_back(med[i]); //popula  a 1ª parte do vetor
    }


    for (int i=inicio_vet2; i<fim_vet2; i++){
       vet2.push_back(med[i]); //popula  a 2ª parte do vetor
    }

    for (int i=inicio_vet3; i<fim_vet3; i++){
       vet3.push_back(med[i]); //popula  a 3ª parte do vetor
    }

    sort(vet1.begin(), vet1.end());
    cout << "vetor 1 ordenado: ";
    mostraVetor(vet1);
    meio = vet1.size()/2; //pega o elemento do meio
    cout << "mediana:" << vet1[meio] << endl;
    v_med.push_back(vet1[meio]); //insere no vetor a mediana encontrada

    sort(vet2.begin(), vet2.end());
    cout << "vetor 2 ordenado: ";
    mostraVetor(vet2);
    meio = vet2.size()/2; //pega o elemento do meio
    cout << "mdiana:" << vet2[meio] << endl;
    v_med.push_back(vet2[meio]); //insere no vetor a mediana encontrada


    sort(vet3.begin(), vet3.end());
    cout << "vetor 3 ordenado: ";
    mostraVetor(vet3);
    meio = vet3.size()/2; //pega o elemento do meio
    cout << "mediana:" << vet3[meio] << endl;
    v_med.push_back(vet3[meio]); //insere no vetor a mediana encontrada


    encontraMediana(v_med); //passa para a funcao recursiva o vetor de medianas encontradas.

    }
} else {
   /* cout << "Vetor : ";
    mostraVetor(med);

    vector <int> vet1; //declaração da 1ª parte do vetor
    vector <int> vet2; //declaração da 2ª parte do vetor

    int divisao = med.size()/2; //pega a quantidade de itens que terá cada vetor
    int fim_vet1 = divisao; //encontra o fim do vetor 1
    int inicio_vet2 = fim_vet1; //encontra o inicio do vetor 2
    int fim_vet2 = med.size();//encontra o fim do vetor 2


     for (int i=0; i<fim_vet1; i++){
        vet1.push_back(med[i]); //popula  a 1ª parte do vetor
    }


    for (int i=inicio_vet2; i<fim_vet2; i++){
       vet2.push_back(med[i]); //popula  a 2ª parte do vetor
    }

    cout << "vetor 1 ordenado: ";
    sort(vet1.begin(), vet1.end());
    mostraVetor(vet1);

    cout << "vetor 2 ordenado: ";
    sort(vet2.begin(), vet2.end());
    mostraVetor(vet2);

    cout << "A mediana e: " << (vet1[fim_vet1-1] + vet2[inicio_vet2])/2;*/

}



}

int main()
{
    //cria o vetor de medianas
    vector<int> mediana {3,2,4,15,5,9,1,15,8,10,0,11,7,6, 13};

    //chama a funcao para encontrar medianas
    encontraMediana(mediana);
    return 0;
}
