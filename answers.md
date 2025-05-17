# Answers for questions 

### LinkedList
1. **Linked List** is an abstract data structure that represents a sequence of elements, where each element contains a reference to the next element in the list.

2. #### Advantages and Disadvantages  
    #### Advantages of Linked List:
    - Easy to add and remove elements because there's no need to shift other elements like in arrays.
    - Memory is allocated for each element as needed, allowing flexible memory management.
    - Easy to expand by simply adding new elements.

   #### Disadvantages of Linked List:
    - Accessing elements by index is inefficient, as it requires sequential traversal.
    - Requires more memory due to storing references (pointers).
    - Cannot directly access an element like in an array — must traverse from the beginning.

3. #### Common Use Cases:
    - In data structures like stacks, queues, or lists where frequent insertion/removal is needed.
    - When working with large, dynamic datasets.
    - In operating systems for memory management.
    - In file systems for storing file and data metadata.
---

### Stack
4. **Stack** is an abstract data structure that follows the principle of "Last In, First Out" (LIFO). This means the last element added to the stack will be the first one removed.<br>
Core stack operations include:
    - **Push**: Add an element to the top of the stack.
    - **Pop**: Remove the top element from the stack.
    - **Peek/Top**: View the top element without removing it.
    - **IsEmpty**: Check if the stack is empty.
    - **IsFull**: Check if the stack is full (for stacks with a fixed size).

5. #### Advantages and Disadvantages  
    #### Advantages:
    - Easy to understand and implement add/remove operations.
    - Operations are fast (constant time), making stacks efficient.
    - Useful for LIFO scenarios like function call handling or undo operations.

   #### Disadvantages:
    - Limited access: only the top element is accessible.
    - Fixed size (in some implementations) may lead to overflow.
    - Difficult to search if the desired element isn't at the top.

6. #### Common Use Cases:
    - Managing function calls.
    - Solving arithmetic expressions.
    - Undo/redo functionality in applications.
    - Graph traversal.
    - Implementing recursive algorithms.
---

### Queue
7. **Queue** is an abstract data structure that works on the "First In, First Out" (FIFO) principle. This means elements are added to the end and removed from the front.
    #### Core queue operations include:

    - Enqueue (or Push): Add an element to the end of the queue.
    - Dequeue (or Pop): Remove the element from the front of the queue.
    - Peek (or Front): View the front element without removing it.
    - IsEmpty: Check if the queue is empty.
    - IsFull: Check if the queue is full (for fixed-size queues).

8.  #### Advantages and Disadvantages  

    #### Advantages:
    - Maintains order — elements stay in the order they were added.
    - Simple and intuitive to use.
    - Great for managing data in multithreaded apps and buffering.

    #### Disadvantages:
    - Fixed-size queues can overflow.
    - Not easy to access elements in the middle.
    - Only allows adding at the end and removing from the front, limiting use in some scenarios.

9. #### Common Use Cases:

    - Handling requests in web servers.
    - Order processing in e-commerce systems.
    - Message passing between system components.
    - Background task processing, such as database updates.
---

### Useful terminal commands:
- make  
- make build  
- make clean  
