
#ifndef __CHESSBOARD_HPP__
#define __CHESSBOARD_HPP__

#include "Piece.hpp"
struct ChessBoard
{

   //2d array;
   std::vector<std::vector<PiecePtr>> boardSquares;
   
   void addPiece(PiecePtr piece);

   bool movePiece(PiecePtr piece, int dstRow, int dstCol);

   const int n_rows = 8;
   const int n_cols = 8;
   ChessBoard();

   bool isValidPos(const int row, const int col);

   PiecePtr getPiece(const int row, const int col);

   PiecePtrList getPiecesInPlay();
};
#endif
