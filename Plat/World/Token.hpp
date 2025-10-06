#pragma once

#include <cstddef>

namespace Plat::World
{

enum TokenKind
{
    None,

    // Literals
    Identifier,
    Integer,
    String,
    Yes,
    No,
    Sliding,
    Swapping,

    // Properties
    Background,
    Foreground,
    Player,
    Enemies,

    // Sub-properites
    Animated,
    SlidingSpeed,
    SwappingSpeed,
    Image,
    Images,

    // Symbols
    Assign,
    Comma,
    SemiColon,
    OpenBrace,
    CloseBrace
};

struct Token
{
    TokenKind Kind;
    size_t Start;
    size_t Length;
};

}
