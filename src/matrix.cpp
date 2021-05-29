/**
 * @file matrix.cpp
 * @authors Alisson Fabra da Silva e Eduardo Vinicius Betim.
 * @brief Implementação da classe Matrix.
 * 
 * @copyright Copyright [2021] <Alisson Fabra da Silva, Eduardo Vinicius Betim>
 */

#include <utility>

#include "../include/linked_queue.h"
#include "../include/matrix.h"


xml_processing::Matrix::Matrix(int n_lines, int n_columns) {
    lines = n_lines;
    columns = n_columns;
    M = new int*[lines];
    for (int i = 0; i < lines; i++) {
        M[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            M[i][j] = 0;
        }
    }
}

xml_processing::Matrix::~Matrix() {
    for (int i = 0; i < lines; i++) {
        delete[] M[i];
    }
    delete[] M;
}

int xml_processing::Matrix::count_connected() {
    using pixel = std::pair<int, int>;
    structures::LinkedQueue<pixel> queue_pixels;
    Matrix R = Matrix(lines, columns);
    int label = 1;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (!R.get_value(i, j) && M[i][j]) {
                R.set_value(i, j, label);
                queue_pixels.enqueue({i, j});
                while (!queue_pixels.empty()) {
                    const pixel pixel = queue_pixels.dequeue();
                    const int x = pixel.first;
                    const int y = pixel.second;
                    
                    if (x - 1 >= 0 && !R.get_value(x-1, y) && M[x-1][y]) {
                        R.set_value(x-1, y, label);
                        queue_pixels.enqueue({x-1, y});
                    }
                    
                    if (x + 1 < lines && !R.get_value(x+1, y) && M[x+1][y]) {
                        R.set_value(x+1, y, label);
                        queue_pixels.enqueue({x+1, y});
                    }
                    
                    if (y - 1 >= 0 && !R.get_value(x, y-1) && M[x][y-1]) {
                        R.set_value(x, y-1, label);
                        queue_pixels.enqueue({x, y-1});
                    }
                    
                    if (y + 1 < columns && !R.get_value(x, y+1) && M[x][y+1]) {
                        R.set_value(x, y+1, label);
                        queue_pixels.enqueue({x, y+1});
                    }
                }
                label++;
            }
        }
    }
    return label - 1;
}

int xml_processing::Matrix::get_value(int line, int column) {
    return M[line][column];
}

void xml_processing::Matrix::set_value(int line, int column, int value) {
    M[line][column] = value;
}
