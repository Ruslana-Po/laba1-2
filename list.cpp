// 1 связные списки


#include "header.h"



//Добавление в голову 1 связный
void AddToHead(List* ptr, string element){
    Node* new_node = new Node;
    new_node->number = element;
    if(ptr->head == nullptr){
        new_node->next=ptr->head;
        ptr->head = new_node;
    }else{
         new_node->next = ptr->head;
         ptr->head=new_node;

    }

}

//Добавление в конец й связный
void AddToEnd(List* ptr, string element){
    Node* new_node = new Node;
    new_node->number = element;
    new_node->next = nullptr;
    if(ptr->head == nullptr){
        ptr->head = new_node;
    }else{
        Node* nextNode = ptr->head;
        while(nextNode-> next != nullptr){
            nextNode= nextNode->next;
        }
        nextNode->next = new_node;
    }
}


//Удаление c головы
void DeleteToHead(List* node){
    if(node->head != nullptr){
    Node* delete_node = node->head;
    node->head = delete_node->next;
    delete delete_node;
    }
}

//Удаление c конца
void DeleteToEnd(List* node){
    if(node->head!= nullptr){
        if (node->head->next == nullptr) {
            delete node->head;
            node->head=nullptr;
        }else{
        Node* delete_node = node->head;
        while(delete_node->next->next != nullptr){
            delete_node = delete_node->next;
        }
        delete delete_node->next;
        delete_node->next = nullptr;
    }
}
}
//Удаление по значению
void DeleteValue(List* ptr, string element){
    Node* new_node = ptr->head;
    Node* previous = nullptr;
    while(new_node!= nullptr && new_node->number != element){
        previous = new_node;
        new_node= new_node->next;
    }
    //Есть ли значение
    if(new_node == nullptr){
        cout<<"Error. There is no such meaning"<<endl;
        return;
    }
    //Первое ли оно
    if(previous == nullptr){
        ptr->head=new_node->next;
    }else{
        previous->next=new_node->next;
    }
    delete new_node;
}

//Поиск по значению

void Quest(List* ptr, string element){
    Node* new_node = ptr->head;
    while (new_node!= nullptr){
        if(new_node->number == element){
            cout<<"Found"<<endl;
            return;
        }
        new_node = new_node->next;
    }
    cout<<"Error: no such element"<<endl;
}

//Чтение
void PrintNode(List* ptr){
    Node* new_node = ptr->head;
    if(new_node == nullptr){
        cout<<"Error list is empty"<<endl;
        return;
    }
    cout<<"List: "<<endl;
    while(new_node != nullptr){
        cout<<new_node->number<<endl;
        new_node=new_node->next;
    }
}


