#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    int len = 0;

    LinkedList()
    {
        this->head = nullptr;
    }

    void append(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void ListDisplay()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    // Reverse realization
    void ReverseList()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};
// Stack realization
class Stack : public LinkedList
{
public:
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            len++;
            return;
        }
        newNode->next = head;
        head = newNode;
        len++;
    }

    int pop()
    {
        int ret_val = head->data;

        head = head->next;
        len--;
        return ret_val;
    }

    int peek()
    {
        int ret_val = head->data;
        return ret_val;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    int size()
    {
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main()
{ 
    // Linked List realization
    LinkedList list;
    list.append(1);
    list.append(4);
    list.append(0);
    list.append(-30);
    list.append(2);
    list.append(14);
    list.append(5);
    list.append(-12);

    cout << "List: ";
    list.ListDisplay();

    cout << "Reverse List: ";
    list.ReverseList();
    list.ListDisplay();

    // Stack realization
    Stack stack;
    cout << "Not push - Size: " << stack.size() << endl;
    stack.push(1);
    stack.push(4);
    stack.push(0);
    stack.push(-30);
    stack.push(2);
    stack.push(14);
    stack.push(5);
    stack.push(-12);

    cout << "Push - Size: " << stack.size() << endl;

    printf("top: %d\n", stack.peek());
    printf("pop: %d\n", stack.pop());
    printf("pop: %d\n", stack.pop());

    printf("top: %d\n", stack.peek());
    printf("top: %d\n", stack.peek());
    printf("top: %d\n", stack.peek());
    printf("top: %d\n", stack.peek());

    printf("pop: %d\n", stack.pop());
    printf("pop: %d\n", stack.pop());
    printf("pop: %d\n", stack.pop());

    if (stack.is_empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "Before all - Size: " << stack.size() << endl;

    cout << "After deletion - Size: " << stack.size() << endl;
    if (stack.is_empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    return 0;
}