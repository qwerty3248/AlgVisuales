#ifndef PATHFINDERCONTROLLER_H
#define PATHFINDERCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include "../include/gridcell.h"
#include <cstdlib>  // para rand()
#include <ctime>    // para time()

class PathfinderController : public QObject {
    Q_OBJECT
public:
    PathfinderController(QGraphicsScene *scene);
    void runBFS();
    void runDijkstra();
    void runAStar();
    void reset();
    void placeRandomWalls(float probability);

private:
    QGraphicsScene *scene;
    QVector<QVector<GridCell*>> grid;
    QGraphicsTextItem *errorText;

    void showErrorMessage(const QString &msg);
    void clearErrorMessage();
    void createGrid(int rows, int cols);
};

#endif // PATHFINDERCONTROLLER_H