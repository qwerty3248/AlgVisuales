#include "../include/pathfindercontroller.h"
#include "../include/graphalgorithms.h"

PathfinderController::PathfinderController(QGraphicsScene *s) : scene(s) {
    createGrid(20, 20); // default 20x20
}

void PathfinderController::createGrid(int rows, int cols) {
    int cellSize = 25;
    grid.resize(rows);
    for (int i = 0; i < rows; ++i) {
        grid[i].resize(cols);
        for (int j = 0; j < cols; ++j) {
            GridCell *cell = new GridCell(j, i, cellSize);
            scene->addItem(cell);
            grid[i][j] = cell;
        }
    }

    // Asignar start y end por defecto
    if (!grid.empty() && !grid[0].empty()) {
        grid[0][0]->setType(START); // esquina superior izquierda
        grid[rows-1][cols-1]->setType(END); // esquina inferior derecha
    }

    placeRandomWalls(0.3f);
}

// Función auxiliar para mostrar mensaje de error en la escena
void PathfinderController::showErrorMessage(const QString &msg) {
    if (errorText) {
        scene->removeItem(errorText);
        delete errorText;
        errorText = nullptr;
    }
    errorText = scene->addText(msg);
    errorText->setDefaultTextColor(Qt::red);
    // Posición: arriba a la izquierda, ajusta según necesites
    errorText->setPos(10, 10);
}

void PathfinderController::clearErrorMessage() {
    if (errorText) {
        scene->removeItem(errorText);
        delete errorText;
        errorText = nullptr;
    }
}

void PathfinderController::placeRandomWalls(float probability) {
    srand(time(nullptr));  // Semilla aleatoria

    for (auto &row : grid) {
        for (auto &cell : row) {
            CellType type = cell->getType();
            if (type != START && type != END) {  // No tocar start ni end
                float r = static_cast<float>(rand()) / RAND_MAX;
                if (r < probability) {
                    cell->setType(WALL);
                } else {
                    cell->setType(FREE);
                }
            }
        }
    }
}


void PathfinderController::runBFS() {
    clearErrorMessage();
    
    QVector<QVector<int>> map(grid.size(), QVector<int>(grid[0].size()));
    QPair<int, int> start, end;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            CellType type = grid[i][j]->getType();
            if (type == WALL) map[i][j] = 1;
            else map[i][j] = 0;
            if (type == START) start = {i, j};
            if (type == END) end = {i, j};
        }
    }

    if (start.first == -1 || start.second == -1) {
        showErrorMessage("ERROR: No se ha definido el START");
        return;
    }
    if (end.first == -1 || end.second == -1) {
        showErrorMessage("ERROR: No se ha definido el END");
        return;
    }

    auto path = GraphAlgorithms::bfs(map, start, end);
    for (auto &[i, j] : path) {
        if (grid[i][j]->getType() != START && grid[i][j]->getType() != END)
            grid[i][j]->setType(PATH_BFS);
    }
}

void PathfinderController::runDijkstra() {
    clearErrorMessage();
    
    QVector<QVector<int>> map(grid.size(), QVector<int>(grid[0].size()));
    QPair<int, int> start, end;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            CellType type = grid[i][j]->getType();
            if (type == WALL) map[i][j] = 1;
            else map[i][j] = 0;
            if (type == START) start = {i, j};
            if (type == END) end = {i, j};
        }
    }

    if (start.first == -1 || start.second == -1) {
        showErrorMessage("ERROR: No se ha definido el START");
        return;
    }
    if (end.first == -1 || end.second == -1) {
        showErrorMessage("ERROR: No se ha definido el END");
        return;
    }

    auto path = GraphAlgorithms::dijkstra(map, start, end);
    for (auto &[i, j] : path) {
        if (grid[i][j]->getType() != START && grid[i][j]->getType() != END)
            grid[i][j]->setType(PATH_DIJKSTRA);
    }
}

void PathfinderController::runAStar() {
    clearErrorMessage();
    
    QVector<QVector<int>> map(grid.size(), QVector<int>(grid[0].size()));
    QPair<int, int> start, end;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            CellType type = grid[i][j]->getType();
            if (type == WALL) map[i][j] = 1;
            else map[i][j] = 0;
            if (type == START) start = {i, j};
            if (type == END) end = {i, j};
        }
    }

    if (start.first == -1 || start.second == -1) {
        showErrorMessage("ERROR: No se ha definido el START");
        return;
    }
    if (end.first == -1 || end.second == -1) {
        showErrorMessage("ERROR: No se ha definido el END");
        return;
    }

    auto path = GraphAlgorithms::a_star(map, start, end);
    for (auto &[i, j] : path) {
        if (grid[i][j]->getType() != START && grid[i][j]->getType() != END)
            grid[i][j]->setType(PATH_ASTAR);
    }
}

void PathfinderController::reset() {
    for (auto &row : grid) {
        for (auto &cell : row) {
            CellType type = cell->getType();
            if (type != START && type != END) {
                cell->setType(FREE);
            }
        }
    }
    placeRandomWalls(0.3f);
}