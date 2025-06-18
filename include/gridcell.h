#ifndef GRIDCELL_H
#define GRIDCELL_H

#include <QGraphicsRectItem>
#include <QBrush>

enum CellType { FREE, WALL, START, END, VISITED, PATH_BFS ,PATH_DIJKSTRA, PATH_ASTAR };

class GridCell : public QGraphicsRectItem {
public:
    GridCell(int x, int y, int size);
    void setType(CellType type);
    CellType getType() const;
private:
    CellType type;
};

#endif // GRIDCELL_H