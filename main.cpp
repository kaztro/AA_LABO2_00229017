#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
}*start;

class Stack {
    public:
        Node* createNode(int value) {
            Node *n = new Node;
            n -> value = value;
            n -> next = nullptr;
            return n;
        }

        void push(int value) {
            Node *n = createNode(value);
            n -> next = start;
            start = n;
        }

        void pop() {
            Node *temp = start;
            start = start -> next;
            free(temp);
        }

        void showStack() {
            Node *temp = start;
            if (!start) cout << "The Stack is empty" << endl;
            else
                while(temp) {
                    cout << temp -> value << ", ";
                    temp = temp -> next;
                }
        }

        //Discrima los pares y retorna un arreglo con los mismos...
        Stack getPairs(int sizeS) {
            Stack stack;
            if(sizeS == 0) return stack;
            Node *temp = start;
            if (!start) cout << "The Stack is empty" << endl;
            else {
                while (temp) {
                    if (temp->value % 2 == 0) stack.push(temp -> value);
                    temp = temp -> next;
                }
            }
            return stack;
        }

    //Discrima los impares y retorna un arreglo con los mismos...
    Stack getOdds(int sizeS) {
        Stack stack;
        if(sizeS == 0) return stack;
        Node *temp = start;
        if (!start) cout << "The Stack is empty" << endl;
        else {
            while (temp) {
                if (temp -> value % 2 != 0) stack.push(temp -> value);
                temp = temp -> next;
            }
        }
        return stack;
    }

        int size() {
            int sizeS = 0;
            Node *temp = start;
            if (!start) return 0;
            else {
                while (temp) {
                    sizeS++;
                    temp = temp -> next;
                }
            } return sizeS;
        }

        Stack() {
            start = nullptr;
        }
};

int fillS(int tamA, int aux, Stack stack) {
    if (aux < tamA) {
        int value = 0;
        cout << "Enter the " << aux + 1 << " value of " << tamA << endl;
        cin >> value;
        stack.push(value);
        fillS(tamA, aux + 1, stack);
    } else {
        Stack pair = stack.getPairs(tamA);
        Stack odd = stack.getOdds(tamA);

        cout << "Pair stack (contains: " << pair.size() << " elements): " << endl;
        pair.showStack();
        cout << endl;
        cout << "Odd stack (contains: " << odd.size() << " elements): " << endl;
        odd.showStack();
        cout << endl;
        if (pair.size() == odd.size()) cout << "Both stacks are equals" << endl;
        else {
            (pair.size() > odd.size()) ? cout << "The pair stack is bigger" :
            cout << "The odd stack is bigger";
            cout << endl;
        }
    }
}

int main() {
    int length;
    Stack principal;

    cout << "How many numbers are you gonna enter?" << endl;
    cin >> length;

    fillS(length, 0, principal);

    return 0;
}