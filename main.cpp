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

// Linked List realization
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
    void sort()
    {
        Node *prev_node = nullptr;
        Node *current_node = head;
        Node *next_node = current_node->next;
        Node *new_head = head;
        Node *min_node = head;
        Node *before_min = prev_node;
        Node *after_min = next_node;
        Node *unsorted_starts_here = head;
        Node *sorted_ends_here = nullptr;

        while (true)
        {
            current_node = unsorted_starts_here;
            while (current_node != nullptr)
            {
                if (current_node->data <= min_node->data)
                {
                    before_min = prev_node;
                    min_node = current_node;
                    after_min = next_node;
                }

                prev_node = current_node;
                current_node = current_node->next;

                if (current_node != nullptr)
                    next_node = current_node->next;
            }

            if (min_node == unsorted_starts_here)
            {
                unsorted_starts_here = unsorted_starts_here->next;
            }

            min_node->next = new_head;
            if (sorted_ends_here == nullptr)
            {
                sorted_ends_here = min_node;
            }
            new_head = min_node;
            before_min->next = after_min;
            min_node = unsorted_starts_here;

            if (min_node == nullptr)
            {
                break;
            }

            next_node = unsorted_starts_here->next;
            prev_node = sorted_ends_here;
        }
        head = new_head;
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
    Stack first_stack;
    Stack second_stack;

public:
    void enqueue(int data)
    {
        first_stack.push(data);
    }

    int dequeue()
    {
        if (second_stack.is_empty())
        {
            while (!first_stack.is_empty())
            {
                second_stack.push(first_stack.pop());
            }
        }

        if (second_stack.is_empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        return second_stack.pop();
    }

    bool is_empty()
    {
        return first_stack.is_empty() && second_stack.is_empty();
    }

    int size()
    {
        return first_stack.size() + second_stack.size();
    }
};
// bonus
void deleteStack(Stack &stack)
{
    Node *current = stack.head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    stack.head = nullptr;
    stack.len = 0;
}

// CONVERT
bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }

    if (c == '*' || c == '/')
    {
        return 2;
    }

    return 0;
}

string infix_to_prefix(string infix)
{
    Stack operators;
    string result;

    reverse(infix.begin(), infix.end());

    for (char &elem : infix)
    {
        // Handle operands
        if (isdigit(elem))
        {
            result += elem;
        }

        else if (is_operator(elem))
        {
            while (!operators.is_empty() && precedence(operators.peek()) >= precedence(elem))
            {
                result += operators.pop();
            }
            operators.push(elem);
        }

        else if (elem == ')')
        {
            operators.push(elem);
        }
        else if (elem == '(')
        {
            while (!operators.is_empty() && operators.peek() != ')')
            {
                result += operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.is_empty())
    {
        result += operators.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int calc(string prefix)
{
    Stack operands;

    reverse(prefix.begin(), prefix.end());

    for (char &c : prefix)
    {
        if (isdigit(c))
        {
            operands.push(c - '0');
        }
        else if (is_operator(c))
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
    return operands.peek();
}

int main()
{
    // Linked List realization test
    LinkedList list;
    cout << "============>" << endl;
    cout << "LINKEDLIST REALIZATION" << endl;

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

    cout << "Sort List: ";
    list.sort();
    list.ListDisplay();

    // Stack realization test
    Stack stack;
    cout << endl
         << "============>" << endl;
    cout << "STACK REALIZATION" << endl;

    cout << "Size: " << stack.size() << endl;
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
    // bonus
    deleteStack(stack);

    cout << "After deletion - Size: " << stack.size() << endl;

    // Queue with 2 stacks test
    Queue queue;
    cout << endl
         << "============>" << endl;
    cout << "QUEUE WITH 2 STACKS REALIZATION" << endl;

    cout << "Queue size: " << queue.size() << endl;
    queue.enqueue(3);
    queue.enqueue(9);
    queue.enqueue(31);
    queue.enqueue(-9);
    queue.enqueue(5);
    queue.enqueue(16);
    cout << "Queue size: " << queue.size() << endl;

    cout << "Dequeuing elements: " << endl;
    while (!queue.is_empty())
    {
        cout << "Elem: " << queue.dequeue() << endl;
        cout << "Queue size: " << queue.size() << endl;
    }
    cout << endl;

    // CONVERT BLAT 3 uzdevums test
    string infix = "(1+3)*17-(12+4)";
    cout << "Infix: " << infix << endl;

    string prefix = infix_to_prefix(infix);
    cout << "Prefix: " << prefix << endl;

    int result = calc(prefix);
    cout << "Result: " << result << endl;
    return 0;
}