//стек

#include "header.h"


//Добавление
void push(Stack* stack, string element){
    NodeS* new_node = new NodeS{element, nullptr};
    new_node->next = stack->head;
    stack->head = new_node;
}

//Удаление
void pop(Stack* stack){
    NodeS* new_head = new NodeS;
    new_head = stack->head->next;
    delete stack->head;
    stack->head= new_head;
}

//Отоборажение
void Show(Stack* MyList){
    NodeS* new_stack = new NodeS;
    new_stack = MyList->head;
    while ( new_stack != nullptr)
    {
        cout <<  new_stack->person << " ";
         new_stack =  new_stack->next;
    }
    cout<<endl;
}
