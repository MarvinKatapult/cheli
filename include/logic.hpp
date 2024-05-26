#pragma once

class Board;
class Square;
class TList;
class TList;
typedef char PieceSymbol;

#include "piece.hpp"

class Logic {

    enum HorizontalDirection {
        Left = -1,
        HNone = 0,
        Right = 1
    };

    enum VerticalDirection {
        Up = -1,
        VNone = 0,
        Down = 1
    };
    
    public:

        /** Constructor **/
        Logic( Board * board );

        /** Modification **/
        void removeIllegalMoves( TList * list ) const;

        /** Utils **/
        TList getLegals( bool check_for_checks = true );
        void getLegals( TList * list, const Square & square );
        void getLegals( TList * legals, int x, int y );
        Pieces::PieceColor isCheck( void );
        Pieces::PieceColor isCheckmate( void );

        static bool squareHasEnemy( const Square & square, Pieces::PieceColor color );
        static bool squareHasAlly( const Square & p_square, Pieces::PieceColor p_color );

    private:

        /** These functions have to be called with a square with the correspending piece on it **/
        void getLegalsPawn( TList * list, const Square & square );
        void getLegalsBishop( TList * list, const Square & square );
        void getLegalsRook( TList * list, const Square & square );
        void getLegalsQueen( TList * list, const Square & square );
        void getLegalsKing( TList * list, const Square & square );
        void getLegalsKnight( TList * list, const Square & square );
        void getLegalsPawnMove( TList * list, const Square & square );
        void getLegalsPawnCapture( TList * list, const Square & square );
        void getLegalsPawnEnpassant( TList * list, const Square & start_square );

        bool checkEnpassant( const Square & start_square, int enemy_pawn_start_row, Logic::HorizontalDirection dir );
        void checkPawnCapture( TList * list, const Square & start_square, const Square & dest_square );
        void getLegalsCommon( TList * list, const Square & start_square, HorizontalDirection horizontal, VerticalDirection vertical, int range = 8 );

        Board * myBoard;
};
