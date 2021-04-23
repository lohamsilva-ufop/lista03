#include <iostream>
#include <vector>
#include <numeric>

/*Algoritmo feito com base na explicação: https://www.youtube.com/watch?v=8k-sJLUe0EE&ab_channel=EuclidesPiR2*/

using namespace std;

//funcao que mostra o vettor de moedas
void mostraVetorMoedas(vector <int> moedas){
    cout << "Moedas: {";
    for (int i=0; i<moedas.size(); i++){
        cout << moedas[i] << ",";
    }
    cout << "}" << endl;
}

//funcao que encontra a moeda falsa. Recebe como prametro, o inicio, fim do e o vetor de moedas
int encontraMoedaFalsa(int inicio, int fim, vector <int> moedas){

/*
Premissa:
1) pegue o vetor de moedas, divida em 2
2) some o peso dos dois vetores separadamente (acumulador)
3) pegue o primeira peso do vetor e compare o peso com o segundo
4) se o primeiro vetor tem peso menor que o segundo, a moeda falsa esta nele. Senao, esta no segundo vetor
5) estando no vetor encontrado, passe novamente para a funcao atraves de recursao, ate encontrar a moeda falsa (quando tiver somente 1 moeda - caso base - retorne a posicao que a moeda esta)

ATENÇÃO:
Se na divisao, obtivermos um numero impar, tiramos a ultima moeda para deixar o vetor par
se na hora de pesar, os vetores tiverem pesos iguais, retorne a moeda (pois ela e a falsa)

*/
    int div =  (fim - inicio)/2; //verifica qual é o meio do vetor para dividir. Se vetor tem tam 10, o meio é = 5 (10-0)/2
    int resto = (fim - inicio)%2; //verifica qual é o resto da divisao (para realizar o tratamento do par ou impar
    int meio = inicio + div; //indica onde se inicia a 2ª parte do vetor


    int peso1; //variavel que irá captar o peso da 1ª parte do vetor
    int peso2; //variavel que irá captar o peso da 2ª parte do vetor
    int posicao; //variavel que irá captar a posicao que esta a moeda falsa

    if( (fim - inicio) == 1){ //caso base: se tivermos somente 1 moeda, retoena a posicao da moeda (inicio)
        return inicio;
    } else{ //senao

    if (resto == 1){ //tratamento: se resto da divisao e = 1, entao e impar. logo:
        fim = fim - 1; //o fim vai ate a penultima posicao para que possamos isolar a ultima moeda e deixar o vetor par
    }

    peso1 = accumulate(moedas.begin()+inicio, moedas.begin()+meio, 0); //pega o peso das moedas atraves de um acumular do inicio do vetor ate o meio
    peso2 = accumulate(moedas.begin()+meio, moedas.begin()+fim, 0); //pega o peso das moedas atraves de um acumular do meio do vetor ate n-1 (fim)

    if (peso1 < peso2){ //pesa e compara. Se for menor
        posicao = encontraMoedaFalsa(inicio, meio, moedas); //manda a 1ª parte do vetor
    } else if (peso1 > peso2) { //pesa e compara. Se for maior:
        posicao = encontraMoedaFalsa(meio, fim, moedas); //manda a 2ª parte do vetor
    } else{
        posicao = fim; //se os pesos forem iguais, manda a ultima moeda
    }
}
    return posicao; //retorna a posicao do vetor apos a recursao
}


int main()
{
    vector <int> moedas; //cria o vetor de moedas
    int quantidade; //cria a variavel quantidade para saber a quantidade de moedas
    int peso; //variavel para capturar o peso das moedas
    int peso_falsa; //variavel que captura o peso da moeda falsa
    int posicao; //variavel que insere a moeda falsa em uma posicao aleatoria

    //captura valores:

    cout << "Digite a quantidade de moedas:";
    cin >> quantidade;

    cout << "Digite o peso das moedas:";
    cin >> peso;

    cout << "Digite o peso da moeda falsa (deve ser menor que as outras):";
    cin >> peso_falsa;

    //escolhe a posição aleatoria da moeda falsa
    posicao = rand() % quantidade;

    //loop para inserir o peso das moedas no vetor.
    for (int i=0; i<quantidade; i++){
        if(i == posicao){ //se i é igual a posicao aletoria, insere a moeda falsa
            moedas.push_back(peso_falsa);
        } else{
            moedas.push_back(peso);
        }
    }

    //mostra o vetor de moedas
    mostraVetorMoedas(moedas);


    //chama a funcao para encontrar a moeda falsa, passando como parametro a posicao inicial, final do - e o vetor
    cout << "A moeda falsa esta na " <<  encontraMoedaFalsa(0, moedas.size(), moedas) << " posicao";

    return 0;
}
