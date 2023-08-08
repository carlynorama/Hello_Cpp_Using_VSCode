
#include "PrimeLib.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << random_prime() << " ";
    } else {
        for (int i = 1; i <= argc - 1; i++) {
            //in a real program would want to handle error
            const long num = std::stoi(argv[i]);
            cout << prime_at(num) << " ";
        }
    }

    cout << endl;
    return 0;
}

