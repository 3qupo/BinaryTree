
// РЕКУРСИВНЫЙ ВАРИАНТ РЕАЛИЗАЦИИ
//#include <iostream>
//
//using namespace std;
//
//struct Node 
//{
//    int data;       // Данные в узле
//    Node* left;     // Указатель на левое поддерево
//    Node* right;    // Указатель на правое поддерево
//
//    Node(int value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//// Функция для обработки узла (вывод данных)
//void visit(Node* node) {
//    cout << node->data << " ";
//}
//
//// Рекурсивный обход: КЛП (Pre-order)
//void preOrder(Node* root) 
//{
//    if (root == nullptr) return;  // Базовый случай: дерево пусто
//    visit(root);                  // Обработка текущего узла
//    preOrder(root->left);         // Рекурсивно обходим левое поддерево
//    preOrder(root->right);        // Рекурсивно обходим правое поддерево
//}
//
//// Рекурсивный обход: ЛКП (In-order)
//void inOrder(Node* root) 
//{
//    if (root == nullptr) return;  // Базовый случай: дерево пусто
//    inOrder(root->left);          // Рекурсивно обходим левое поддерево
//    visit(root);                  // Обработка текущего узла
//    inOrder(root->right);         // Рекурсивно обходим правое поддерево
//}
//
//// Рекурсивный обход: ЛПК (Post-order)
//void postOrder(Node* root)
//{
//    if (root == nullptr) return;  // Базовый случай: дерево пусто
//    postOrder(root->left);        // Рекурсивно обходим левое поддерево
//    postOrder(root->right);       // Рекурсивно обходим правое поддерево
//    visit(root);                  // Обработка текущего узла
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//
//    Node* root = new Node(1);
//    root->left = new Node(2);
//    root->right = new Node(3);
//    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//
//    cout << "КЛП (Pre-order): ";
//    preOrder(root);
//    cout << endl;
//
//    cout << "ЛКП (In-order): ";
//    inOrder(root);
//    cout << endl;
//
//    cout << "ЛПК (Post-order): ";
//    postOrder(root);
//    cout << endl;
//
//    return 0;
//}



// ИТЕРАТИВНЫЙ ВАРИАНТ РЕАЛИЗАЦИИ
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//struct Node
//{
//    int data;       // Данные в узле
//    Node* left;     // Указатель на левое поддерево
//    Node* right;    // Указатель на правое поддерево
//
//    Node(int value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//// Функция для обработки узла (вывод данных)
//void visit(Node* node) {
//    cout << node->data << " ";
//}
//
//// Итеративный обход: КЛП (Pre-order)
//void iterativePreOrder(Node* root)
//{
//    if (root == nullptr) return;
//
//    stack<Node*> s;
//    s.push(root);
//
//    while (!s.empty()) {
//        Node* current = s.top();
//        s.pop();
//
//        visit(current);
//
//        // Сначала добавляем правого потомка, затем левого
//        if (current->right) s.push(current->right);
//        if (current->left) s.push(current->left);
//    }
//}
//
//// Итеративный обход: ЛКП (In-order)
//void iterativeInOrder(Node* root)
//{
//    stack<Node*> s;
//    Node* current = root;
//
//    while (current != nullptr || !s.empty()) {
//        // Достигнем самого левого узла
//        while (current != nullptr) {
//            s.push(current);
//            current = current->left;
//        }
//
//        // Обрабатываем узел
//        current = s.top();
//        s.pop();
//        visit(current);
//
//        // Переходим к правому поддереву
//        current = current->right;
//    }
//}
//
//// Итеративный обход: ЛПК (Post-order)
//void iterativePostOrder(Node* root)
//{
//    if (root == nullptr) return;
//
//    stack<Node*> s1, s2;
//    s1.push(root);
//
//    while (!s1.empty()) {
//        Node* current = s1.top();
//        s1.pop();
//        s2.push(current);
//
//        // Сначала добавляем левого, затем правого
//        if (current->left) s1.push(current->left);
//        if (current->right) s1.push(current->right);
//    }
//
//    // Обрабатываем элементы из второго стека
//    while (!s2.empty()) {
//        visit(s2.top());
//        s2.pop();
//    }
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//
//    Node* root = new Node(1);
//    root->left = new Node(2);
//    root->right = new Node(3);
//    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//
//    cout << "Итеративный КЛП (Pre-order): ";
//    iterativePreOrder(root);
//    cout << endl;
//
//    cout << "Итеративный ЛКП (In-order): ";
//    iterativeInOrder(root);
//    cout << endl;
//
//    cout << "Итеративный ЛПК (Post-order): ";
//    iterativePostOrder(root);
//    cout << endl;
//
//    return 0;
//}


// ОБХОД ДЕРЕВА В ШИРИНУ
#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;       // Данные в узле
    Node* left;     // Указатель на левое поддерево
    Node* right;    // Указатель на правое поддерево

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функция для обхода в ширину
void levelOrderTraversal(Node* root)
{
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " "; // Обработка узла

        // Добавляем потомков в очередь
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "check" << endl;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Обход в ширину (по уровням): ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
