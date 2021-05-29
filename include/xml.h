/**
 * @file xml.h
 * @authors Alisson Fabra da Silva e Eduardo Vinicius Betim.
 * @brief Declaração das funções validação e extração de conteúdo de arquivos xml.
 * 
 * @copyright Copyright [2021] <Alisson Fabra da Silva, Eduardo Vinicius Betim>
 */

#ifndef XML_H
#define XML_H

#include <string>
#include <cstddef>

/// Código para processamento de xml.
namespace xml_processing {

/// Xml
class XML {
 public:

    /**
     * @brief Construtor.
     * 
     * Recebe o arquivo xml no formado string para ser utilizado no restante
     * dos metodos.
     * 
     * @param xml Arquivo xml no formado string.
     */
    XML(const std::string& xml_string);
    
    /**
     * @brief Faz a validação do arquivo xml passado.
     * 
     * A validação verifica se todas as tags abriram e fecharam corretamente. É
     * utilizado uma pilha encadeada auxiliar neste processo.
     * 
     * @return True se o arquivo for válido e false se for inválido.
     */
    bool validation();
    
    /**
     * @brief Faz a extração do conteúdo entre as tags.
     * 
     * A extração copia o conteúdo entre as tags que estão a partir da posição
     * passada para iniciar a busca no xml em formato de string.
     * 
     * @param tag_begin Indicador de abertura de uma tag.
     * @param tag_end Indicador de fechamento de uma tag.
     * @param position Posição inicial de busca no xml em formato string.
     * 
     * @return String com o conteúdo entre as tags.
     */
    std::string extract(const std::string& tag_begin,
                    const std::string& tag_end,
                    std::size_t& position);

 private:

    /// Xml no formato string.
    std::string xml;
};

}  // namespace xml

#endif  // XML_H
