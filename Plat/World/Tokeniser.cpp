#include "Tokeniser.hpp"
#include <cctype>

namespace Plat::World
{

Tokeniser::Tokeniser() : m_tokens({}),
                         m_source(""),
                         m_curPos(0),
                         m_nxtPos(1)
{
}

void Tokeniser::SkipWhitespace() 
{
    while (std::isspace(GetCur()) && CurInRange())
        Advance();
}

void Tokeniser::SkipComment() 
{
    while (GetCur() != '\n' && CurInRange())
        Advance();
}

void Tokeniser::TokeniseLiteral() {}

void Tokeniser::TokeniseString() 
{
}

void Tokeniser::TokeniseSymbol() 
{
    Token token = 
    {
        .Kind = TokenKind::None,
        .Start = m_curPos,
        .Length = 1
    };
    switch (GetCur())
    {
        case '=': token.Kind = TokenKind::Assign; break;
        case ',': token.Kind = TokenKind::Comma; break;
        case ';': token.Kind = TokenKind::SemiColon; break;
        case '{': token.Kind = TokenKind::OpenBrace; break;
        case '}': token.Kind = TokenKind::CloseBrace; break;
    }
    m_tokens.push_back(token);
}

char Tokeniser::GetCur() { return m_source[m_curPos]; }
char Tokeniser::GetNxt() { return m_source[m_nxtPos]; }
bool Tokeniser::CurInRange() { return m_curPos < m_source.size(); }
bool Tokeniser::NxtInRange() { return m_nxtPos < m_source.size(); }
void Tokeniser::Advance() { m_curPos++; m_nxtPos++; }

void Tokeniser::Print()
{
    for (const Token& token : m_tokens)
        std::cout << "Token { "
                  << ".Kind = " << token.Kind << ", "
                  << ".Start = " << token.Start << ", "
                  << ".Length = " << token.Length
                  << " }\n";
}

}
