// OTUS C++ Basic course homework skeleton.
// Lexer interface

#pragma once

#include <istream>
#include <string>

class Lexer {
  public:
    enum class Token {
        Number,
        Operator,
        End,
        LParenthesis,
        RParenthesis,
        Name,
    };

    explicit Lexer(std::istream &in);

    Lexer(const Lexer &other) = delete;

    Lexer &operator=(const Lexer &other) = delete;

    Token next_token();

    int get_number() const;
    std::string get_operator() const;
    std::string get_name() const;

  protected:
    bool is_parenthesis(char ch) const;

    bool is_operator(char ch) const;

  private:
    enum class State {
        Empty,
        ReadNumber,
        ReadName,
        End,
    };
    char next_char();
    bool is_end() const;

    State state_;
    std::string name_;
    int number_;
    std::string operator_;
    char ch_;
    std::istream &in_;
};
