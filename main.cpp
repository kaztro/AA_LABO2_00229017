#include <iostream>

using namespace std;

struct PairNode {
    int value;
    PairNode *next;
}*pair_start;

struct OddNode {
    int value;
    OddNode *next;
}*odd_start;

//Pila de pares
class PairStack {
    public:
        static PairNode* createNode(int value) {
            auto *n = new PairNode;
            n -> value = value;
            n -> next = nullptr;
            return n;
        }

        static void push(int value) {
            PairNode *n = createNode(value);
            n -> next = pair_start;
            pair_start = n;
        }

    static void showStack() {
            PairNode *temp = pair_start;
            if (!pair_start) cout << "The PairStack is empty" << endl;
            else
                while(temp) {
                    cout << temp -> value << ", ";
                    temp = temp -> next;
                }
        }

        static int size() {
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

//Pila de impares...
class OddStack {
public:
    static OddNode* createNode(int value) {
        auto *n = new OddNode;
        n -> value = value;
        n -> next = nullptr;
        return n;
    }

    static void push(int value) {
        OddNode *n;
        n = createNode(value);
        n -> next = odd_start;
        odd_start = n;
    }

    static void showStack() {
        OddNode *temp = odd_start;
        if (!odd_start) cout << "The PairStack is empty" << endl;
        else
            while(temp) {
                cout << temp -> value << ", ";
                temp = temp -> next;
            }
    }

    static int size() {
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

//Funcion que llena las pilasy hace la respectiva comparación
int fillS(int tamA, int aux, PairStack pStack, OddStack oStack) {
    if (aux < tamA) {
        int value = 0;
        cout << "Enter the " << aux + 1 << " value of " << tamA << endl;
        cin >> value;
        (value % 2 == 0) ? PairStack::push(value) : OddStack::push(value);
        fillS(tamA, aux + 1, pStack, oStack);
    } else {
        cout << "Pair stack (contains: " << PairStack::size() << " elements): " << endl;
        PairStack::showStack();
        cout << endl;
        cout << "Odd stack (contains: " << OddStack::size() << " elements): " << endl;
        OddStack::showStack();
        cout << endl;
        if (PairStack::size() == OddStack::size()) cout << "Both stacks are equals" << endl;
        else {
            (PairStack::size() > OddStack::size()) ? cout << "The pair stack is bigger" :
            cout << "The odd stack is bigger";
            cout << endl;
        }
    }
}

int main() {
    int length;
    PairStack pairS; //Pila pares
    OddStack oddS; //Pila impares

    cout << "How many numbers are you gonna enter?" << endl;
    cin >> length;

    fillS(length, 0, pairS, oddS);

    return 0;
}