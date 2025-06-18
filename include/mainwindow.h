#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include "../include/gridcell.h"
#include "../include/pathfindercontroller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene *scene;
    PathfinderController *controller;
    QPushButton *bfsButton, *dijkstraButton, *astarButton, *resetButton;

    void setupUI();
};

#endif // MAINWINDOW_H