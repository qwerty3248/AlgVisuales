#include "../include/gridcell.h"
#include <QPen>
#include <QBrush>  // si usas también QBrush
#include <QGraphicsRectItem>  // si heredas de esta clase


GridCell::GridCell(int x, int y, int size) : QGraphicsRectItem(x * size, y * size, size, size) {
    setType(FREE);
    setBrush(Qt::white);
    setPen(QPen(Qt::black));
}

void GridCell::setType(CellType newType) {
    type = newType;
    switch (type) {
        case FREE: setBrush(Qt::white); break;
        case WALL: setBrush(Qt::black); break;
        case START: setBrush(Qt::green); break;
        case END: setBrush(Qt::red); break;
        case VISITED: setBrush(Qt::blue); break;
        case PATH_ASTAR: setBrush(Qt::yellow); break;
        case PATH_BFS: setBrush(Qt::magenta); break;
        case PATH_DIJKSTRA: setBrush(Qt::gray); break;
    }
}

CellType GridCell::getType() const {
    return type;
}
