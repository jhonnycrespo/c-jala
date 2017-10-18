The memory a program uses is typically divided into a few different areas, called segments:

    - The code segment (also called a text segment), where the compiled program sits in memory. The code segment is typically read-only.

    - The bss segment (also called the uninitialized data segment), where zero-initialized global and static variables are stored.

    - The data segment (also called the initialized data segment), where initialized global and static variables are stored.

    - The heap, where dynamically allocated variables are allocated from.

    - The call stack, where function parameters, local variables, and other function-related information are stored.


The Heap
========

The heap has advantages and disadvantages:

    - Allocating memory on the heap is comparatively slow.
    - Allocated memory stays allocated until it is specifically deallocated (beware memory leaks) or the application ends (at which point the OS should clean it up).
    - Dynamically allocated memory must be accessed through a pointer. Dereferencing a pointer is slower than accessing a variable directly.
    - Because the heap is a big pool of memory, large arrays, structures, or classes can be allocated here.

The Call Stack
==============

The call stack (usually referred to as “the stack”) has a much more interesting role to play. The call stack keeps track of all the active functions (those that have been called but have not yet terminated) from the start of the program to the current point of execution, and handles allocation of all function parameters and local variables.

The call stack is implemented as a stack data structure.


Heap and Stack
==============

The difference is lifespan, any local variable inside a function (anything you do not malloc() or new) lives on the stack. It goes away when you return from the function. If you want something to live longer than the function that declared it, you must allocate it on the heap.

* Where are the stack and heap stored?
- They are both stored in the computer’s RAM

* How long does memory on the stack last versus memory on the heap?
- Once a function call runs to completion, any data on the stack created specifically for that function call will automatically be deleted. Any data on the heap will remain there until it’s manually deleted by the programmer.

* Can the stack grow in size? Can the heap grow in size?
- The stack is set to a fixed size, and can not grow past it’s fixed size (although some languages have extensions that do allow this). So, if there is not enough room on the stack to handle the memory being assigned to it, a stack overflow occurs. This often happens when a lot of nested functions are being called, or if there is an infinite recursive call.

If the current size of the heap is too small to accommodate new memory, then more memory can be added to the heap by the operating system. This is one of the big differences between the heap and the stack.

* How is memory deallocated on the stack and heap?
- Data on the stack is automatically deallocated when variables go out of scope. However, in languages like C and C++, data stored on the heap has to be deleted manually by the programmer using one of the built in keywords like free, delete, or delete[ ]. Other languages like Java and .NET use garbage collection to automatically delete memory from the heap, without the programmer having to do anything..
