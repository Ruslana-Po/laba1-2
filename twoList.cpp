//Двусвязный список
#include "header.h"


//Добавление в конец 2 связный
void AddToEndTwo(TwoList* lists, string element){
    NodeT* new_node = new NodeT;
    new_node->next=nullptr;
    new_node->number = element;
    if(lists->head!= nullptr){
        new_node->prev= lists->tail;
        lists->tail->next=new_node;
        lists->tail = new_node;
        return;
    }

    new_node->prev=nullptr;
    lists->head=lists->tail = new_node;
}

//Добавление в начало 2 связный
void AddToHeadTwo(TwoList* lists, string element){
     NodeT* new_node = new NodeT;
     new_node->prev=nullptr;
     new_node->number = element;
    if(lists->head!= nullptr){
        new_node->next=lists->head;
        lists->head->prev= new_node;
        lists->head=new_node;
        return;
    }
    new_node->next=nullptr;
    lists->head=lists->tail = new_node;
}

//Удаление c головы
void DeleteToHeadTwo(TwoList* lists){
    if (lists != nullptr){
        NodeT* delete_node = lists->head;
        lists->head = delete_node->next;
        if (lists->head != nullptr) {
            lists->head->prev = nullptr;
        }
         delete delete_node;
    }
}

void DeleteToEndTwo(TwoList* lists) {
    if (lists != nullptr && lists->tail != nullptr) {
        NodeT* delete_node = lists->tail;
        // Обновляем указатель tail на предыдущий элемент
        lists->tail = delete_node->prev;
        // Если список не пустой после удаления
        if (lists->tail != nullptr) {
            lists->tail->next = nullptr;
        } else {
            lists->head = nullptr;
        }

        delete delete_node;
    }
}



//Удаление по значению
void DeleteValueTwo(TwoList* lists, string element){
    if(lists->head->number==element && lists->head->next!=nullptr){
        NodeT* temp = lists->head;
        lists->head=lists->head->next;
        lists->head->prev=nullptr;
        delete temp;
        return;
    }else if(lists->head->number==element && lists->head->next==nullptr){
        lists->head->next=nullptr;
        lists->head= nullptr;
        delete lists->head;
        return;
    }

    if(lists->tail->number==element){
        NodeT* temp = lists->tail;
        lists->tail=lists->tail->prev;
        lists->tail->next=nullptr;
        delete temp;
        return;
    }
    //середина
    NodeT* temp=lists->head;
    NodeT* temp2;
    while(temp!= nullptr){
        if(temp->number==element){
            temp2=temp;
            temp2->prev->next=temp->next;
            temp2->next->prev=temp->prev;
            delete temp;
            return;
        }
        temp=temp->next;
    }
}

//Поиск по значению

void QuestTwo(TwoList* ptr, string element){
    NodeT* new_node = ptr->head;
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
void PrintNodeTwo(TwoList* ptr){
    NodeT* new_node = ptr->head;
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


