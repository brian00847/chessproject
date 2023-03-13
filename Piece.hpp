#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <vector>
#include <list>
#include <QString>
class ChessBoard;
struct Position
{
   int row; // = -1;
   int col; // = -1;
   Position(int r = -1 , int c = -1 )
   : row(r), col(c) {}
};

typedef std::vector<Position> Positions;



typedef int PieceID;

class ChessPiece
{

   public:
   
   enum class PieceColor
   {
      Black,
      White,
   };

   enum class PieceType
   {
      King,
      Queen,
      Bishop,
      Knight,
      Rook,
      Pawn,
   };

   static QString toStr(PieceColor color);
   static QString toStr(PieceType pieceType);

   virtual Positions getValidMoves(ChessBoard* brd) const;

   QString pieceDescription();


   PieceColor getPieceColor() const;
   virtual PieceType getPieceType() const = 0;

   const PieceID id;
   const PieceColor color;
   Position pos;

   ChessPiece(PieceColor color_, Position pos_);

   //virtual ~ChessPiece() {}
   
}; //End class ChessPiece
typedef std::shared_ptr<ChessPiece> PiecePtr;
typedef std::list<PiecePtr> PiecePtrList;

class KingPiece : public ChessPiece
{
   
   public:
   virtual PieceType getPieceType() const override;

   KingPiece(PieceColor color_, Position pos_);
};

class QueenPiece : public ChessPiece
{
   public:
   virtual PieceType getPieceType() const override;

   QueenPiece(PieceColor color_, Position pos_);

   //QueenPiece
   virtual Positions getValidMoves(ChessBoard* brd) const override;
};

class BishopPiece : public ChessPiece
{
   public:
   virtual PieceType getPieceType() const override;

   BishopPiece(PieceColor color_, Position pos_);
};

class KnightPiece : public ChessPiece
{
   public:
   virtual PieceType getPieceType() const override;

   KnightPiece(PieceColor color_, Position pos_);
};

class RookPiece : public ChessPiece
{
   public:
   virtual PieceType getPieceType() const override;

   RookPiece(PieceColor color_, Position pos_);
};

class PawnPiece : public ChessPiece
{
   public:
   virtual PieceType getPieceType() const override;

   PawnPiece(PieceColor color_, Position pos_);
};


#endif
