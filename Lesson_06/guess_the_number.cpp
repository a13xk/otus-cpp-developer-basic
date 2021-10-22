#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
/**
 * Print game header
 */
void print_header()
{
    cout << "╔═══════════════════════╗" << endl;
    cout << "║ Guess The Number Game ║" << endl;
    cout << "╚═══════════════════════╝" << endl;
}
/**
 * Return random value between 0 and max_value
 * @param max_value Upper limit for random number generation
 * @return
 */
int random_value(const int max_value)
{
    srand(time(nullptr)); // use current time as seed for random generator
    return rand() % max_value;
}
/**
 * Ask player to enter his/her name
 */
string ask_for_name()
{
    cout << "Hi! Enter your name, please:" << endl;
    string user_name;
    cin >> user_name;
    return user_name;
}
/**
 * Write user name and attempts count to high scores file
 * @param high_scores_filename Path to High Scores table file
 * @param user_name User name
 * @param attempts_taken Number of attempts taken to guess the number
 * @return
 */
int write_high_scores(const string& high_scores_filename, const string& user_name, unsigned int attempts_taken)
{
    ofstream out_file{high_scores_filename, ios_base::app};
    if (!out_file.is_open()) {
        cout << "Failed to open file for writing: " << high_scores_filename << "!" << endl;
        return -1;
    }
    out_file << user_name << ' ' << attempts_taken << endl;
    out_file.close();
    return 0;
}
/**
 * Print High Scores table read from file
 * @param high_scores_filename Path to High Scores table file
 * @return
 */
int print_high_scores(const string& high_scores_filename)
{
    ifstream in_file{high_scores_filename};
    if (!in_file.is_open()) {
        std::cout << "Failed to open file for reading: " << high_scores_filename << "!" << endl;
        return -1;
    }
    cout << "\n";
    cout << "╔═════════════╗" << endl;
    cout << "║ High Scores ║" << endl;
    cout << "╚═════════════╝" << endl;

    string username;
    unsigned int high_score=0;

    while (true)
    {
        in_file >> username;
        in_file >> high_score;
        in_file.ignore();
        if (in_file.fail()) break;
        cout << username << "\t" << high_score << endl;
    }
    in_file.close();
    return 0;
}
/**
 * Entry point
 */
int main(int argc, char** argv)
{
    int max_value = 0;
    if (argc >= 2) {
        string key{argv[1]};
        if (key == "-max")
        {
            if (argc != 3)
            {
                cout << "Wrong usage! The '-max VALUE' parameter requires some value" << endl;
                return -1;
            }
            max_value = stoi(argv[2]);
        } else {
            cout << "Only '-max VALUE' optional argument is supported" << endl;
            return -1;
        }
    }
    if (max_value < 2 || max_value > 100)
        max_value = 100;
    const int target_value = random_value(max_value);
    int current_value = 0;
    unsigned int attempts = 0;
    const string high_scores_filename = "high_scores.txt";

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
    if (write_high_scores(high_scores_filename, user_name, attempts) != 0)
        return -1;
    if (print_high_scores(high_scores_filename) != 0)
        return -1;
    return 0;
}
