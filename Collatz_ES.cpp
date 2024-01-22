/******************************************************************************
The Collatz conjecture: chain, length, max_value
compile on https://cpp.sh/
*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct Collatz {
    vector<int> chain;
    int length;
    int max_value;
};

Collatz collatz_calculate(int n) {
    Collatz c;
    c.chain.push_back(n);
    c.length = 1; 
    c.max_value = n;

    while (n > 1) {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        c.chain.push_back(n);
        c.length++; // Increment length after each loop iteration
        c.max_value = max(n, c.max_value);
    }

  return c;
}

int main() {
    const int n = 13;
    Collatz d = collatz_calculate(n);
    cout << "Length: " << d.length << " | Max value: " << d.max_value << endl;
  
    cout << "Collatz chain: ";
    cout <<  d.chain[0];
    for (int i = 1; i < d.chain.size(); ++i)
        cout << "->" << d.chain[i];
    cout << endl;
  
    return 0;
}
