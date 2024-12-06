// zad_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* list = nullptr;
public:
    void push_front(int data)
    {
        Node* current = new Node(data);
        current->next = head;

        if (head != nullptr)
            head->prev = current;
        if (tail == nullptr)
            tail = current;

        head = current;
        std::cout << "Элемент " << data << " добавлен в начало списка" << std::endl;
    }
    void display() {
        if (head != nullptr)
        {
            Node* temp = head;
            std::cout << "Список: ";
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Список пустой" << std::endl;
        }
    }
    void push_back(int data)
    {
        Node* current = new Node(data);
        current->prev = tail;

        if (tail != nullptr)
            tail->next = current;
        if (head == nullptr)
            head = current;

        tail = current;
        std::cout << "Элемент " << data << " добавлен в конец списка" << std::endl;
    }
    void pop_front()
    {
        if (head != nullptr)
        {
            Node* current = head->next;

            if (current != nullptr)
                current->prev = nullptr;
            else
                tail = nullptr;

            delete head;
            head = current;
            std::cout << "Элемента с начала списка удален" << std::endl;
        }
        else
        { 
            std::cout << "Список пустой" << std::endl;
        }
    }
    void pop_back()
    {
        if (tail != nullptr)
        {
            Node* current = tail->prev;

            if (current != nullptr)
                current->next = nullptr;
            else
                head = nullptr;

            delete tail;
            tail = current;
            std::cout << "Элемента с конца списка удален" << std::endl;
        }
        else
            std::cout << "Список пустой" << std::endl;
    };
};
int main()
{
    DoublyLinkedList list;
   setlocale(LC_ALL, "Russian");
   //1
   list.push_front(10);
   list.push_front(20);
   list.push_front(30);
   //2
   list.push_back(60);
   list.push_back(70);
   list.push_back(44);
   list.display();
   //3
   list.pop_front();
   list.display();
   //4
   list.pop_back();
   list.display();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
