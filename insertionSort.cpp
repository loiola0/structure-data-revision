#include <iostream>
#include <vector>



void insertionSort(std::vector<int> &array){
    int i,j,key;
        for(i=1;i<array.size();i++){
            key = array[i];
            j = i-1;

                while(j>=0 && array[j]>key){
                        array[j+1] = array[j];
                        j = j-1;
                }

                array[j+1] = key;
        }

    
}

void printVector(std::vector<int> array){
    int i;
        for(i=0;i<array.size();i++){
            std::cout<< array[i]<<std::endl;
        }
}



int main(){
    std::vector<int> v1 = {5,1,4,3,2,21,23,4354,454,12,4,1,0};
    

    std::cout<<"Vector Original"<<std::endl;
    printVector(v1);

    insertionSort(v1);

    std::cout<<"Vector Post Ordenation"<<std::endl;
    printVector(v1);
}
