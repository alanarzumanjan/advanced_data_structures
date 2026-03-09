# Advanced data structures & algorithms

A C++ project implementing fundamental data structures and algorithms:

- Linked List  
- Stack  
- Queue (via two stacks)  
- Infix to Prefix conversion and evaluation  

Includes hands-on demonstrations and terminal commands for compiling and testing.

---

## Features

- **Linked List** with append, display, reverse, and custom sort
- **Stack** with push, pop, peek, and size
- **Queue** implemented using two stacks
- **Expression Converter**: from infix to prefix with evaluation
- **Bonus**: memory cleanup and manual stack deletion

---

## How to Run

### Compile
```bash
make
```
Clean build files
```
make clean
```

Project Structure

├── main.cpp         # All implementations and test cases<br>
├── Makefile         # Build automation<br>
├── README.md        # Project overview<br>
├── answers.md       # Theoretical explanations <br>

### Visual Overview (Mermaid)

```mermaid
classDiagram
    class Main

    class LinkedList {
        +append()
        +ListDisplay()
        +ReverseList()
        +sort()
    }

    class Stack {
        +push()
        +pop()
        +peek()
        +is_empty()
        +size()
    }

    class QueueWithTwoStacks {
        +enqueue()
        +dequeue()
        +is_empty()
        +size()
    }

    class Convert {
        +infix_to_prefix()
        +calc()
    }

    LinkedList --> Main
    Stack --> Main
    QueueWithTwoStacks --> Main
    Convert --> Main
```
