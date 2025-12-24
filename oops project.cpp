#include <bits/stdc++.h>
using namespace std;

class Policy {
public:
    int id;
    string name;

    Policy(int i, string n) : id(i), name(n) {}
    virtual int premium() = 0;
    virtual void show() = 0;
    virtual ~Policy() {}
};

class Term : public Policy {
public:
    Term(int i, string n) : Policy(i, n) {}

    int premium() {
        return 105;
    }

    void show() {
        cout << "TERM Policy | ID: " << id
             << " | Name: " << name
             << " | Premium: 105\n";
    }
};

class AutoP : public Policy {
public:
    AutoP(int i, string n) : Policy(i, n) {}

    int premium() {
        return 180;
    }

    void show() {
        cout << "AUTO Policy | ID: " << id
             << " | Name: " << name
             << " | Premium: 180\n";
    }
};

int main() {
    vector<Policy*> p;
    int c;

    while (true) {
        cout << "\n1.Add 2.Show 3.Total 4.Exit : ";
        cin >> c;

        if (c == 1) {
            cout << "1.Term 3.Auto: ";
            int t, id;
            string n;
            cin >> t;

            cout << "ID: ";
            cin >> id;
            cout << "Name: ";
            cin >> n;

            if (t == 1) {
                p.push_back(new Term(id, n));
            }
            else if (t == 3) {
                p.push_back(new AutoP(id, n));
            }
            else {
                cout << "Invalid policy type\n";
            }
        }

        else if (c == 2) {
            if (p.empty()) {
                cout << "No policies available\n";
            }
            else {
                for (auto x:p) {
                    x->show();
                }
            }
        }

        else if (c == 3) {
            int total = 0;
            for (auto x : p) {
                total += x->premium();
            }
            cout << "Total Premium: " << total << endl;
        }

        else if (c == 4) {
            break;
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    // Free memory
    for (auto x : p) {
        delete x;
    }

    return 0;
}

