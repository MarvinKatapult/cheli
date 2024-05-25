#include "tlog.hpp"

#include "board.hpp"
#include "logic.hpp"
#include "move.hpp"

#include "tlist.hpp"

int main() {

    TLog log;

    // Board board( "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR" );
    // Board board( "r7/2K5/8/8/8/8/8/8" );
    Board board( "8/Rpk5/8/8/8/8/8/8" );
    board.printBoard();

    Logic logic( &board );
    TList list = logic.getLegals();

    for ( int i = 0; i < list.count(); i++ ) {
        Move move = *(Move *)list.getValue( i );
        PRINT_MOVE( move );

        Board temp = board;
        temp.playMove( move );

        temp.printBoard();
        log.print( "\n" );
    }

    return 0;
}
