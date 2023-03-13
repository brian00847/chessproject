
#include "Piece.hpp"
static PieceID getPieceID()
{
   static int id = 0;
   return id++;

}

QString ChessPiece::toStr(PieceColor color)
{
   switch(color)
   {
      case PieceColor::Black: return "Black";
      case PieceColor::White: return "White";
   }
}
QString ChessPiece::toStr(PieceType pieceType)
{
   switch(pieceType)
   {
      case PieceType::King: return "King";
      case PieceType::Queen: return "Queen";
      case PieceType::Bishop: return "Bishop";
      case PieceType::Knight: return "Knight";
      case PieceType::Rook: return "Rook";
      case PieceType::Pawn: return "Pawn";
   }

}

Positions ChessPiece::getValidMoves(ChessBoard* brd) const
{
   Positions ret;
   return ret;
}

QString ChessPiece::pieceDescription()
{
   return QString("%1 %2")
      .arg(toStr(this->getPieceColor()))
      .arg(toStr(this->getPieceType()));


}


ChessPiece::PieceColor ChessPiece::getPieceColor() const { return color; }
//ChessPiece::PieceType ChessPiece::getPieceType() const = 0;

ChessPiece::ChessPiece(ChessPiece::PieceColor color_, Position pos_)
   : id(getPieceID())
   ,color(color_)
   , pos(pos_)
   {
   }


ChessPiece::PieceType KingPiece::getPieceType() const { return ChessPiece::PieceType::King; }

KingPiece::KingPiece(PieceColor color_, Position pos_)
   : ChessPiece(color_, pos_)
{}


ChessPiece::PieceType QueenPiece::getPieceType() const { return ChessPiece::PieceType::Queen; }

QueenPiece::QueenPiece(PieceColor color_, Position pos_)
   : ChessPiece(color_, pos_)
{}

//QueenPiece
Positions QueenPiece::getValidMoves(ChessBoard* brd) const 
{
   Positions ret;
   //Check diagonals
   //Go up left until find a piece
   int irow = this->pos.row - 1;
   int icol = this->pos.col - 1;
   //while ( brd->isValidPos(irow, icol) )
   {
      irow--;
      icol--;

   }

   //Check straight
   return ret;
}

ChessPiece::PieceType BishopPiece::getPieceType() const { return ChessPiece::PieceType::Bishop; }

BishopPiece::BishopPiece(PieceColor color_, Position pos_)
   : ChessPiece(color_, pos_)
{}

ChessPiece::PieceType KnightPiece::getPieceType() const { return ChessPiece::PieceType::Knight; }

KnightPiece::KnightPiece(PieceColor color_, Position pos_)
   : ChessPiece(color_, pos_)
{}


ChessPiece::PieceType RookPiece::getPieceType() const { return ChessPiece::PieceType::Rook; }

RookPiece::RookPiece(PieceColor color_, Position pos_)
   : ChessPiece(color_, pos_)
{}

ChessPiece::PieceType PawnPiece::getPieceType() const { return ChessPiece::PieceType::Pawn; }

PawnPiece::PawnPiece(PieceColor color_, Position pos_)
   : ChessPiece(color_, pos_)
{}
