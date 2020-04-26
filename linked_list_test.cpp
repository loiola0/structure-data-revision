//realiza os testes
#include <cassert>
//chama a classe
#include <linked_list.hpp>

int main(){
    //instânciando o objeto
    LinkedList<int,std::string> lista{};

    //verifica se a lista é vazia
    assert(lista.isEmpty());

    lista.push(2,"reas");
    lista.pop();

    lista.push(3,"martins");
    lista.push(1,"victor");

    lista.insertAfter(1,2,"gabriel");

    
    lista.remove(3);

    lista.imprimir();
    return 0;
}