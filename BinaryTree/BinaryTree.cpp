
/// РЕКУРСИВНЫЙ ВАРИАНТ РЕАЛИЗАЦИИ
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



/// ИТЕРАТИВНЫЙ ВАРИАНТ РЕАЛИЗАЦИИ
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


/// ОБХОД ДЕРЕВА В ШИРИНУ
//#include <iostream>
//#include <queue>
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
//// Функция для обхода в ширину
//void levelOrderTraversal(Node* root)
//{
//    if (root == nullptr) return;
//
//    queue<Node*> q;
//    q.push(root);
//
//    while (!q.empty()) {
//        Node* current = q.front();
//        q.pop();
//
//        cout << current->data << " "; // Обработка узла
//
//        // Добавляем потомков в очередь
//        if (current->left) q.push(current->left);
//        if (current->right) q.push(current->right);
//    }
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//
//    cout << "check" << endl;
//
//    Node* root = new Node(1);
//    root->left = new Node(2);
//    root->right = new Node(3);
//    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//
//    cout << "Обход в ширину (по уровням): ";
//    levelOrderTraversal(root);
//    cout << endl;
//
//    return 0;
//}


/// Алгоритм 1. Алгоритм блочной обработки битового массива
//#include <iostream>
//#include <bitset>
//
//using namespace std;
//
//void processBitArray(uint32_t* array, int n, int l, int k)
//{
//    int i = 0; // Индекс текущего элемента массива
//    int j = 0; // Смещение внутри элемента массива
//
//    while (i < n) 
//    {
//        // Извлечение текущего блока
//        uint32_t mask = ((1 << k) - 1) << j;
//        uint32_t block = (array[i] & mask) >> j;
//
//        // Обработка блока (пример: инвертирование)
//        block ^= (1 << k) - 1;
//
//        // Установка измененного блока
//        array[i] = (array[i] & ~mask) | ((block << j) & mask);
//
//        // Перемещение окна на следующий блок
//        j += k;
//        if (j >= l) {
//            j -= l;
//            i++;
//        }
//    }
//}
//
//int main() 
//{
//    setlocale(LC_ALL, "Russian");
//
//    int n = 3;   // Количество элементов в массиве
//    int l = 32;  // Размер элемента массива в битах
//    int k = 8;   // Размер блока в битах
//
//    // Пример массива битовых данных
//    uint32_t bitArray[3] = { 0xFFFFFFFF, 0x12345678, 0x87654321 };
//
//    // Вывод исходного массива
//    cout << "Оригинальный массив:\n";
//    for (int i = 0; i < n; ++i) {
//        cout << bitset<32>(bitArray[i]) << endl;
//    }
//
//    // Обработка массива
//    processBitArray(bitArray, n, l, k);
//
//    // Вывод измененного массива
//    cout << "Измененный массив:\n";
//    for (int i = 0; i < n; ++i) {
//        cout << bitset<32>(bitArray[i]) << endl;
//    }
//
//    return 0;
//}


/// Алгоритм 2. Алгоритм сложения целых чисел произвольной точности
//#include <iostream>
//
//using namespace std;
//
//class BigInt 
//{
//private:
//    int* digits; // Динамический массив для хранения цифр числа
//    int length;  // Длина числа
//
//public:
//    BigInt() : length(0)
//    {
//        digits = new int[1];
//        digits[0] = 0;
//    }
//
//    BigInt(const char* number)
//    {
//        length = 0;
//        while (number[length] != '\0') {
//            ++length;
//        }
//
//        digits = new int[length];
//        for (int i = 0; i < length; ++i) {
//            digits[i] = number[length - i - 1] - '0';
//        }
//    }
//
//    ~BigInt() {
//        delete[] digits;
//    }
//
//    void print() const 
//    {
//        for (int i = length - 1; i >= 0; --i) {
//            cout << digits[i];
//        }
//        cout << endl;
//    }
//
//    BigInt add(const BigInt& other) const
//    {
//        int maxLength = max(length, other.length) + 1;
//        BigInt result;
//        delete[] result.digits;
//        result.digits = new int[maxLength];
//        for (int i = 0; i < maxLength; ++i) {
//            result.digits[i] = 0;
//        }
//
//        int carry = 0;
//        result.length = maxLength - 1;
//
//        for (int i = 0; i < result.length; ++i) 
//        {
//            int x = (i < length) ? digits[i] : 0;
//            int y = (i < other.length) ? other.digits[i] : 0;
//            int sum = x + y + carry;
//            result.digits[i] = sum % 10;
//            carry = sum / 10;
//        }
//
//        if (carry > 0) {
//            result.digits[result.length] = carry;
//            ++result.length;
//        }
//
//        return result;
//    }
//};
//
//int main() 
//{
//    setlocale(LC_ALL, "Russian");
//
//    char num1[1000], num2[1000];
//
//    cout << "Введите первое число: ";
//    cin >> num1;
//
//    cout << "Введите второе число: ";
//    cin >> num2;
//
//    BigInt bigInt1(num1);
//    BigInt bigInt2(num2);
//
//    BigInt sum = bigInt1.add(bigInt2);
//
//    cout << "Сумма: ";
//    sum.print();
//
//    return 0;
//}


/// Алгоритм 3. Алгоритм вычитания целых чисел произвольной точности
//#include <iostream>
//
//using namespace std;
//
//class BigInt {
//private:
//    int* digits; // Динамический массив для хранения цифр числа
//    int length;  // Длина числа
//
//public:
//    BigInt() : length(0) {
//        digits = new int[1];
//        digits[0] = 0;
//    }
//
//    BigInt(const char* number) {
//        length = 0;
//        while (number[length] != '\0') {
//            ++length;
//        }
//
//        digits = new int[length];
//        for (int i = 0; i < length; ++i) {
//            digits[i] = number[length - i - 1] - '0';
//        }
//    }
//
//    ~BigInt() {
//        delete[] digits;
//    }
//
//    void print() const {
//        for (int i = length - 1; i >= 0; --i) {
//            cout << digits[i];
//        }
//        cout << endl;
//    }
//
//    // Метод вычитания
//    BigInt subtract(const BigInt& other) const
//    {
//        int maxLength = max(length, other.length);
//        BigInt result;
//        delete[] result.digits;
//        result.digits = new int[maxLength];
//        for (int i = 0; i < maxLength; ++i) {
//            result.digits[i] = 0;
//        }
//
//        int borrow = 0;
//        result.length = maxLength;
//
//        for (int i = 0; i < maxLength; ++i)
//        {
//            int x = (i < length) ? digits[i] : 0;
//            int y = (i < other.length) ? other.digits[i] : 0;
//
//            int diff = x - y - borrow;
//            if (diff < 0) {
//                diff += 10;
//                borrow = 1;
//            }
//            else {
//                borrow = 0;
//            }
//
//            result.digits[i] = diff;
//        }
//
//        // Убираем ведущие нули
//        while (result.length > 1 && result.digits[result.length - 1] == 0) {
//            --result.length;
//        }
//
//        return result;
//    }
//};
//
//int main() 
//{
//    setlocale(LC_ALL, "Russian");
//
//    char num1[1000], num2[1000];
//
//    cout << "Введите первое число: ";
//    cin >> num1;
//
//    cout << "Введите второе число: ";
//    cin >> num2;
//
//    BigInt bigInt1(num1);
//    BigInt bigInt2(num2);
//
//    BigInt diff = bigInt1.subtract(bigInt2);
//
//    cout << "Разница: ";
//    diff.print();
//
//    return 0;
//}


/// Алгоритм 4. Алгоритм умножения целого числа произвольной точности на целое число фиксированной точности
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class BigInt
//{
//private:
//    int* digits; // Динамический массив для хранения цифр числа
//    int length;  // Длина числа
//
//public:
//    BigInt() : length(1) 
//    {
//        digits = new int[length];
//        digits[0] = 0;
//    }
//
//    BigInt(const char* number) 
//    {
//        length = strlen(number);
//        digits = new int[length];
//
//        for (int i = 0; i < length; ++i) {
//            digits[i] = number[length - i - 1] - '0'; // Храним число в обратном порядке
//        }
//    }
//
//    ~BigInt() {
//        delete[] digits;
//    }
//
//    // Метод умножения на одноразрядное число
//    void multiplyBySingleDigit(int digit) 
//    {
//        int carry = 0;
//
//        for (int i = 0; i < length; ++i) 
//        {
//            int product = digits[i] * digit + carry;
//            digits[i] = product % 10;
//            carry = product / 10;
//        }
//
//        // Если есть перенос, увеличиваем длину
//        while (carry > 0)
//        {
//            length++;
//            int* newDigits = new int[length];
//
//            for (int i = 0; i < length - 1; ++i) {
//                newDigits[i] = digits[i];
//            }
//
//            newDigits[length - 1] = carry % 10;
//            delete[] digits;
//            digits = newDigits;
//            carry /= 10;
//        }
//    }
//
//    // Метод умножения на число произвольной точности
//    void multiply(const BigInt& other) 
//    {
//        int* resultDigits = new int[length + other.length]();
//        int resultLength = length + other.length;
//
//        for (int i = 0; i < length; ++i)
//        {
//            int carry = 0;
//
//            for (int j = 0; j < other.length; ++j) 
//            {
//                int product = digits[i] * other.digits[j] + resultDigits[i + j] + carry;
//                resultDigits[i + j] = product % 10;
//                carry = product / 10;
//            }
//
//            resultDigits[i + other.length] += carry;
//        }
//
//        delete[] digits;
//        digits = resultDigits;
//        length = resultLength;
//
//        // Убираем ведущие нули
//        while (length > 1 && digits[length - 1] == 0) {
//            length--;
//        }
//    }
//
//    void print() const 
//    {
//        for (int i = length - 1; i >= 0; --i) {
//            cout << digits[i];
//        }
//        cout << endl;
//    }
//};
//
//int main() 
//{
//    setlocale(LC_ALL, "Russian");
//
//    char num1[1000], num2[1000];
//
//    cout << "первое число: ";
//    cin >> num1;
//
//    cout << "второе число: ";
//    cin >> num2;
//
//    BigInt bigInt1(num1);
//    BigInt bigInt2(num2);
//
//    bigInt1.multiply(bigInt2);
//
//    cout << "Произведение: ";
//    bigInt1.print();
//
//    return 0;
//}


/// Алгоритм 5.	Алгоритм нахождения остатка от деления целого числа произвольной точности на целое число фиксированной точности
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class BigInt {
//private:
//    int* digits; // Динамический массив для хранения цифр числа
//    int length;  // Длина числа
//
//public:
//    BigInt() : length(1) 
//    {
//        digits = new int[length];
//        digits[0] = 0;
//    }
//
//    BigInt(const char* number)
//    {
//        length = strlen(number);
//        digits = new int[length];
//
//        for (int i = 0; i < length; ++i) {
//            digits[i] = number[length - i - 1] - '0'; // Храним число в обратном порядке
//        }
//    }
//
//    ~BigInt() {
//        delete[] digits;
//    }
//
//    int modBySingleDigit(int divisor) 
//    {
//        int remainder = 0;
//
//        for (int i = length - 1; i >= 0; --i) {
//            // Переносим остаток из предыдущего шага и добавляем текущую цифру
//            remainder = (remainder * 10 + digits[i]) % divisor;
//        }
//
//        return remainder;
//    }
//
//    void print() const 
//    {
//        for (int i = length - 1; i >= 0; --i) {
//            cout << digits[i];
//        }
//        cout << endl;
//    }
//};
//
//int main() 
//{
//    setlocale(LC_ALL, "Russian");
//
//    char num1[1000];
//    int divisor;
//
//    cout << "Введите число: ";
//    cin >> num1;
//
//    cout << "Введите одноразрядное число для деления: ";
//    cin >> divisor;
//
//    BigInt bigInt(num1);
//
//    int remainder = bigInt.modBySingleDigit(divisor);
//
//    cout << "Остаток от деления: " << remainder << endl;
//
//    return 0;
//}


/// Алгоритм 6.	Алгоритм нахождения частного от деления целого числа произвольной точности на целое число фиксированной точности
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class BigInt 
//{
//private:
//    int* digits; // Динамический массив для хранения цифр числа
//    int length;  // Длина числа
//
//public:
//    BigInt() : length(1) 
//    {
//        digits = new int[length];
//        digits[0] = 0;
//    }
//
//    BigInt(const char* number)
//    {
//        length = strlen(number);
//        digits = new int[length];
//
//        for (int i = 0; i < length; ++i) {
//            digits[i] = number[length - i - 1] - '0'; // Храним число в обратном порядке
//        }
//    }
//
//    ~BigInt() {
//        delete[] digits;
//    }
//
//    void divideBySingleDigit(int divisor, BigInt& quotient) 
//    {
//        int* quotientDigits = new int[length]; // Массив для хранения частного
//        int remainder = 0; // Остаток от деления
//
//        for (int i = length - 1; i >= 0; --i) 
//        {
//            // Переносим остаток из предыдущего шага и добавляем текущую цифру
//            remainder = remainder * 10 + digits[i];
//
//            // Частное для текущего разряда
//            quotientDigits[i] = remainder / divisor;
//
//            // Обновляем остаток
//            remainder = remainder % divisor;
//        }
//
//        // Убираем ведущие нули в частном
//        int newLength = length;
//        while (newLength > 1 && quotientDigits[newLength - 1] == 0) {
//            newLength--;
//        }
//
//        // Копируем результат в новый объект BigInt
//        quotient.length = newLength;
//        quotient.digits = new int[quotient.length];
//
//        for (int i = 0; i < quotient.length; ++i) {
//            quotient.digits[i] = quotientDigits[i];
//        }
//
//        delete[] quotientDigits;
//    }
//
//    // Вывод числа
//    void print() const 
//    {
//        for (int i = length - 1; i >= 0; --i) {
//            cout << digits[i];
//        }
//        cout << endl;
//    }
//};
//
//int main() 
//{
//    setlocale(LC_ALL, "Russian");
//
//    char num1[1000];
//    int divisor;
//
//    cout << "Введите число: ";
//    cin >> num1;
//
//    cout << "Введите одноразрядное число для деления: ";
//    cin >> divisor;
//
//    BigInt bigInt(num1);
//    BigInt quotient;
//
//    bigInt.divideBySingleDigit(divisor, quotient);
//
//    cout << "Частное от деления: ";
//    quotient.print();
//
//    return 0;
//}


/// Алгоритм 7.	Алгоритм вставки элемента в Л1 – список перед обрабатываемым элементом
//#include <iostream>
//
//using namespace std;
//
//struct ListNode 
//{
//    int data;          // Данные элемента
//    ListNode* next;    // Указатель на следующий элемент
//};
//
//void insertElement(ListNode*& head, int x) 
//{
//    // Создаем новый элемент
//    ListNode* newNode = new ListNode();
//    newNode->data = x;
//    newNode->next = nullptr;
//
//    // Если список пуст, новый элемент становится головой
//    if (head == nullptr) {
//        head = newNode;
//    }
//    else 
//    {
//        // Вставляем новый элемент перед первым элементом
//        newNode->next = head;
//        head = newNode;
//    }
//}
//
//void printList(ListNode* head)
//{
//    while (head != nullptr) {
//        cout << head->data << " ";
//        head = head->next;
//    }
//    cout << endl;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//
//    ListNode* list = nullptr;
//
//    // Создаем список 1 -> 2 -> 3
//    insertElement(list, 3);
//    insertElement(list, 2);
//    insertElement(list, 1);
//
//    cout << "Список до вставки: ";
//    printList(list);
//
//    // Вставляем элемент перед первым элементом
//    insertElement(list, 0);
//
//    cout << "Список после вставки: ";
//    printList(list);
//
//    return 0;
//}


/// Алгоритм 8.	Алгоритм удаления обрабатываемого элемента из Л1 – списка
//#include <iostream>
//
//using namespace std;
//
//struct ListNode
//{
//    int data;          // Данные элемента
//    ListNode* next;    // Указатель на следующий элемент
//};
//
//void deleteElement(ListNode*& head)
//{
//    if (head == nullptr) {
//        cout << "Список пуст!" << endl;
//        return;
//    }
//
//    // Удаляем первый элемент (обрабатываемый элемент)
//    ListNode* temp = head;
//    head = head->next;  // Новый первый элемент становится головой списка
//    delete temp;        // Освобождаем память удаленного элемента
//}
//
//void printList(ListNode* head) 
//{
//    while (head != nullptr) 
//    {
//        cout << head->data << " ";
//        head = head->next;
//    }
//
//    cout << endl;
//}
//
//int main() 
//{
//    setlocale(LC_ALL, "Russian");
//
//    ListNode* list = nullptr;
//
//    // Создаем список 1 -> 2 -> 3
//    ListNode* node1 = new ListNode();
//    node1->data = 1;
//    node1->next = nullptr;
//    list = node1;
//
//    ListNode* node2 = new ListNode();
//    node2->data = 2;
//    node2->next = nullptr;
//    node1->next = node2;
//
//    ListNode* node3 = new ListNode();
//    node3->data = 3;
//    node3->next = nullptr;
//    node2->next = node3;
//
//    cout << "Список до удаления: ";
//    printList(list);
//
//    deleteElement(list);
//
//    cout << "Список после удаления: ";
//    printList(list);
//
//    return 0;
//}


/// Алгоритм 9.	Алгоритм линейных операций для разреженных многочленов
//#include <iostream>
//
//using namespace std;
//
//// Класс для представления одного члена разреженного многочлена
//class SparseTerm
//{
//public:
//    int degree;      // Степень
//    int coefficient; // Коэффициент
//
//    // Конструктор для инициализации члена
//    SparseTerm(int degree = 0, int coefficient = 0)
//        : degree(degree), coefficient(coefficient) {
//    }
//};
//
//// Класс для представления разреженного многочлена
//class SparsePolynomial 
//{
//private:
//    static const int MAX_TERMS = 100;  // Максимальное количество членов
//    SparseTerm terms[MAX_TERMS];       // Массив для хранения членов многочлена
//    int numTerms;                      // Количество членов в многочлене
//
//public:
//    // Конструктор
//    SparsePolynomial() : numTerms(0) {}
//
//    // Метод для добавления нового члена в разреженный многочлен
//    void addTerm(int degree, int coefficient) 
//    {
//        if (numTerms < MAX_TERMS) {
//            terms[numTerms] = SparseTerm(degree, coefficient);
//            numTerms++;
//        }
//    }
//
//    // Функция для сложения двух разреженных многочленов
//    SparsePolynomial add(const SparsePolynomial& poly2) const
//    {
//        SparsePolynomial result;
//
//        int i = 0, j = 0;
//        while (i < numTerms && j < poly2.numTerms)
//        {
//            if (terms[i].degree == poly2.terms[j].degree) 
//            {
//                result.addTerm(terms[i].degree, terms[i].coefficient + poly2.terms[j].coefficient);
//                i++;
//                j++;
//            }
//
//            else if (terms[i].degree > poly2.terms[j].degree) 
//            {
//                result.addTerm(terms[i].degree, terms[i].coefficient);
//                i++;
//            }
//
//            else 
//            {
//                result.addTerm(poly2.terms[j].degree, poly2.terms[j].coefficient);
//                j++;
//            }
//        }
//
//        // Добавляем оставшиеся члены из первого многочлена
//        while (i < numTerms) {
//            result.addTerm(terms[i].degree, terms[i].coefficient);
//            i++;
//        }
//
//        // Добавляем оставшиеся члены из второго многочлена
//        while (j < poly2.numTerms) {
//            result.addTerm(poly2.terms[j].degree, poly2.terms[j].coefficient);
//            j++;
//        }
//
//        return result;
//    }
//
//    // Функция для вычитания двух разреженных многочленов
//    SparsePolynomial subtract(const SparsePolynomial& poly2) const 
//    {
//        SparsePolynomial result;
//
//        int i = 0, j = 0;
//        while (i < numTerms && j < poly2.numTerms) 
//        {
//            if (terms[i].degree == poly2.terms[j].degree) 
//            {
//                result.addTerm(terms[i].degree, terms[i].coefficient - poly2.terms[j].coefficient);
//                i++;
//                j++;
//            }
//
//            else if (terms[i].degree > poly2.terms[j].degree) 
//            {
//                result.addTerm(terms[i].degree, terms[i].coefficient);
//                i++;
//            }
//
//            else 
//            {
//                result.addTerm(poly2.terms[j].degree, -poly2.terms[j].coefficient);
//                j++;
//            }
//        }
//
//        // Добавляем оставшиеся члены из первого многочлена
//        while (i < numTerms) {
//            result.addTerm(terms[i].degree, terms[i].coefficient);
//            i++;
//        }
//
//        // Добавляем оставшиеся члены из второго многочлена с отрицательными коэффициентами
//        while (j < poly2.numTerms) {
//            result.addTerm(poly2.terms[j].degree, -poly2.terms[j].coefficient);
//            j++;
//        }
//
//        return result;
//    }
//
//    // Функция для умножения разреженного многочлена на константу
//    SparsePolynomial multiplyByConstant(int constant) const 
//    {
//        SparsePolynomial result;
//
//        for (int i = 0; i < numTerms; i++) {
//            result.addTerm(terms[i].degree, terms[i].coefficient * constant);
//        }
//
//        return result;
//    }
//
//    void print() const 
//    {
//        for (int i = 0; i < numTerms; i++) 
//        {
//            cout << terms[i].coefficient << "x^" << terms[i].degree;
//
//            if (i < numTerms - 1) {
//                cout << " + ";
//            }
//        }
//        cout << endl;
//    }
//};
//
//int main() 
//{
//    SparsePolynomial poly1;
//    poly1.addTerm(5, 3);
//    poly1.addTerm(3, 2);
//    poly1.addTerm(2, -4);
//    poly1.addTerm(0, 5);
//
//    SparsePolynomial poly2;
//    poly2.addTerm(5, 1);
//    poly2.addTerm(3, 3);
//    poly2.addTerm(1, 4);
//
//    cout << "Poly1: ";
//    poly1.print();
//
//    cout << "Poly2: ";
//    poly2.print();
//
//    SparsePolynomial sum = poly1.add(poly2);
//    cout << "Sum: ";
//    sum.print();
//
//    SparsePolynomial diff = poly1.subtract(poly2);
//    cout << "Difference: ";
//    diff.print();
//
//    int constant = 2;
//    SparsePolynomial product = poly1.multiplyByConstant(constant);
//    cout << "Product with constant " << constant << ": ";
//    product.print();
//
//    return 0;
//}


/// Алгоритм 10. Алгоритм вычисления стандартного скалярного произведения разреженных многочленов линейных операций для разреженных многочленов

/// Алгоритм 11. Рекурсивные алгоритмы обходов (КЛП, ЛКП, ЛПК) бинарного дерева

/// Алгоритм 12. Итеративный алгоритм КЛП – обхода бинарного дерева

/// Алгоритм 13. Итеративный алгоритм ЛКП – обхода бинарного дерева

/// Алгоритм 14. Итеративный алгоритм ЛПК – обхода бинарного дерева

/// Алгоритм 15. Итеративный алгоритм обхода в ширину бинарного дерева

/// Алгоритм 16. Алгоритм построения идеально сбалансированного бинарного дерева

/// Алгоритм 17. Алгоритм поиска узла БДП

/// Алгоритм 18. Алгоритм вставки узла в БДП

/// Алгоритм 19. Алгоритм удаления узла из БДП

/// Алгоритм 20. Алгоритм вращения узла для восстановления инварианта пирамиды

/// Алгоритм 21. Алгоритм малого вращения вправо и влево для восстановления инварианта АВЛ-дерева 

/// Алгоритм 22. Алгоритм большого вращения вправо и влево для восстановления инварианта АВЛ-дерева

/// Алгоритм 23. Алгоритм поиска подстроки перебором 

/// Алгоритм 24. Алгоритм поиска подстроки с использованием кода строки

/// Алгоритм 25. Алгоритм Рабина-Карпа поиска подстроки

/// Алгоритм 26. Сортировка выбором

/// Алгоритм 27. Сортировка обменами

/// Алгоритм 28. Сортировка перемешиванием

/// Алгоритм 29. Сортировка расческой

/// Алгоритм 30. Сортировка вставками

/// Алгоритм 31. Алгоритм разбиения последовательности (базовый вариант)

/// Алгоритм 32. Алгоритм разбиения последовательности (модификация Хоара)

/// Алгоритм 33. Алгоритм нахождения медианы

/// Алгоритм 34. Алгоритм слияния упорядоченных последовательностей

/// Алгоритм 35. Быстрая сортировка

/// Алгоритм 36. Сортировка слиянием

/// Алгоритм 37. Пирамидальная сортировка

/// Алгоритм 38. Сортировка подсчетом

/// Алгоритм 39. Блочная сортировка

/// Алгоритм 40. Поразрядная сортировка