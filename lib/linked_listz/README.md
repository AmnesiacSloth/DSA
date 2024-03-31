# CPP Templates and my LL Implementation 

--- 


## Templates

Should be thought of like macros, since they are expanded at **COMPILE TIME**. This means that template definition and
declaration must both be available to the compiler right away?? 

From a yt comment at [Templates in C++](https://www.youtube.com/watch?v=I-hZkUa9mIs&t=942s)
> With templates, you must either write AND use them inside a SINGLE source (cpp) file, OR you must write them ENTIRELY
> inside a header file. Unlike a regular function or class, you can NOT declare them inside a header file and then 
> define them inside a source file. The linker won't be able to link the templates if you do.


In my .h file, I declare the class with the template identifies right before the class definitions as is required.
Then, in my .tpp file (which is not actually a file type that is in cpp reference, could be .duck .sloth etc). Basically
I include this file at the bottom of my header file so that both the definitions and declarations "exist" in the same
file. The only reason that I can think of (as of right now) is that this .h / .tpp file breakup is for the developers
ease of use. Still resembles the .h / .cpp structure without breaking the rules of the language :)

## Pointer Style 
```c
int* p VS int *p
```

A "typical **C** programmer" writes "int *p;" and explains it "*p is what is the int" emphasizing syntax, 
and may point to the C (and C++) declaration grammar to argue for the correctness of the style. Indeed, 
the * binds to the name p in the grammar.


A "typical **C++** programmer" writes "int* p;" and explains it "p is a pointer to an int" emphasizing type. 
Indeed the type of p is int*. I clearly prefer that emphasis and see it as important for using the more advanced
parts of C++ well.


## Pass-By-Value Vs Pass-By-Reference

#### Pass By Value 

---

- Small or primitive types (like int, float, char, etc.), makes pass by value usually more efficient or equally 
efficient as passing by reference
- If function needs to modify the input without actually affecting the original arg, pass by value makes this easy
since it automatically gives you a copy to work with. 
- Guarantees immutability : Meaning it can signal to the user that the function does not modify the input data which 
makes it easy to understand the code and reason about it in large complex codebases

#### Pass By Reference

---

- Use when you need to pass in large or complex types. Pass by reference avoids the overhead of copying the entire 
object. Especially important when dealing with container or other types that manage resources like dynamic memory 
`std::vector, std::string, asVector :)))`
- Use when you need to modify the original data in the function. If the purpose is to modify the input arg, passing by
a **non-const** reference allows you to make changes that will be reflected in the original object. Common in functions 
that need to and intend to modify their inputs directly
- Also very useful and IMPORTANT when you want to read a large object **WITHOUT** modifying it. Passing by a const 
reference `const T&` is usually the best way to go. Avoids the copy overhead while simultaneously preventing 
modification to the original object, best of both worlds!


> - Considerations 
> - Move Semantics: C++11 introduced move semantics, which can make passing by value more efficient for types that 
> support moving. When an object is moved, its resources are transferred without copying the actual data, which can 
> mitigate the cost of passing by value. This is particularly relevant when the argument is a temporary object or 
> when using std::move with movable types. Universal References and Perfect Forwarding: Template functions or functions
> taking universal references (e.g., T&& with std::forward<T>) can optimize for both passing by value and reference, 
> depending on the context. This advanced feature allows functions to perfectly forward arguments to other functions, 
> minimizing unnecessary copies.

## STD Exceptions

- `std::exception` is a class that serves as the base class for all standard exception types.
- Provides a virtual function `what()` that returns a C-style string describing the error. Can be overwritten in 
derived classes to provide more specific error messages
- Usually you don't throw a `std::exception` itself, but instead you use one of its derived classes

### Derived Classes from `std::exception`
- The two most prevalent are logic_error and runtime_error

### `std::logic_error`
> Represents errors that could be detected before a program runs. They are the result of flaws in program logic
---
##### `std::invalid_argument`
- Thrown when an invalid argument is passed.
##### `std::domain_error`
- Used when a mathematical function receives an argument outside its domain.
##### `std::length_error`
- Indicates an attempt to create an object larger than a maximum size.

##### `std::out_of_range`
- For arguments that are outside the valid range.

### `std::runtime_error`
> Represents errors that can only be detected during runtime.
---
##### `std::range_error`
- Used when a result of a computation cannot be represented by the destination type.
##### `std::overflow_error`
- Indicates arithmetic overflow.
##### `std::underflow_error`
- Indicates arithmetic underflow.
##### `std::system_error`
- Used to report errors from the operating system or other low-level operations.

### Other Derived Classe 
> Exception classes derived from `std::exception` that don't fit neatly into logic or runtime error categories
- `std::bad_alloc`
- `std::bad_cast`
- `std::bad_typeid`
- `std::bad_exception`
- `std::bad_function_call`
- `std::bad_weak_ptr`

Note: These exceptions handle errors that are fundamentally different from the more common runtime and logic errors,
often dealing with lower-level operations such as memory allocation, type identification, and function invocation. 