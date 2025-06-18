#include "../include/mainwindow.h"
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scene(new QGraphicsScene(this)), controller(new PathfinderController(scene)) {
    setupUI();
}

MainWindow::~MainWindow() {
    delete controller;
    delete scene;
}

void MainWindow::setupUI() {
    // Crear vista de la escena
    QGraphicsView *view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setFixedSize(520, 520);  // Ajusta el tamaño según el grid

    // Crear botones
    bfsButton = new QPushButton("BFS");
    dijkstraButton = new QPushButton("Dijkstra");
    astarButton = new QPushButton("A*");
    resetButton = new QPushButton("Reset");

    // Conectar botones
    connect(bfsButton, &QPushButton::clicked, controller, &PathfinderController::runBFS);
    connect(dijkstraButton, &QPushButton::clicked, controller, &PathfinderController::runDijkstra);
    connect(astarButton, &QPushButton::clicked, controller, &PathfinderController::runAStar);
    connect(resetButton, &QPushButton::clicked, controller, &PathfinderController::reset);

    // Layout de botones
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(bfsButton);
    buttonLayout->addWidget(dijkstraButton);
    buttonLayout->addWidget(astarButton);
    buttonLayout->addWidget(resetButton);

    // Layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addLayout(buttonLayout);

    QWidget *central = new QWidget;
    central->setLayout(mainLayout);
    setCentralWidget(central);
    setWindowTitle("Pathfinding Visualizer");
}
 