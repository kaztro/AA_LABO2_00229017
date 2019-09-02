#include <iostream>

using namespace std;

struct PairNode {
    int value;
    PairNode *next;
}*pair_start;

class PairStack {
    public:
        PairNode* createNode(int value) {
            PairNode *n = new PairNode;
            n -> value = value;
            n -> next = nullptr;
            return n;
        }

        void push(int value) {
            PairNode *n = createNode(value);
            n -> next = pair_start;
            pair_start = n;
        }

        void pop() {
            PairNode *temp = pair_start;
            pair_start = pair_start -> next;
            free(temp);
        }

        void showStack() {
            PairNode *temp = pair_start;
            if (!pair_start) cout << "The PairStack is empty" << endl;
            else
                while(temp) {
                    cout << temp -> value << ", ";
                    temp = temp -> next;
                }
        }

        int size() {
            int sizeS = 0;
            PairNode *temp = pair_start;
            if (!pair_start) return 0;
            else {
                while (temp) {
                    sizeS++;
                    temp = temp -> next;
                }
            } return sizeS;
        }

        PairStack() {
            pair_start = nullptr;
        }
};

struct OddNode {
    int value;
    OddNode *next;
}*odd_start;

class OddStack {
public:
    OddNode* createNode(int value) {
        OddNode *n = new OddNode;
        n -> value = value;
        n -> next = nullptr;
        return n;
    }

    void push(int value) {
        OddNode *n = createNode(value);
        n -> next = odd_start;
        odd_start = n;
    }

    void pop() {
        OddNode *temp = odd_start;
        odd_start = odd_start -> next;
        free(temp);
    }

    void showStack() {
        OddNode *temp = odd_start;
        if (!odd_start) cout << "The PairStack is empty" << endl;
        else
            while(temp) {
                cout << temp -> value << ", ";
                temp = temp -> next;
            }
    }

    int size() {
        int sizeS = 0;
        OddNode *temp = odd_start;
        if (!pair_start) return 0;
        else {
            while (temp) {
                sizeS++;
                temp = temp -> next;
            }
        } return sizeS;
    }

    OddStack() {
        odd_start = nullptr;
    }
};

int fillS(int tamA, int aux, PairStack pStack, OddStack oStack) {
    if (aux < tamA) {
        int value = 0;
        cout << "Enter the " << aux + 1 << " value of " << tamA << endl;
        cin >> value;
        (value % 2 == 0) ? pStack.push(value) : oStack.push(value);
        fillS(tamA, aux + 1, pStack, oStack);
    } else {
        cout << "Pair stack (contains: " << pStack.size() << " elements): " << endl;
        pStack.showStack();
        cout << endl;
        cout << "Odd stack (contains: " << oStack.size() << " elements): " << endl;
        oStack.showStack();
        cout << endl;
        if (pStack.size() == oStack.size()) cout << "Both stacks are equals" << endl;
        else {
            (pStack.size() > oStack.size()) ? cout << "The pair stack is bigger" :
            cout << "The odd stack is bigger";
            cout << endl;
        }
    }
}

int main() {
    int length;
    PairStack pairS;
    OddStack oddS;

    cout << "How many numbers are you gonna enter?" << endl;
    cin >> length;

    fillS(length, 0, pairS, oddS);

    return 0;
}