//tipo opcional
#include<optional>

#include <stack.hpp>
/*

*PARA IMPLENTAÇÃO DA FILA FORAM UTILIZADAS DUAS PILHAS, VISTO QUE PODEMOS TAMBÉM
CRIAR A ESTRUTURA COM LISTAS ENCADIADAS.

*FOI TAMBÉM UTILIZADA COMPOSIÇÃO AO INVÉS DE HERANÇA COMO ACONTECEU COM A PILHA.

*/


template<typename Element>
class Queue{
private:
    //pilha na qual os elementos vão ser inseridos na fila.
    Stack<Element> inStk;
    // pilha da onde os elementos vão sair.
    Stack<Element> outStk;

public:
    Queue(): inStk{},
             outStk{}
    {}

    Queue(Element e): inStk{e},
                      outStk{}
    {}

    bool isEmpty(){
        return inStk.isEmpty() && outStk.isEmpty();
    }

    void insert(Element e){
        inStk.push(e);
    }

    std::optional<Element> remove(){
        if(isEmpty()){
            return {};
        }else{
            if(outStk.isEmpty()){
                while(!inStk.isEmpty()){
                    /* outra maneira
                    
                    auto e = inStk.pop();
                    outStk.push(*e);

                    */

                    outStk.push(*inStk.pop());

                }
            }
          return outStk.pop();
        }
    }

};