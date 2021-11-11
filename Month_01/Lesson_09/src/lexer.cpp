// OTUS C++ Basic course homework skeleton.
// Lexer implementation

#include "lexer.hpp"

#include <cctype>

Lexer::Token Lexer::next_token() {
    for (;;) {
        switch (state_) {
        case State::End:
            return Token::End;
        case State::ReadNumber:
            if (end()) {
                state_ = State::End;
                return Token::Number;
            }
            if (std::isdigit(ch_)) {
                number_ = 10 * number_ + (ch_ - '0');
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            state_ = State::Empty;
            return Token::Number;
        case State::ReadName:
            if (end()) {
                state_ = State::End;
                return Token::Name;
            }
            if (std::isalpha(ch_) || std::isdigit(ch_)) {
                name_ += ch_;
                next_char();
                break;
            }
            state_ = State::Empty;
            return Token::Name;
        case State::Empty:
            if (end()) {
                state_ = State::End;
                return Token::End;
            }
            if (std::isspace(ch_)) {
                next_char();
                break;
            }
            if (is_operator(ch_)) {
                operator_ = ch_;
                next_char();
                return Token::Operator;
            }
            if (ch_ == '(') {
                next_char();
                return Token::LParenthesis;
            }
            if (ch_ == ')') {
                next_char();
                return Token::RParenthesis;
            }
            if (std::isdigit(ch_)) {
                number_ = ch_ - '0';
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            if (std::isalpha(ch_)) {
                name_ = ch_;
                state_ = State::ReadName;
                next_char();
                break;
            }
        }
    }
}
