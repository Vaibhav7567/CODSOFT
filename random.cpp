#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    cout << "Enter the range (two numbers) for generating a random number: " << endl;
    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << "Invalid range: n should be less than or equal to m." << endl;
        return 1;
    }

    int random = (rand() % (m - n + 1)) + n;

    cout << "Guess the number between " << n << " and " << m << ": ";
    int guess;
    cin >> guess;

    int range = m - n;
    int closeEnoughMark;

    if (range <= 100) {
        closeEnoughMark = 10;
    } else if (range <= 1000) {
        closeEnoughMark = 50;
    } else {
        closeEnoughMark = 100;
    }

    if (guess == random) {
        cout << "Congratulations! You guessed the correct number: " << random << endl;
    } else {
        int difference = guess - random;
        if (abs(difference) <= closeEnoughMark) {
            if (difference < 0) {
                cout << "Close enough, but low! The random number was: " << random << endl;
            } else {
                cout << "Close enough, but high! The random number was: " << random << endl;
            }
        } else {
            if (guess < random) {
                cout << "Too low! The random number was: " << random << endl;
            } else {
                cout << "Too high! The random number was: " << random << endl;
            }
        }
    }

    return 0;
}
