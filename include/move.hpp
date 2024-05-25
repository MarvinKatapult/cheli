#pragma once

#include "square.hpp"

#define PRINT_MOVE_C( COL, MOV )   TLog::log( COL, "%c [X:%d;Y:%d] -> [X:%d;Y:%d]\n", \
                                   MOV.startSquare().piece, MOV.startSquare().x, MOV.startSquare().y, \
                                   MOV.destSquare().x, MOV.destSquare().y )

#define PRINT_MOVE( MOV )   PRINT_MOVE_C( TLog::White, MOV )

class TString;

class Move {

    public:

        /** Constructors **/
        Move( const Square & start_square, const Square & dest_square );
        Move( const Move & other );

        /** Utils **/
        Square startSquare( void ) const { return myStartSquare; }
        Square destSquare( void ) const { return myDestSquare; }
        short startX( void ) const { return myStartSquare.x; }
        short startY( void ) const { return myStartSquare.y; }
        short destX( void ) const { return myDestSquare.x; }
        short destY( void ) const { return myDestSquare.y; }

        bool hasPiece( Piece piece ) const { return myStartSquare.piece == piece; }
        Piece piece( void ) const { return myStartSquare.piece; }
        TString getNotation( void ) const;

        /** Operators **/
        Move & operator=( const Move & other );

    
    private:

        Square myStartSquare;
        Square myDestSquare;
};
