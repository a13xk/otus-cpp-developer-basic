#include "helpers.h"

/**
 * Print game header
 */
void print_header()
{
    std::cout << "╔═══════════════════════╗" << std::endl;
    std::cout << "║ Guess The Number Game ║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
}
/**
 * Print usage for `-level VALUE` parameter
 */
void print_level_usage() {
    std::cout << "Wrong usage! The '-level VALUE' parameter supports 3 possible values:" << std::endl;
    std::cout << "-level 1 - random number is generated in range between 0 and 10" << std::endl;
    std::cout << "-level 2 - random number is generated in range between 0 and 50" << std::endl;
    std::cout << "-level 3 - random number is generated in range between 0 and 100" << std::endl;
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
std::string ask_for_name()
{
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;
    return user_name;
}
/**
 * Write user name and attempts count to high scores file
 * @param high_scores_filename Path to High Scores table file
 * @param user_name User name
 * @param attempts_taken Number of attempts taken to guess the number
 * @return
 */
int write_high_scores(const std::string& high_scores_filename, const std::string& user_name, unsigned int attempts_taken)
{
    std::ofstream out_file{high_scores_filename, std::ios_base::app};
    if (!out_file.is_open()) {
        std::cout << "Failed to open file for writing: " << high_scores_filename << "!" << std::endl;
        return -1;
    }
    out_file << user_name << ' ' << attempts_taken << std::endl;
    out_file.close();
    return 0;
}
/**
 * Print High Scores table read from file
 * @param high_scores_filename Path to High Scores table file
 * @return
 */
int print_high_scores(const std::string& high_scores_filename)
{
    std::ifstream in_file{high_scores_filename};
    if (!in_file.is_open()) {
        std::cout << "Failed to open file for reading: " << high_scores_filename << "!" << std::endl;
        return -1;
    }
    std::cout << "\n";
    std::cout << "╔═════════════╗" << std::endl;
    std::cout << "║ High Scores ║" << std::endl;
    std::cout << "╚═════════════╝" << std::endl;

    std::string username;
    unsigned int high_score=0;

    while (true)
    {
        in_file >> username;
        in_file >> high_score;
        in_file.ignore();
        if (in_file.fail()) break;
        std::cout << username << "\t" << high_score << std::endl;
    }
    in_file.close();
    return 0;
}