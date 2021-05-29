/**
 * @file matrix.h
 * @authors Alisson Fabra da Silva e Eduardo Vinicius Betim.
 * @brief Declaração da classe Matrix.
 * 
 * @copyright Copyright [2021] <Alisson Fabra da Silva, Eduardo Vinicius Betim>
 */

#ifndef MATRIX_H
#define MATRIX_H

/// Código para processamento de xml.
namespace xml_processing {

/// Matriz
class Matrix {
 public:
    /**
     * @brief Constroi uma matriz.
     * 
     * Constroi uma matriz do tipo ponteiro para ponteiro de inteiros. Esta matriz
     * será nula, ou seja, todos os elementos são zero.
     * 
     * @param n_lines Número de linhas da matriz.
     * @param n_columns Número de colunas da matriz.
     */
    Matrix(int n_lines, int n_columns);
        
    /**
     * @brief Destrói a matriz.
     * 
     * Libera todo o espaço de memória ocupado pela matriz.
     */
    ~Matrix();

    /**
     * @brief Conta componentes conexos na matriz.
     * 
     * 
     * A matriz neste caso é uma imagem binária. Cada pixel conexo
     * encontrado na matriz é rotulado com um valor inteiro e enfileirado
     * utilizando uma fila encadeada. Utilizamos vizinhança-4 para o calculo de componentes conexos. A
     * vizinhança-4 de um pixel são os pixels que estão em cima, em baixo,
     * na direita e na esquerda. 
     * 
     * @return Inteiro com o número de componentes conexos na matriz.
     */
    int count_connected();

    /**
     * @brief Pega uma posição da matriz.
	 * 
	 * @param line Linha onde será definido o valor.
	 * @param column Coluna onde será definido o valor.
	 * 
	 * @return Inteiro que está na posição passada.
     */
	int get_value(int line, int column);
	
	/**
     * @brief Coloca um inteiro na posição passada
	 * 
	 * @param line Linha onde será definido o valor.
	 * @param column Coluna onde será definido o valor.
	 * @param value Valor que será colocado na matriz.
     */
	void set_value(int line, int column, int value);

 private:
    /// Matriz.
    int** M;
    /// Número de linhas.
    int lines;
    /// Número de colunas.
    int columns;
};

}  // namespace image

#endif  // MATRIX_H
