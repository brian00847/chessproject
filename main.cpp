
#include <cstdio>
#include <QApplication>
//#include "mymainwindow.h"
#include <QGraphicsView>


#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QColor>

class ChessPiece
{

   public:
   enum class PieceType
   {
      King,
      Queen,
      Bishop,
      Knight,
      Rook,
      Pawn,
   };

   virtual PieceType getPieceType() const = 0;
};

class ChessboardScene : public QGraphicsScene
{
public:
    ChessboardScene(QObject *parent = nullptr)
        : QGraphicsScene(parent)
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

    ChessboardScene* scene = new ChessboardScene();
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    return app.exec();
#endif
}

