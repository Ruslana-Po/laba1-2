#include<iostream>
#include<string>
#include<locale>
#include <fstream>
#include <sstream>
using namespace std;


//Стек


struct NodeS{
    string person;
    NodeS* next;
};

struct Stack{
    NodeS* head;
};
void push(Stack* stack, string element);
void pop(Stack* stack);
void Show(Stack* MyList);


//Дерево
struct Tree;
void AddTree(Tree*& root, int value);
void removeTree(Tree* root, int value);
void print_Tree(Tree* root, int level);
int countNumNodes(struct Tree *tree);
bool checkComplete(Tree* tree,  int index, int numberNodes);
//Очередь
struct NodeQ{
    string person;
    NodeQ* next;
};

struct Queue{
    NodeQ* head;
    NodeQ* tail;
};
void pushQ(Queue* queues, string element);
void popQ(Queue* queues);
void ShowQ(Queue* queues);
//list
struct Node {
    string number;
    Node* next;
};
struct List{
    Node* head;
};
void AddToHead(List* ptr, string element);
void AddToEnd(List* ptr, string element);
void DeleteToHead(List* node);
void DeleteToEnd(List* node);
void DeleteValue(List* ptr, string element);
void Quest(List* ptr, string element);
void PrintNode(List* ptr);
//2list

struct NodeT {
    string number;
    NodeT* next;
    NodeT* prev;
};

struct TwoList{
    NodeT* head;
    NodeT* tail;
};
void AddToEndTwo(TwoList* lists, string element);
void AddToHeadTwo(TwoList* lists, string element);
void DeleteToHeadTwo(TwoList* lists);
void DeleteToEndTwo(TwoList* lists);
void DeleteValueTwo(TwoList* lists, string element);
void QuestTwo(TwoList* ptr, string element);
void PrintNodeTwo(TwoList* ptr);
//hash
struct Item{
    string key;
    string value;
    Item* next;
};
struct HashTab{
    int sizeArr=5;
     Item** tabl;
    HashTab() {
        tabl = new Item*[sizeArr];
        for (int i = 0; i < sizeArr; i++) {
            tabl[i] = nullptr;
        }
    }

    ~HashTab() {
        for (int i = 0; i < sizeArr; i++) {
            delete tabl[i];
        }
        delete[] tabl;
    }

    //хэш функция
    int Hash(string itemKey){
        int result=0;
        for(char i: itemKey){
            result+=static_cast<int>(i);
        }
        return abs(result)%sizeArr;

    }
    bool isFull() {
        int count = 0;
        for (int i = 0; i < sizeArr; i++) {
            if(tabl[i]!=nullptr){
                count++;
            }


        }
        // Проверка на количество элементов
        return count >= sizeArr;
    }

    //Добавление
     void AddHash(string key, string value){
        int index= Hash(key);

        //Наличие уже такого ключа

            if(tabl[index] != nullptr && tabl[index]->key==key){
                cout << "Ключ '" << tabl[index]->key<< "' уже существует. Значение не добавлено." << endl;
                return;
    }

        //Проверка на есть ли место
        if (isFull()) {
            cout << "Хэш-таблица переполнена. Невозможно добавить новый элемент." << endl;
            return;
        }
        //Занят ли индекс
        if(tabl[index]==nullptr){
            Item* new_node= new Item{key, value, tabl[index]};
            tabl[index] = new_node;
        }else{
            for(int i=0; i<sizeArr;i++){
                if(tabl[i]==nullptr){
                     Item* new_node= new Item{key, value, tabl[i]};
                     tabl[i] = new_node;
                }
            }

        }

    }
    //Получение значения по ключу
    void KeyItem(string key){
          int index= Hash(key);
         if(tabl[index]->key==key){
            cout << "key: "<<key<<" value: "<< tabl[index]->value << endl;
            return;
         }
        cout<<"Такого ключа нет."<<endl;
    }

    //удаление элемента по ключу
    void DelValue(string key){
         int index= Hash(key);
         if(tabl[index]->key==key){
            delete tabl[index];
            tabl[index]=nullptr;
            return;
         }
        cout<<"Такого ключа нет."<<endl;
    }
    //Вывод
    void Print() {
        for (int i = 0; i < sizeArr; i++) {
                cout << " key: " << tabl[i]->key << " value: " << tabl[i]->value;
                cout<<endl;

        }

    }
};

//arr
struct Arr {
     // Указатель на массив
    string* number;
     // Текущий размер массива
    int sizes;
    // Вместимость массива
    int capacity;
    // Выделяемая память под массив
    Arr(int cap) : sizes(0), capacity(cap) {
        number = new string[capacity];
    }
    // Освобождаем память
    ~Arr() {
        delete[] number;
    }

    void reSize() {
        // Увеличиваем вместимость вдвое
        capacity *= 2;
        string* new_node = new string[capacity];
        for (int i = 0; i < sizes; ++i) {
            // Копируем старые данные
            new_node[i] = number[i];
        }
        // Освобождаем старую память
        delete[] number;
        number = new_node;
    }

    void AddArr(string value) {
        if (sizes >= capacity) {
            //меняем размер
            reSize();
        }
        // Добавляем элемент в конец
        number[sizes++] = value;
    }
    //Добавляем по индексу
    void AddAtIndex(int index, string value) {
        if (index < 0 || index > sizes) {
            cout << "Индекс вне диапазона!" << endl;
            return;
        }
        if (sizes >= capacity) {
            reSize();
        }
        for (int i = sizes; i > index; --i) {
            number[i] = number[i - 1];
        }
        number[index] = value;
        sizes++;
    }
    //Элемент по индексу
    void returnItemByIndex(int index) {
        if (index < 0 || index >= sizes) {
            cout << "Индекс вне диапазона!" << endl;
            return;
        }
        cout<< number[index]<<endl;
    }
    //Удаление по индексу
    void removeItemByIndex(int index) {
        if (index < 0 || index >= sizes) {
            cout << "Индекс вне диапазона!" << endl;
            return;
        }
        for (int i = index; i < sizes - 1; ++i) {
            number[i] = number[i + 1];
        }
        sizes--;
    }
    //Замена по индексу
    void replaceItemByIndex(int index, string value) {
        if (index < 0 || index >= sizes) {
            cout << "Индекс вне диапазона!" << endl;
            return;
        }
        number[index] = value;
    }
    //Текущий размер
    int Size() {
        return sizes;
    }
    void Print(){
        for (int i = 0; i < sizes; ++i) {
           cout<< number[i]<<" ";
        }

        cout << endl;
    }

};

