#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H

#include <QVector>
#include <QPair>
#include <QQueue>
#include <QSet>
#include <QMap>
#include <QList>
#include <QtMath>

namespace GraphAlgorithms {
    QVector<QPair<int, int>> bfs(QVector<QVector<int>> &map, QPair<int, int> start, QPair<int, int> end);
    QVector<QPair<int, int>> dijkstra(QVector<QVector<int>> &map, QPair<int, int> start, QPair<int, int> end);
    QVector<QPair<int, int>> a_star(QVector<QVector<int>> &map, QPair<int, int> start, QPair<int, int> end);
}

#endif // GRAPHALGORITHMS_H