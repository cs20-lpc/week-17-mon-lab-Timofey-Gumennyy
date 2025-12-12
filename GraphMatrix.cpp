#include "GraphMatrix.hpp"
#include <algorithm> // Required for std::fill

GraphMatrix::GraphMatrix(int numV, GType type) {
    // TODO
    edgesAmount = 0;
    verticesAmount = numV;
    graphType = type;
    adjMatrix = new bool*[numV];
    for (int i = 0; i < numV; i++) {
        adjMatrix[i] = new bool[numV]();
    }
}

GraphMatrix::~GraphMatrix() {
    // TODO
    for (int i = 0; i < verticesAmount; i++)
        delete[] adjMatrix[i];

    delete[] adjMatrix;
}

bool GraphMatrix::isEdge(int i, int j) const {
    // TODO
    return adjMatrix[i][j];
}

void GraphMatrix::toggleEdge(int i, int j) {
    // TODO
    adjMatrix[i][j] = !adjMatrix[i][j];
    for (int k = 0; k < verticesAmount; k++)
        cout << adjMatrix[i][k] << " ";
    if (graphType == DIRECTED && i == j) return;

    adjMatrix[j][i] = !adjMatrix[j][i];
}

ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < verticesAmount; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < verticesAmount; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < verticesAmount; i++) {
        os << i << " | ";
        for (int j = 0; j < verticesAmount; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

