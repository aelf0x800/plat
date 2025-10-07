#pragma once

#include "Token.hpp"
#include <string>
#include <vector>

namespace Plat::World
{

class TokenList
{
private:
    std::vector<Token> m_tokens;

    std::string m_source;
    size_t m_pos;
    char m_curChr;
    char m_nxtChr;

public:
    TokenList(std::string source);

private:
    void SkipWhitespace();
    void SkipComment();

    Token TokeniseString();
    Token TokeniseSymbol();
    Token TokeniseLiteral();

    bool InRange(int offset = 1);
    void Advance();

    void Print();
};

}
