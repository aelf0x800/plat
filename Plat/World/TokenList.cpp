#include "TokenList.hpp"
#include <cctype>
#include <iostream>

namespace Plat::World
{

TokenList::TokenList(std::string source) : m_tokens({}),
                                           m_source(source),
                                           m_pos(0),
                                           m_curChr(source[0]),
                                           m_nxtChr(source[1])
{
    while (InRange())
    {
        SkipWhitespace();
        SkipComment();

        Token token = {};
        if (m_curChr == '"')
            token = TokeniseString();
        else if (std::ispunct(m_curChr))
            token = TokeniseSymbol();
        else if (std::isalnum(m_curChr))
            token = TokeniseLiteral();

        m_tokens.push_back(token);
    }

    Print();
}

void TokenList::SkipWhitespace() 
{
    while (std::isspace(m_curChr) && InRange())
        Advance();
}

void TokenList::SkipComment() 
{
    if (m_curChr == '#')
        while (m_curChr != '\n' && InRange())
            Advance();
}

Token TokenList::TokeniseString() 
{
    return {};
}

Token TokenList::TokeniseSymbol() 
{
    Token token = 
    {
        .Kind = TokenKind::None,
        .Start = m_pos,
        .Length = 1
    };
    
    switch (m_curChr)
    {
        case '=': token.Kind = TokenKind::Assign; break;
        case ',': token.Kind = TokenKind::Comma; break;
        case ';': token.Kind = TokenKind::SemiColon; break;
        case '{': token.Kind = TokenKind::OpenBrace; break;
        case '}': token.Kind = TokenKind::CloseBrace; break;
        default: token = TokeniseLiteral(); break;
    }

    Advance();

    return token;
}

Token TokenList::TokeniseLiteral() 
{
    Token token = 
    {
        .Kind = TokenKind::Identifier,
        .Start = m_pos,
        .Length = 0,
    };

    while (InRange() && !std::isspace(m_curChr))
    {
        token.Length++;
        Advance();
    }

    return token;
}

bool TokenList::InRange(int offset) { return m_pos + offset < m_source.size(); }

void TokenList::Advance() 
{ 
    m_pos++; 
    m_curChr = InRange() ? m_source[m_pos] : 0;
    m_nxtChr = InRange(1) ? m_source[m_pos + 1] : 0;
}

void TokenList::Print()
{
    static const std::string_view kindToStr[] = 
    {
        [TokenKind::None] = "TokenKind::None",
        [TokenKind::Identifier] = "TokenKind::Identifier",
        [TokenKind::Integer] = "TokenKind::Integer",
        [TokenKind::String] = "TokenKind::String",
        [TokenKind::Yes] = "TokenKind::Yes",
        [TokenKind::No] = "TokenKind::No",
        [TokenKind::Sliding] = "TokenKind::Sliding",
        [TokenKind::Swapping] = "TokenKind::Swapping",
        [TokenKind::Background] = "TokenKind::Background",
        [TokenKind::Foreground] = "TokenKind::Foreground",
        [TokenKind::Player] = "TokenKind::Player",
        [TokenKind::Enemies] = "TokenKind::Enemies",
        [TokenKind::Animated] = "TokenKind::Animated",
        [TokenKind::SlidingSpeed] = "TokenKind::SlidingSpeed",
        [TokenKind::SwappingSpeed] = "TokenKind::SwappingSpeed",
        [TokenKind::Image] = "TokenKind::Image",
        [TokenKind::Images] = "TokenKind::Images",
        [TokenKind::Assign] = "TokenKind::Assign",
        [TokenKind::Comma] = "TokenKind::Comma",
        [TokenKind::SemiColon] = "TokenKind::SemiColon",
        [TokenKind::OpenBrace] = "TokenKind::OpenBrace",
        [TokenKind::CloseBrace] = "TokenKind::CloseBrace"
    };

    for (const Token& token : m_tokens)
        std::cout << "Token { "
                  << ".Kind = " << kindToStr[token.Kind] << ", "
                  << ".Start = " << token.Start << ", "
                  << ".Length = " << token.Length
                  << " }"
                  << " is \"" << m_source.substr(token.Start, token.Length) << "\"\n";
}

}
