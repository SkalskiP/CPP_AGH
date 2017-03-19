#include "CCounter.h"

using namespace std;
using namespace ccounter;

int main() {
    unique_ptr<Counter> MyCounter = Init();
    Inc("a", &MyCounter);
    Inc("a", &MyCounter);
    Inc("b", &MyCounter);

    cout << Counts(MyCounter, "a") << endl;
    cout << Counts(MyCounter, "b") << endl;
    cout << Counts(MyCounter, "c") << endl;

    SetCountsTo("d", 5, &MyCounter);
    cout << Counts(MyCounter, "d") << endl;

    return 0;
}