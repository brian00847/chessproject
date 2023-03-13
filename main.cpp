
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
#include "ChessBoard.hpp"


class ChessBoard;


class ChessBoardEngine
{
   //PiecePtrList piecesInPlay;
   PiecePtrList piecesCaptured;
   ChessBoard chessBoard;
   public:
      PiecePtrList getAllPieces()
      {
         return chessBoard.getPiecesInPlay();
      }

      //PiecePtrList getPieces(ChessPiece::PieceType pieceType);

      PiecePtrList getPiecesByColor(const ChessPiece::PieceColor color)
      {
         
         auto allPieces = this->getAllPieces();
         PiecePtrList pieces;

         auto lam1 = [&pieces, color] (PiecePtr piece) {
            if ( piece->color == color )
               pieces.push_back(piece);

         };
         std::for_each(allPieces.begin(), allPieces.end(), lam1);
         return pieces;
      }

      void _init1(
         const ChessPiece::PieceColor color,
         const int pawnRow,
         const int pieceRow)
      {
         chessBoard.addPiece(std::make_shared<RookPiece>(color, Position(pieceRow, 0)));
         chessBoard.addPiece(std::make_shared<KnightPiece>(color, Position(pieceRow, 1)));
         chessBoard.addPiece(std::make_shared<BishopPiece>(color, Position(pieceRow, 2)));
         chessBoard.addPiece(std::make_shared<BishopPiece>(color, Position(pieceRow, 5)));
         chessBoard.addPiece(std::make_shared<KnightPiece>(color, Position(pieceRow, 6)));
         chessBoard.addPiece(std::make_shared<RookPiece>(color, Position(pieceRow, 7)));

         for( int i = 0; i < 8; ++i )
         {
            chessBoard.addPiece(std::make_shared<PawnPiece>(color, Position(pawnRow, i)));

         }
      }

      //Initialize Board to normal positions.
      void init()
      {
         //Create Black King
         const ChessPiece::PieceColor color = ChessPiece::PieceColor::Black;
         const int pawnRow = 6;
         const int pieceRow = 7;

         _init1(ChessPiece::PieceColor::Black, 6, 7);
         _init1(ChessPiece::PieceColor::White, 1, 0);

         //Create Queen and King - Black 
         chessBoard.addPiece( std::make_shared<KingPiece>(ChessPiece::PieceColor::Black, Position(7, 3)));
         chessBoard.addPiece( std::make_shared<QueenPiece>(ChessPiece::PieceColor::Black, Position(7, 4)));

         //Create Queen and King - White
         chessBoard.addPiece( std::make_shared<KingPiece>(ChessPiece::PieceColor::White, Position(0, 3)));
         chessBoard.addPiece( std::make_shared<QueenPiece>(ChessPiece::PieceColor::White, Position(0, 4)));
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

