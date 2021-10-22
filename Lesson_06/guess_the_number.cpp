#include <iostream>
#include <ctime>

using namespace std;

void print_header()
{
    cout << "╔═══════════════════════╗" << endl;
    cout << "║ Guess The Number Game ║" << endl;
    cout << "╚═══════════════════════╝" << endl;
}

int random_value()
{
    const int max_value = 100;
    srand(time(nullptr)); // use current time as seed for random generator
    return rand() % max_value;
}

string ask_for_name()
{
    cout << "Hi! Enter your name, please:" << endl;
    string user_name;
    cin >> user_name;
    return user_name;
}

int main()
{
    const int target_value = random_value();
    int current_value = 0;
    unsigned int attempts = 0;

    print_header();
    string user_name = ask_for_name();

    cout << "Enter your guess:" << endl;
    do {
        cin >> current_value;
        attempts++;
        if (current_value < target_value) {
            cout << "You entered " << current_value << ". It is less than guessed number, please try again" << endl;
        }
        else if (current_value > target_value) {
            cout << "You entered " << current_value << ". It is greater than guessed number, please try again" << endl;
        }
        else {
            cout << "Congratulation! You guessed correct number!" << endl;
            break;
        }
    } while(true);
    cout << "Attempts taken: " << attempts << endl;
    return 0;
}
