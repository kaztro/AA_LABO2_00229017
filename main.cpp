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

        int size() {
            int size = 0;
            Node *temp = start;
            if (!start) cout << "The Stack is empty" << endl;
            else
                while(temp) {
                    size++;
                    temp = temp -> next;
                }
                return size;
        }

        Stack() {
            start = nullptr;
        }
};

void operateS(int *array, int tamA, int aux, Stack pair, Stack odd) {
    if (aux < tamA) {
        if(array[aux]%2 == 0) {
            pair.push(array[aux]);
        } else {
            odd.push(array[aux]);
        }
        operateS(array, tamA, aux + 1, pair, odd);
    } else {
        cout << "Pair stack (contains:" << pair.size() << "): " << endl;
        pair.showStack();
        cout << endl;
        cout << "Odd stack (contains:" << odd.size() << "): " << endl;
        odd.showStack();
        cout << endl;
        if (pair.size() == odd.size()) cout << "Both stacks are equals" << endl;
        else {
            if(pair.size() > odd.size()) cout << "The pair stack is bigger" << endl;
            else cout << "The odd stack is bigger" << endl;
        }
    }
}

int fillA(int *array, int tamA, int aux, Stack pair, Stack odd) {
    if (aux < tamA) {
        cout << "Enter the " << aux + 1 << " value of " << tamA << endl;
        cin >> array[aux];
        fillA(array, tamA, aux + 1);
    } else operateS(array, tamA, 0, pair, odd);
}

int main() {
    int length;

    Stack pair, odd;

    cout << "How many numbers are you gonna enter?" << endl;
    cin >> length;

    int values[length];

    fillA(values, length, 0, pair, odd);

/*
    do {
        cout << "Enter an integer, enter any letter or symbol to finish: " << endl;
        ok = scanf("%d",  &value);
        (value%2 == 0) ? pair.push(value) : odd.push(value);
    }
    while(!isdigit(ok));

    while(flag) {
        cout << "Enter an integer, enter any letter or symbol to finish: " << endl;
        scanf("%d",  &value);
        if(flag) {
            if(value%2 == 0) pair.push(value);
            else odd.push(value);
        } else {
            break;
        }
    }
*/
    return 0;
}