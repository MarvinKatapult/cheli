#pragma once

typedef char Piece;

namespace Pieces {

    enum PieceSymbol {
        BlackPawn = 'p',
        WhitePawn = 'P',
        BlackKnight = 'n',
        WhiteKnight = 'N',
        BlackBishop = 'b',
        WhiteBishop = 'B',
        BlackRook = 'r',
        WhiteRook = 'R',
        BlackQueen = 'q',
        WhiteQueen = 'Q',
        BlackKing = 'k',
        WhiteKing = 'K',

        NoPiece = ' '
    };

    enum PieceColor {
        White = 0,
        Black,
        NoColor
    };

    /** Utils **/
    bool isPiece( char piece );
    PieceColor getColor( Piece piece );

};
