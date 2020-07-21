#include <iostream>
#include <vector>




void Juntar(int vetor[], int ini, int meio, int fim, int vetAux[]) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (vetor[esq] < vetor[dir]))) {
            vetAux[i] = vetor[esq];
            ++esq;
        }
        else {
            vetAux[i] = vetor[dir];
            ++dir;
        }
    }
    //copiando o vetor de volta
    for (int i = ini; i < fim; ++i) {
        vetor[i] = vetAux[i];
    }
}

void MergeSort(int vetor[], int inicio, int fim, int vetorAux[]) {
    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    MergeSort(vetor, inicio, meio, vetorAux);
    MergeSort(vetor, meio, fim, vetorAux);
    Juntar(vetor, inicio, meio, fim, vetorAux);
}


void MergeSort(int vetor[], int tamanho) { //função que o usuario realmente chama
    //criando vetor auxiliar
    int vetorAux[tamanho];
    MergeSort(vetor, 0, tamanho, vetorAux);
}



void printVector(int *array,int size){
    int i;
        for(i=0;i<size;i++){
            std::cout<< array[i]<<std::endl;
        }
}


int main(){
    int v[] = {1,2,4,3,4,8,9,5,6,7};
   

    std::cout<< "Vector Original: "<<std::endl;
    printVector(v,10);

    MergeSort(v,10);

    std::cout<< "Vector Post Ordenation: "<<std::endl;
    printVector(v,10);

}