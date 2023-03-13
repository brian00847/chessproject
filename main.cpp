
#include <cstdio>
#include <QApplication>
//#include "mymainwindow.h"
#include <QDebug>
#include <QGraphicsView>


#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QColor>

#include <memory>
struct Position
{
   int row; // = -1;
   int col; // = -1;
   Position(int r = -1 , int c = -1 )
   : row(r), col(c) {}
};




typedef int PieceID;

PieceID getPieceID()
{
   static int id = 0;
   return id++;

}
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

   static QString toStr(PieceColor color)
   {
      switch(color)
      {
         case PieceColor::Black: return "Black";
         case PieceColor::White: return "White";
      }
   }
   static QString toStr(PieceType pieceType)
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

   QString pieceDescription()
   {
      return QString("%1 %2")
         .arg(toStr(this->getPieceColor()))
         .arg(toStr(this->getPieceType()));


   }


   PieceColor getPieceColor() const { return color; }
   virtual PieceType getPieceType() const = 0;

   const PieceID id;
   const PieceColor color;
   Position pos;

   ChessPiece(PieceColor color_, Position pos_)
   : id(getPieceID())
   ,color(color_)
   , pos(pos_)
   {
   }

   //virtual ~ChessPiece() {}
   
}; //End class ChessPiece
typedef std::shared_ptr<ChessPiece> PiecePtr;
typedef std::list<PiecePtr> PiecePtrList;

class KingPiece : public ChessPiece
{
   
   public:
   virtual PieceType getPieceType() const override { return ChessPiece::PieceType::King; }

   KingPiece(PieceColor color_, Position pos_)
   : ChessPiece(color_, pos_)
   {}
};

class QueenPiece : public ChessPiece
{
   
   public:
   virtual PieceType getPieceType() const override { return ChessPiece::PieceType::King; }

   QueenPiece(PieceColor color_, Position pos_)
   : ChessPiece(color_, pos_)
   {}
};


class ChessBoardEngine
{
   PiecePtrList piecesInPlay;
   PiecePtrList piecesCaptured;
   public:
      PiecePtrList getAllPieces()
      {
         return piecesInPlay;
      }

      PiecePtrList getPieces(ChessPiece::PieceType pieceType);
      //PiecePtrList getWhitePieces();
      //PiecePtrList getBlackPieces();

      //Initialize Board to normal positions.
      void init()
      {
         //Assume White on top. Black on Bottom;

         //Create Black King
         ChessPiece::PieceColor color = ChessPiece::PieceColor::Black;
         //Position pos
         //Position pos = {0, 0};
         //pos.row = 0;
         //pos.col = 0;
         //Position pos1 = {1, 1};
         //PiecePtr bKing = std::make_shared<KingPiece>(ChessPiece::PieceColor::Black, pos);
         PiecePtr bKing = std::make_shared<KingPiece>(ChessPiece::PieceColor::Black, Position(7, 3));
         piecesInPlay.push_back(bKing);

      }

      //TODO: add ability to create custom setups


};

typedef std::shared_ptr<ChessBoardEngine> ChessBoardEnginePtr;


QGraphicsTextItem* getTextItem(PiecePtr piece)

{

      QString s = piece->pieceDescription();
      QGraphicsTextItem* textItem = new QGraphicsTextItem(s);
      QFont font("Helvetica", 14);
      
      const Position& pos = piece->pos;
      textItem->setFont(font);
      textItem->setPos(pos.col * 50, pos.row * 50);


      textItem->setTextWidth(50);
      return textItem;

}
class ChessboardScene : public QGraphicsScene
{

   public:
   void displayPieces()
   {
      if ( ! engine) 
         return;

      PiecePtrList allPieces = engine->getAllPieces();
      qDebug() << allPieces.size();

#if 1
      auto lam1 = [this] (PiecePtr piece) {
         QGraphicsItem* textItem = getTextItem(piece);
         this->addItem(textItem);

      };
      std::for_each(allPieces.begin(), allPieces.end(), lam1);
#endif

      //auto piece = allPieces[0];
      //for ( int i = 0; i < allPieces.size()


   }
      ChessBoardEnginePtr engine;
      ChessboardScene(QObject *parent = nullptr)
         : QGraphicsScene(parent)
         //, engine(engine_)
      {
         // Create the chessboard squares
         for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
               // Create a QGraphicsRectItem for each square
               QGraphicsRectItem *rect = new QGraphicsRectItem(QRectF(col*50, row*50, 50, 50));

               // Set the brush and pen to draw a chessboard pattern
               QBrush brush((row+col) % 2 == 0 ? Qt::white : Qt::darkGray);
               QPen pen(Qt::NoPen);
               rect->setBrush(brush);
               rect->setPen(pen);

               // Add the square to the scene
               addItem(rect);
            }
         }
      }
};


int main(int argc, char *argv[])
{
#if 0
   printf("hello world\n");
   return 0;
#endif
#if 1
    QApplication app(argc, argv);
    //MyMainWindow mainWindow;
    //mainWindow.show();

    ChessBoardEnginePtr engine = std::make_shared<ChessBoardEngine>();
    engine->init();
    ChessboardScene* scene = new ChessboardScene();
    scene->engine = engine;
    scene->displayPieces();
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    return app.exec();
#endif
}

