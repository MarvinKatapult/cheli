#include "move.hpp"
#include "logic.hpp"
#include "tstring.hpp"

#include <ctype.h>

#define SMALL_A_ASCII   97

Move::Move( const Square & p_start_square, const Square & p_dest_square ) {
    myStartSquare = p_start_square;
    myDestSquare = p_dest_square;
}

Move::Move( const Move & p_other ) {
    myStartSquare = p_other.startSquare();    
    myDestSquare = p_other.destSquare();    
}

Move & Move::operator=( const Move & p_other ) {
    myStartSquare = p_other.startSquare();
    myDestSquare = p_other.destSquare();

    return *this;
}

TString Move::getNotation() const {
    const Piece piece = myStartSquare.piece;
    bool is_capturing = Logic::squareHasEnemy( myDestSquare, Pieces::getColor( piece ) );

    TString str;
    if ( piece != 'p' && piece != 'P' ) str += toupper( piece );
    if ( ( piece == 'p' || piece == 'P' ) && is_capturing ) {
        str += SMALL_A_ASCII + myStartSquare.x; 
    }
    if ( is_capturing ) str += 'x';
    str += myDestSquare.name();
    return str;

}
