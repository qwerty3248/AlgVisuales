#include "../include/graphalgorithms.h"
#include <QMap>
#include <QPair>
#include <QVector>
#include <QList>
namespace GraphAlgorithms {

QVector<QPair<int, int>> bfs(QVector<QVector<int>> &map, QPair<int, int> start, QPair<int, int> end) {
    int rows = map.size(), cols = map[0].size();
    QQueue<QPair<int, int>> queue;
    QMap<QPair<int, int>, QPair<int, int>> came_from;
    QSet<QPair<int, int>> visited;

    queue.enqueue(start);
    visited.insert(start);

    QVector<QPair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!queue.isEmpty()) {
        auto current = queue.dequeue();
        if (current == end) break;

        for (auto dir : directions) {
            QPair<int, int> next = {current.first + dir.first, current.second + dir.second};
            if (next.first >= 0 && next.first < rows && next.second >= 0 && next.second < cols &&
                !visited.contains(next) && map[next.first][next.second] != 1) {
                queue.enqueue(next);
                visited.insert(next);
                came_from[next] = current;
            }
        }
    }

    QVector<QPair<int, int>> path;
    for (auto at = end; at != start; at = came_from[at]) {
        path.prepend(at);
        if (!came_from.contains(at)) return {};
    }
    path.prepend(start);
    return path;
}

QVector<QPair<int, int>> dijkstra(QVector<QVector<int>> &map, QPair<int, int> start, QPair<int, int> end) {
    int rows = map.size(), cols = map[0].size();
    QMap<QPair<int, int>, int> dist;
    QMap<QPair<int, int>, QPair<int, int>> prev;
    QSet<QPair<int, int>> visited;
    QList<QPair<int, int>> queue;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            dist[{i, j}] = INT_MAX;

    dist[start] = 0;
    queue.append(start);

    QVector<QPair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!queue.isEmpty()) {
        std::sort(queue.begin(), queue.end(), [&](auto a, auto b) { return dist[a] < dist[b]; });
        auto current = queue.takeFirst();

        if (current == end) break;
        if (visited.contains(current)) continue;
        visited.insert(current);

        for (auto dir : directions) {
            QPair<int, int> next = {current.first + dir.first, current.second + dir.second};
            if (next.first >= 0 && next.first < rows && next.second >= 0 && next.second < cols && map[next.first][next.second] != 1) {
                int alt = dist[current] + 1;
                if (alt < dist[next]) {
                    dist[next] = alt;
                    prev[next] = current;
                    queue.append(next);
                }
            }
        }
    }

    QVector<QPair<int, int>> path;
    for (auto at = end; at != start; at = prev[at]) {
        path.prepend(at);
        if (!prev.contains(at)) return {};
    }
    path.prepend(start);
    return path;
}

QVector<QPair<int, int>> a_star(QVector<QVector<int>> &map, QPair<int, int> start, QPair<int, int> end) {
    int rows = map.size(), cols = map[0].size();
    QMap<QPair<int, int>, int> g_score, f_score;
    QMap<QPair<int, int>, QPair<int, int>> came_from;
    QSet<QPair<int, int>> open_set;
    QList<QPair<int, int>> open_list;

    auto heuristic = [&](QPair<int, int> a, QPair<int, int> b) {
        return qAbs(a.first - b.first) + qAbs(a.second - b.second);
    };

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            g_score[{i, j}] = f_score[{i, j}] = INT_MAX;

    g_score[start] = 0;
    f_score[start] = heuristic(start, end);

    open_set.insert(start);
    open_list.append(start);

    QVector<QPair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!open_list.isEmpty()) {
        std::sort(open_list.begin(), open_list.end(), [&](auto a, auto b) { return f_score[a] < f_score[b]; });
        auto current = open_list.takeFirst();
        open_set.remove(current);

        if (current == end) break;

        for (auto dir : directions) {
            QPair<int, int> next = {current.first + dir.first, current.second + dir.second};
            if (next.first >= 0 && next.first < rows && next.second >= 0 && next.second < cols && map[next.first][next.second] != 1) {
                int tentative_g = g_score[current] + 1;
                if (tentative_g < g_score[next]) {
                    came_from[next] = current;
                    g_score[next] = tentative_g;
                    f_score[next] = tentative_g + heuristic(next, end);
                    if (!open_set.contains(next)) {
                        open_set.insert(next);
                        open_list.append(next);
                    }
                }
            }
        }
    }

    QVector<QPair<int, int>> path;
    for (auto at = end; at != start; at = came_from[at]) {
        path.prepend(at);
        if (!came_from.contains(at)) return {};
    }
    path.prepend(start);
    return path;
}

} // namespace