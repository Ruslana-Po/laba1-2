#include "header.h"
//Достаю строки
string InStrok(char* argv){
string strok;
 for(int j=0; argv[j] != '\0';j++){
        strok+=argv[j];
}

return strok;
}
//Очистка файла
void DelFil(char** argv){
 string fileStr;
 fileStr = InStrok(argv[2]);
 fstream clear_file(fileStr, ios::out);
 clear_file.close();
}

void WorkMasiv(string comand, Arr& arr){
    istringstream Stream(comand);
    string element;
    Stream>>element;
    string nameStruct;
    Stream>>nameStruct;
    //Массив
    if(element=="MPUSH"){
        string data;
        Stream>>data;
        arr.AddArr(data);
    }else if(element=="MADDINDEX"){
        string data;
        Stream>>data;
        int index;
        Stream>>index;
        arr.AddAtIndex(index, data);
    }else if(element=="MREMOVE"){
        int index;
        Stream>>index;
         arr.removeItemByIndex(index);
    }else if(element=="MREPLACE"){
        string data;
        Stream>>data;
        int index;
        Stream>>index;
        arr.replaceItemByIndex(index, data);
    }else if(element=="MRETURN"){
        int index;
        Stream>>index;
        arr.returnItemByIndex(index);
    }else if(element=="MSIZE"){
        int a = arr.Size();
        cout<<a<<endl;
    }else if(element=="PRINT"){
         arr.Print();
    }

}
//Дерево
void WorkTree(string comand,Tree*& root){
    istringstream Stream(comand);
    string element;
    Stream>>element;
    string nameStruct;
    Stream>>nameStruct;
     if(element=="TPUSH"){
        int data;
        Stream>>data;
        AddTree(root,data);
    }else if(element=="TREMOVE"){
        int data;
        Stream>>data;
        removeTree(root,data);
    }else if(element=="TCHECK"){
        int node_count = countNumNodes(root);
        int index = 0;
        if (checkComplete(root, index, node_count))
            cout << "The tree is a complete binary tree\n";
        else
            cout << "The tree is not a complete binary tree\n";
    }else if(element=="PRINT"){
        print_Tree(root, 0);
    }

}
//Stack
void WorkStack(string comand,Stack*& myStack){
    istringstream Stream(comand);
    string element;
    Stream>>element;
    string nameStruct;
    Stream>>nameStruct;
    if(element=="SPUSH"){
        string data;
        Stream>>data;
        push(myStack,data);
    }else if(element=="SPOP"){
        pop(myStack);
    }else if(element =="PRINT"){
        Show(myStack);
    }
}
//Очередь
void WorkQueue(string comand,Queue*& new_gueue){
    istringstream Stream(comand);
    string element;
    Stream>>element;
    string nameStruct;
    Stream>>nameStruct;
    if(element=="QPUSH"){
        string data;
        Stream>>data;
        pushQ( new_gueue,data);
    }else if(element=="QPOP"){
         popQ(new_gueue);
    }else if(element =="PRINT"){
         ShowQ(new_gueue);
    }

}
//list 1
void WorkList(string comand, List*& lists){
    istringstream Stream(comand);
    string element;
    Stream>>element;
    string nameStruct;
    Stream>>nameStruct;
    if(element=="LPUSHHEAD"){
        string data;
        Stream>>data;
        AddToHead(lists, data);
    }else if(element=="LPUSHEND"){
        string data;
        Stream>>data;
        AddToEnd(lists, data);
    }else if(element=="LPOPHEAD"){
        DeleteToHead(lists);
    }else if(element=="LRETURN"){
        string data;
        Stream>>data;
        Quest(lists, data);
    }else if(element=="LPOPEND"){
        DeleteToEnd(lists);
    }else if(element=="LPOPV"){
        string data;
        Stream>>data;
        DeleteValue(lists,data);
    }
    else if(element =="PRINT"){
        PrintNode(lists);
    }
}
//LIST TWO
void WorkTwoList(string comand,  TwoList*& listss){
    istringstream Stream(comand);
    string element;
    Stream>>element;
    string nameStruct;
    Stream>>nameStruct;
    if(element=="DPUSHHEAD"){
        string data;
        Stream>>data;
        AddToHeadTwo(listss, data);
    }else if(element=="DPUSHEND"){
        string data;
        Stream>>data;
        AddToEndTwo(listss, data);
    }else if(element=="DPOPHEAD"){
        DeleteToHeadTwo(listss);
    }else if(element=="DRETURN"){
        string data;
        Stream>>data;
        QuestTwo(listss, data);
    }else if(element=="DPOPEND"){
        DeleteToEndTwo(listss);
    }else if(element=="DPOPV"){
        string data;
        Stream>>data;
        DeleteValueTwo(listss,data);
    }
    else if(element =="PRINT"){
        PrintNodeTwo(listss);
    }
}

//ХЭШ
void WorkHash(string comand,   HashTab& ht){
    istringstream Stream(comand);
    string element;
    Stream>>element;
    string nameStruct;
    Stream>>nameStruct;
    if(element == "HPUSH"){
        string key;
        Stream>>key;
        string val;
        Stream>>val;
        ht.AddHash(key,val);
    }else if(element=="HRETURNVAL"){
        string key;
        Stream>>key;
         ht.KeyItem(key);
    }else if(element=="HPOP"){
        string key;
        Stream>>key;
        ht.DelValue(key);
    }
    else if(element =="PRINT"){
       ht.Print();
    }
}

int main(int args, char** argv){
    //Добавляем команду
    if(args ==5){
    string comand;
    comand = InStrok(argv[4]);
    //Раздел
    istringstream Stream(comand);
    string element;
    Stream>>element;
    string nameStruct;
    Stream>>nameStruct;
    //Если не печатать

    //Считываю все команды
    string fileStr;
    fileStr = InStrok(argv[2]);
    ifstream file;
    file.open(fileStr);
    string temporary="";

    //Cтруктуры
    Arr arr(5);
    Tree* root= nullptr;
    Stack* myStack= new Stack;
    myStack->head=nullptr;
    Queue* new_gueue= new Queue;
    new_gueue->head=nullptr;
    List* lists= new List;
    TwoList* listss= new TwoList;
    HashTab ht;

    //счит из файла
    while(getline(file, temporary)){
    if(temporary[0]=='M'){
         if(nameStruct=="myarr"){
        WorkMasiv(temporary,arr);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(temporary[0]=='T'){
         if(nameStruct=="mytree"){
            WorkTree(temporary,root);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(temporary[0]=='S'){
         if(nameStruct=="mystack"){
            WorkStack(temporary,myStack);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(temporary[0]=='Q'){
         if(nameStruct=="myqueue"){
            WorkQueue(temporary,new_gueue);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(temporary[0]=='L'){
         if(nameStruct=="mylist"){
            WorkList(temporary,lists);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(temporary[0]=='D'){
         if(nameStruct=="mylisttwo"){
            WorkTwoList(temporary,listss);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(temporary[0]=='H'){
         if(nameStruct=="myhash"){
            WorkHash(temporary,ht);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }

    }

    //команду делаем
    if(comand[0]=='M'){
         if(nameStruct=="myarr"){
        WorkMasiv(comand,arr);
         }else{
        cout<<"Неверное имя"<<endl;
    }
    }else if(comand[0]=='T'){
         if(nameStruct=="mytree"){
            WorkTree(comand,root);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(comand[0]=='S'){
         if(nameStruct=="mystack"){
            WorkStack(comand, myStack);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(comand[0]=='Q'){
         if(nameStruct=="myqueue"){
            WorkQueue(comand,new_gueue);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(comand[0]=='L'){
         if(nameStruct=="mylist"){
            WorkList(comand,lists);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(comand[0]=='D'){
         if(nameStruct=="mylisttwo"){
            WorkTwoList(comand,listss);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(comand[0]=='H'){
         if(nameStruct=="myhash"){
            WorkHash(comand,ht);
         }else{
        cout<<"Неверное имя"<<endl;
        }
    }else if(comand[0]=='P'){
    if(comand[1])
        if(nameStruct=="myarr"){
            WorkMasiv(comand,arr);
        }
        else if(nameStruct=="mytree"){
            WorkTree(comand,root);
        }
        else if(nameStruct=="mystack"){
            WorkStack(comand, myStack);
         }
        else if(nameStruct=="myqueue"){
            WorkQueue(comand,new_gueue);
         }
         else if(nameStruct=="mylist"){
            WorkList(comand,lists);
         }
         else if(nameStruct=="mylisttwo"){
            WorkTwoList(comand,listss);
         }
         else if(nameStruct=="myhash"){
            WorkHash(comand,ht);
         }
    }

        if(element!="PRINT"&&element!="MREMOVE"&&element!="MRETURN"&&element!="TREMOVE"&&element!="TCHECK"&&element!="LRETURN"&&element!="DRETURN"&&element!="HRETURNVAL"){
        string fileStr;
        fileStr = InStrok(argv[2]);
        ofstream file;
        file.open(fileStr, ios_base::app);
        file<<comand<<endl;
    }
    }
    //Удаляем
    if(args==3){
        DelFil(argv);
    }

}

