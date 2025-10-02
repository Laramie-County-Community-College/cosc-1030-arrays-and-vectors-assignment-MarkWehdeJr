#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime> // for time()

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Vector to hold the coin flip results
    vector<string> coinFlips;
    string coinFlipResult = "";

    // Flip a coin 500 times
    for (int i = 0; i < 500; ++i) {
        int thisRandomNumber = rand();
        if ((thisRandomNumber % 2) == 0) {
            coinFlipResult = "Heads";
        } else {
            coinFlipResult = "Tails";
        }
        coinFlips.push_back(coinFlipResult);
    }

    // Count the number of heads
    // const prevents the loop from modifying any of the "flips"
    // auto tells the compiler to "figure out" which type of element it is using
    // & prevents the loop from making temporary copies in the memory
    int headsCount = 0;
    for (const auto& flip : coinFlips) {  
        if (flip == "Heads") {
            ++headsCount;
        }
    }

    // Output results
    cout << "Number of Heads: " << headsCount << '\n';
    cout << "Number of Tails: " << coinFlips.size() - headsCount << '\n';

    return 0;
}
