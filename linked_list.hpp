// smart pointers
#include <memory>

#include <iostream>

//tipo opcional
#include <optional>


//metaclasse
template<typename Key,typename Val>
class LinkedList{
private:
    
    struct Node{
        Key key;
        Val val;

        std::unique_ptr<Node> next;


      Node(Key k,Val v):key{k},
                        val{v},
                        next{nullptr}
      {}
    };

    //função para ser aproveitada no insertAfter e remove.
    //esta função só pode ser chamado se existe a chave na lista, caso contrário dá 
    // falha de seguementação.
    static std::pair<Node*,Node*> nodesWithExistingKey(Node *node,Key key){
        Node *previousNode = nullptr;
        while(key != node->key){
            previousNode = node;
            node = node->next.get();
        }

        return std::make_pair(previousNode,node);
    }

 //cabeça da lista(primeiro nó).
 std::unique_ptr<Node> first;

protected:

    void pushNonExistingKey(Key key,Val val){
        std::unique_ptr<Node> newNode{std::make_unique<Node>(key,val)};
        newNode->next = std::move(first);
        first = std::move(newNode);
    }

public:

LinkedList(): first{nullptr}
{}

LinkedList(Key key,Val val):first{std::make_unique<Node>(key,val)}
{}

 bool isEmpty() const{
     return first == nullptr;
 }

//const indica que não está alterando a estrutura lista.
  std::optional<Val> search(Key key) const{
        Node *currentNode = first.get();

        while(currentNode){
            if(key == currentNode->key){
                
                return currentNode->val;

            }else{
                currentNode = currentNode->next.get();
            }
        }
    return {};
  }
 

 bool push(Key key, Val val){
     if(search(key)){
         return false;
     }
     else{
         pushNonExistingKey(key,val);
         return true;

     }
 }

 std::optional<std::pair<Key,Val>> pop(){
     if(isEmpty()){
         return {};
     }else{
         //salva o conteúdo do primeiro nó para exibi-lo como prometido.
         auto KeyVal = std::make_pair(first->key,first->val);
         first = std::move(first->next);

         return KeyVal;
     }
 }

 std::optional<Val>remove(Key key){

     if(search(key)){
         auto[previousNode,currentNode] = nodesWithExistingKey(first.get(),key);
        
        Val deleteVal = currentNode->val;

        if(previousNode){
          previousNode->next = std::move(currentNode->next);
        }else{
            first = std::move(currentNode->next);
        }
        

        return deleteVal;

     }else{
         return {};
     }
 }

 //insere após uma determinada chave(key).
 bool insertAfter(Key refkey,Key key,Val val){

     if(search(refkey) && !search(key)){
         std::unique_ptr<Node> newNode{std::make_unique<Node>(key,val)};
         auto[previousNode,currentNode] = nodesWithExistingKey(first.get(),refkey);

        //TODO declarou previousNode como nullptr para já que estamos utilizando-o, não notifique Warns.
         previousNode = nullptr;

         newNode->next = std::move(currentNode->next);
         currentNode->next = std::move(newNode);

         return true;
     }else{
         return false;
     }
 }

};
