#include <iostream>
#include <string>
#include "StackFactory.hpp"

using namespace std;

template <typename T>
void testStack(Stack<T>* stack, const string& stackName, const T& val1, const T& val2, const T& val3) {
    cout << "\n----------------------------" << endl;
    cout << "Testing " << stackName << endl;
    cout << "----------------------------" << endl;

    cout << "Is stack empty? " << (stack->isEmpty() ? "Yes" : "No") << endl;
    cout << "Length: " << stack->getLength() << endl;

    cout << "\nPushing elements..." << endl;
    stack->push(val1);
    stack->push(val2);
    stack->push(val3);

    stack->print();
    cout << "\nTop element: " << stack->peek() << endl;
    cout << "\nLength after pushes: " << stack->getLength() << endl;

    cout << "\nRotate RIGHT (top goes to bottom):" << endl;
    stack->rotate(Stack<T>::RIGHT);
    stack->print();

    cout << "\nRotate LEFT (bottom goes to top):" << endl;
    stack->rotate(Stack<T>::LEFT);
    stack->print();

    cout << "\nPopping one element..." << endl;
    stack->pop();
    stack->print();
    cout << "\nLength after pop: " << stack->getLength() << endl;

    cout << "\nPeeking again..." << endl;
    cout << "Top element: " << stack->peek() << endl;

    cout << "\nClearing stack by popping everything..." << endl;
    while (!stack->isEmpty()) {
        cout << "Popping: " << stack->peek() << endl;
        stack->pop();
    }

    cout << "Is stack empty now? " << (stack->isEmpty() ? "Yes" : "No") << endl;
    cout << "Length now: " << stack->getLength() << endl;

    cout << "\nTesting exception cases..." << endl;
    try {
        stack->pop();
    }
    catch (string error) {
        cout << error << endl;
    }

    try {
        stack->peek();
    }
    catch (string error) {
        cout << error << endl;
    }

    try {
        stack->rotate(Stack<T>::RIGHT);
    }
    catch (string error) {
        cout << error << endl;
    }

    delete stack;
}

int main() {
    try {
        Stack<int>* linkedIntStack = StackFactory<int>::GetStack();
        testStack(linkedIntStack, "LinkedListStack<int>", 10, 20, 30);

        Stack<int>* arrayIntStack = StackFactory<int>::GetStack(5);
        testStack(arrayIntStack, "ArrayStack<int>", 10, 20, 30);

        Stack<string>* linkedStringStack = StackFactory<string>::GetStack();
        testStack(linkedStringStack, "LinkedListStack<string>", string("CS"), string("Math"), string("Stats"));

        Stack<string>* arrayStringStack = StackFactory<string>::GetStack(5);
        testStack(arrayStringStack, "ArrayStack<string>", string("CS"), string("Math"), string("Stats"));
    }
    catch (string error) {
        cout << "Unhandled exception: " << error << endl;
    }

    return 0;
}