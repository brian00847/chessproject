
#include "ChessBoard.hpp"


void ChessBoard::addPiece(PiecePtr piece)
{
   if ( ! piece ) return;
   if ( piece->pos.row < 0 || piece->pos.row >= n_rows ) return;
   if ( piece->pos.col < 0 || piece->pos.col >= n_cols ) return;
   boardSquares[piece->pos.row][piece->pos.col] = piece;
}

bool movePiece(PiecePtr piece, int dstRow, int dstCol)
{
   //Check if destination is valid.
   return false;
}

const int n_rows = 8;
const int n_cols = 8;
ChessBoard::ChessBoard()
{
   boardSquares.resize(n_rows);
   for ( int irow = 0; irow < n_rows; ++irow )
   {
      boardSquares[irow].resize(n_cols);
   }
}

bool ChessBoard::isValidPos(const int row, const int col)
{
   if ( row >= 0 && row < n_rows &&
         col >= 0 && col < n_cols )
      return true;
   return false;
}

PiecePtr ChessBoard::getPiece(const int row, const int col) 
{
   if ( ! isValidPos(row, col) )
      return PiecePtr();

   PiecePtr piece;
   return piece;

}

PiecePtrList ChessBoard::getPiecesInPlay()
{
   PiecePtrList ret;
   for ( int irow = 0; irow < n_rows; ++irow )
   {
      for ( int icol = 0; icol < n_cols; ++icol )
      {
         PiecePtr piece =  boardSquares[irow][icol];
         if ( piece )
         {
            ret.push_back(piece);
         }
      }
   }
   return ret;
}
