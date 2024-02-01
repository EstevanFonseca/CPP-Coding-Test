#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function declarations
bool isPrime(int number);
bool isPalindrome(int number);
int sumOfPrimesAndPalindromes(const vector<int>& arr);
vector<int> getDecreasingPrimes(int start, int end);
string invertString(const string& input);

int main() {
    int choice;
    do {
        // Display menu
        cout << "Choose an option:" << endl;
        cout << "1 - Determine whether a given number is prime." << endl;
        cout << "2 - Determine whether a given number is a palindrome." << endl;
        cout << "3 - Get the sum of values at prime or palindromic indices in an array." << endl;
        cout << "4 - Get a decreasing list of prime numbers in a range." << endl;
        cout << "5 - Invert a given string." << endl;
        cout << "0 - Exit." << endl;

        // User input
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "Enter a number: ";
                cin >> num;
                cout << num << " is " << (isPrime(num) ? "prime." : "not prime.") << endl << endl;
                break;
            }
            case 2: {
                int num;
                cout << "Enter a number: ";
                cin >> num;
                cout << num << " is " << (isPalindrome(num) ? "a palindrome." : "not a palindrome.") << endl << endl;
                break;
            }
            case 3: {
                int size;
                cout << "Enter the size of the array: ";
                cin >> size;
                vector<int> arr(size);
                cout << "Enter the elements of the array: ";
                for (int i = 0; i < size; ++i)
                    cin >> arr[i];
                cout << "Sum of values at prime or palindromic indices: " << sumOfPrimesAndPalindromes(arr) << endl << endl;
                break;
            }
            case 4: {
                int start, end;
                cout << "Enter the range (start end): ";
                cin >> start >> end;
                vector<int> primes = getDecreasingPrimes(start, end);
                cout << "Decreasing list of prime numbers in the range: ";
                for (int prime : primes)
                    cout << prime << " ";
                cout << endl << endl;
                break;
            }
            case 5: {
                string input;
                cout << "Enter a string: ";
                cin.ignore(); // To clear the newline character from the buffer
                getline(cin, input);
                string invertedString = invertString(input);
                cout << "Inverted string: " << invertedString << endl << endl;
                break;
            }
            case 0:
                cout << "Exiting program." << endl << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl << endl;
        }
    } while (choice != 0);

    return 0;
}

// Function definitions

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1)
        return false;
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0)
            return false;
    }
    return true;
}

// Function to check if a number is palindrome
bool isPalindrome(int number) {
    int original = number;
    int reversed = 0;
    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return original == reversed;
}

// Function to get the sum of values at prime or palindromic indices in an array
int sumOfPrimesAndPalindromes(const vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (isPrime(i) || isPalindrome(i))
            sum += arr[i];
    }
    return sum;
}

// Function to get a decreasing list of prime numbers in a range
vector<int> getDecreasingPrimes(int start, int end) {
    vector<int> primes;
    for (int i = end; i >= start; --i) {
        if (isPrime(i))
            primes.push_back(i);
    }
    return primes;
}

// Function to invert a given string
string invertString(const string& input) {
    string invertedString = input;
    int length = input.length();
    for (int i = 0; i < length / 2; ++i)
        swap(invertedString[i], invertedString[length - i - 1]);
    return invertedString;
}
