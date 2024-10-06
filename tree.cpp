//Tree
#include "header.h"

struct Tree{
    int value;
    Tree* left;
    Tree* right;
    //1 знач, конструктор
    Tree(int val) : value(val), left(nullptr), right(nullptr){}
};

void AddTree(Tree*& root, int value){
     if (root == nullptr) {
     // Создаем новый узел, если дерево пустое
        Tree* new_root= new Tree(value);
        root=new_root;
        return;
    }

    if (value <= root->value) {
        // Рекурсивно добавляем в левое поддерево
        AddTree(root->left, value);
    } else {
        // Рекурсивно добавляем в правое поддерево
        AddTree(root->right, value);
    }
}

void removeTree(Tree* root, int value){
    if (root == nullptr) {
        cout<<"Такого элемента нету"<<endl;
        return;
    }

    if (value <= root->value) {
        if(value==root->value){
            cout<<"Есть элемент"<<endl;
            return;
        }
        removeTree(root->left, value);
    } else {
        if(value==root->value){
            cout<<"Есть элемент"<<endl;
            return;
        }
        removeTree(root->right, value);
    }

}

void print_Tree(Tree* root, int level)
{
    if (root != NULL)
    {
        print_Tree(root->left, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << root->value << endl;
        print_Tree(root->right, level + 1);
    }
}
// Count the number of nodes
int countNumNodes(struct Tree *tree) {
  if (tree == nullptr)
    return (0);
  return (1 + countNumNodes(tree->left) + countNumNodes(tree->right));
}

//Является ли дерево полным бинарным
bool checkComplete(Tree* tree,  int index, int numberNodes) {
     cout<<index<<endl;
  // Check if the tree is empty
  if (tree == nullptr)
    return true;
  if (index >= numberNodes)
    return false;


  return (checkComplete(tree->left, 2*index + 1, numberNodes) && checkComplete(tree->right, 2*index + 2, numberNodes));

}


