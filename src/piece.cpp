#include "piece.hpp"

#include <ctype.h>

bool Pieces::isPiece( char p_piece ) {
    char norm_symbol = tolower( p_piece );
    return ( norm_symbol == 'p'
          || norm_symbol == 'b'
          || norm_symbol == 'n'
          || norm_symbol == 'r'
          || norm_symbol == 'q'
          || norm_symbol == 'k' );
}

Pieces::PieceColor Pieces::getColor( Piece p_piece ) {
    return islower( p_piece ) != 0 ? Pieces::Black : Pieces::White;
}
