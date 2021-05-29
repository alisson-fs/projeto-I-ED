/**
 * @file main.cpp
 * @authors Alisson Fabra da Silva e Eduardo Vinicius Betim.
 * @brief Código principal.
 * 
 * @copyright Copyright [2021] <Alisson Fabra da Silva, Eduardo Vinicius Betim>
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#include "./include/xml.h"
#include "./include/matrix.h"

using namespace std;
using namespace xml_processing;

/**
 * @brief Função main, ponto de partida para a execução do programa.
 * 
 * Recebe um arquivo xml com uma imagem binária no input, valida o arquivo e
 * caso seja válido processa o imagem.
 * 
 * @return Retona 0 caso não ocorra erro, -1 caso o xml não abra, -2 caso o xml
 * seja inválido e -3 caso a imagem do xml tenha dimensão inválida.
 */
int main() {
    char xmlfilename[100];
    std::cin >> xmlfilename;
    ifstream file(xmlfilename);

    std::string xml_string;
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            xml_string += line;
        }
        file.close();
    } else {
        cout << "error\n";
        return -1;
    }

    XML xml = XML(xml_string);
    if (xml.validation()) {
        size_t position = 0;
        while (position < xml_string.length()) {
            const std::string img_string = xml.extract("<img>", "</img>", position);
            if (position == std::string::npos) {
                break;
            }

            std::size_t zero = 0;
            XML img = XML(img_string);
            const std::string name = img.extract("<name>", "</name>", zero);
            const int height = stoi(img.extract("<height>", "</height>", zero));
            const int width = stoi(img.extract("<width>", "</width>", zero));
            if (height <= 0 || width <= 0) {
                cout << "error\n";
                return -3;
            }

            const std::string data = img.extract("<data>", "</data>", zero);

            Matrix image = Matrix(height, width);
            int i = 0;
            int j = 0;
            for (const char& c : data) {
                if (std::isspace(c)) {
                    continue;
                }
                
                image.set_value(i, j, c - '0');

                if (++j >= width) {
                    j = 0;
                    if (++i >= height) {
                        break;
                    }
                }
            }
            cout << name << " " << image.count_connected() << "\n";
        }
    } else {
        cout << "error\n";
        return -2;
    } 
    return 0;
}
