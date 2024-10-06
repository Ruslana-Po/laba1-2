//Очередь
#include "header.h"



//Добавление
void pushQ(Queue* queues, string element){
    NodeQ* new_node = new NodeQ;
    new_node->person = element;
    new_node->next= nullptr;
    if(queues->head!=nullptr){
        queues->tail->next=new_node;
        queues->tail= new_node;
    }else{
        queues->tail= new_node;
        queues->head=queues->tail;
    }
}

//Удаление
void popQ(Queue* queues){
    if(queues->head!= nullptr){
        NodeQ* new_head = new NodeQ;
        new_head=queues->head;
        cout<<"Delete "<<queues->head->person<<endl;
        queues->head=queues->head->next;
        delete new_head;
        return;
    }
   cout<<"Error list is empty"<<endl;
}

//Отоборажение
void ShowQ(Queue* queues){
    NodeQ* new_stack = new NodeQ;
    new_stack = queues->head;
    while (new_stack != nullptr)
    {
        cout <<  new_stack->person << " ";
        new_stack =  new_stack->next;
    }
    cout<<endl;
}
