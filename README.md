# 🧠 AlgVisuales - Visualizador de Algoritmos de Búsqueda

**AlgVisuales** es una herramienta interactiva para la visualización de algoritmos de búsqueda como **BFS**, **Dijkstra** y **A\***. Desarrollada en **C++** con **Qt5**, esta aplicación permite experimentar con estos algoritmos de manera visual e intuitiva sobre una cuadrícula personalizable.

---

## 🚀 Características

- Visualización en tiempo real de:
  - Breadth First Search (BFS)
  - Dijkstra
  - A* (con heurística de Manhattan)
- Interfaz gráfica amigable con Qt5.
- Cuadrícula interactiva con obstáculos y celdas personalizables.
- Selección visual de nodo inicial y final.
- Código modular y mantenible.
- Compilación con CMake.
- Script `setup.sh` para facilitar la instalación de dependencias.

---

## 📁 Estructura del proyecto

```plaintext
AlgVisuales/
├── include/ # Cabeceras de clases
│ ├── gridcell.h
│ ├── graphalgorithms.h
│ ├── mainwindow.h
│ └── pathfinder.h
├── src/ # Código fuente
│ ├── gridcell.cpp
│ ├── graphalgorithms.cpp
│ ├── main.cpp
│ ├── mainwindow.cpp
│ └── pathfinder.cpp
├── build/ # Directorio de compilación (generado con CMake)
├── setup.sh # Instalador de dependencias para Ubuntu
├── Compilar.sh 
├── CompilarYEjecutar.sh 
├── EjecutarPrograma.sh 
├── MakeClean.sh # Limpiar directorio de compilación
├── CMakeLists.txt # Configuración de CMake
└── README.md # Este archivo

```



---

## ⚙️ Requisitos

Antes de compilar, asegúrate de tener:

- `g++` con soporte para C++17
- `cmake`
- `make`
- Qt5: `qtbase5-dev`, `qt5-qmake`, `qtbase5-dev-tools`
- `build-essential`

---

## 🛠️ Instalación

### Opción 1: Script automático

```bash
chmod +x setup.sh
./setup.sh
```
### Opción 2: Manual

```bash
sudo apt update
sudo apt install -y build-essential cmake qtbase5-dev qt5-qmake qtbase5-dev-tools

```
## 🛠️ Compilación
```bash
mkdir build
cd build
cmake ..
make
```

## ▶️ Ejecución
```bash
./PathfindingVisualizer
```


## 👨‍💻 Autor

Jesús Losada Arauzo
Estudiante de Ingeniería Informática
Universidad de Granada – ETSIIT



