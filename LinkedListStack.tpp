// Compilation: g++ homework.cpp -o hw

template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while (top != nullptr) {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }

    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    if (copyObj.top == nullptr) {
        top = nullptr;
        this->length = 0;
        return;
    }

    Node<T>* copyCurr = copyObj.top;
    Node<T>* newNode = new Node<T>(copyCurr->data);
    top = newNode;

    Node<T>* thisCurr = top;
    copyCurr = copyCurr->next;

    while (copyCurr != nullptr) {
        thisCurr->next = new Node<T>(copyCurr->data);
        thisCurr = thisCurr->next;
        copyCurr = copyCurr->next;
    }

    this->length = copyObj.length;
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if (isEmpty()) {
        throw string("peek: error, stack is empty, cannot access the top");
    }

    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) {
        throw string("pop: error, stack is empty, avoiding underflow");
    }

    Node<T>* temp = top;
    top = top->next;
    delete temp;

    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;

    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty()) {
        throw string("rotate: error, stack is empty, unable to rotate");
    }

    if (this->length == 1) {
        return;
    }

    if (dir == Stack<T>::RIGHT) {
        Node<T>* oldTop = top;
        top = top->next;
        oldTop->next = nullptr;

        Node<T>* curr = top;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = oldTop;
    }
    else if (dir == Stack<T>::LEFT) {
        Node<T>* curr = top;

        while (curr->next->next != nullptr) {
            curr = curr->next;
        }

        Node<T>* lastNode = curr->next;
        curr->next = nullptr;

        lastNode->next = top;
        top = lastNode;
    }
    else {
        throw string("rotate: error, unknown direction");
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
