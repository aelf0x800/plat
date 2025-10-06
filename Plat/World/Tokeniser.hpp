#pragma once

#include "Token.hpp"
#include <string>
#include <vector>

namespace Plat::World
{

class Tokeniser
{
private:
    std::vector<Token> m_tokens;
    std::string m_source;
    size_t m_curPos;
    size_t m_nxtPos;

public:
    Tokeniser();

private:
    void SkipWhitespace();
    void SkipComment();

    void TokeniseLiteral();
    void TokeniseString();
    void TokeniseSymbol();

    char GetCur();
    char GetNxt();
    bool CurInRange();
    bool NxtInRange();
    void Advance();

    void Print();
};

}
