#pragma once
#include <iostream>
#include <fstream>

void print_header();
void print_wrong_usage();
int random_value(const int max_value);
std::string ask_for_name();
int write_high_scores(const std::string& high_scores_filename, const std::string& user_name, unsigned int attempts_taken);
int print_high_scores(const std::string& high_scores_filename);