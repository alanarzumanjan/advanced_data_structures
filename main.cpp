#include <iostream>
#include <vector>
#include <algorithm>
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

class Queue : public Stack
{
private:
    Stack inbox;
    Stack outbox;

public:
    void enqueue(int data)
    {
        inbox.push(data);
    }

    int dequeue()
    {
        if (outbox.is_empty())
        {
            while (!inbox.is_empty())
            {
                outbox.push(inbox.pop());
            }
        }

        if (outbox.is_empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return outbox.pop();
    }

    bool is_empty()
    {
        return inbox.is_empty() && outbox.is_empty();
    }

    int size()
    {
        return inbox.size() + outbox.size();
    }
};
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

string infixToPrefix(string infix)
{
    Stack operators;
    string result;

    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    for (char &c : infix)
    {
        // Handle operands
        if (isdigit(c))
        {
            result += c;
        }
        // Handle operators
        else if (isOperator(c))
        {
            while (!operators.is_empty() && precedence(operators.peek()) >= precedence(c))
            {
                result += operators.pop();
            }
            operators.push(c);
        }
        // Handle parentheses
        else if (c == ')')
        {
            operators.push(c);
        }
        else if (c == '(')
        {
            while (!operators.is_empty() && operators.peek() != ')')
            {
                result += operators.pop();
            }
            operators.pop(); // Discard the opening parenthesis
        }
    }

    // Pop remaining operators from the stack
    while (!operators.is_empty())
    {
        result += operators.pop();
    }

    // Reverse the result string to get the final prefix expression
    reverse(result.begin(), result.end());

    return result;
}

int evaluatePrefix(string prefix)
{
    Stack operands;

    // Reverse the prefix expression to start from left
    reverse(prefix.begin(), prefix.end());

    for (char &c : prefix)
    {
        if (isdigit(c))
        {
            operands.push(c - '0'); // Convert char to int
            
        }
        else if (isOperator(c))
        {
            int operand1 = operands.pop();
            int operand2 = operands.pop();
            switch (c)
            {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                operands.push(operand1 / operand2);
                break;
            }
        }
    }

    // The result will be at the top of the stack
    return operands.peek();
}

int main()
{
    // Linked List realization
    cout << "============>" << endl;
    cout << "LINKEDLIST REALIZATION" << endl;
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
    cout << "============>" << endl;
    cout << "STACK REALIZATION" << endl;
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


    // Queue with 2 stacks
    Queue queue;
    cout << "============>" << endl;
    cout << "QUEUE WITH 2 STACKS REALIZATION" << endl;

    cout << "Queue size: " << queue.size() << endl;
    queue.enqueue(3);
    queue.enqueue(9);
    queue.enqueue(31);
    queue.enqueue(-9);
    queue.enqueue(5);
    queue.enqueue(16);
    cout << "Queue size: " << queue.size() << endl;

    // Проверка операции dequeue
    cout << "Dequeuing elements: ";
    while (!queue.is_empty())
    {
        cout << "Elem: "<< queue.dequeue() << endl;
        cout << "Queue size: " << queue.size() << endl;
    }
    cout << endl;

    // CONVERT BLAT 3 uzdevums
    string infixExpression = "(1+3)*17-(12+4)";
    cout << "Infix Expression: " << infixExpression << endl;

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix Expression: " << prefixExpression << endl;

    int result = evaluatePrefix(prefixExpression);
    cout << "Result: " << result << endl;
    return 0;
}