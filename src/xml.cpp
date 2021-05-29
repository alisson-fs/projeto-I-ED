/**
 * @file xml.cpp
 * @authors Alisson Fabra da Silva e Eduardo Vinicius Betim.
 * @brief Implementação das funções validação e extração de arquivos XML.
 * 
 * @copyright Copyright [2021] <Alisson Fabra da Silva, Eduardo Vinicius Betim>
 */

#include <string>

#include "../include/linked_stack.h"
#include "../include/xml.h"


xml_processing::XML::XML(const std::string& xml_string) {
    xml = xml_string;
}

bool xml_processing::XML::validation() {
    structures::LinkedStack<std::string> tags_stack;
    
    std::size_t position = 0;
    while (position < xml.length()) {
        
        std::size_t char_begin = xml.find("<", position);
        std::size_t char_end = xml.find(">", char_begin);
        
        if (char_begin == std::string::npos) {
            break;
        }
        
        if (char_end == std::string::npos) {
            return false;
        }
    
        std::size_t size = (char_end - char_begin) + 1;
        std::string tag = xml.substr(char_begin, size);
        position = char_end + 1;

        if (tag[1] != '/') {
			tags_stack.push(tag.insert(1, "/"));
		} else if (tags_stack.top() == tag) {
            tags_stack.pop();
        } else {
            return false;
        }
    }
    return tags_stack.empty();
}

std::string xml_processing::XML::extract(const std::string& tag_begin,
                                         const std::string& tag_end,
                                         std::size_t& position) {
    std::size_t begin_position = xml.find(tag_begin, position);
    std::size_t end_position = xml.find(tag_end, begin_position);
    
    if (begin_position == std::string::npos ||
        end_position == std::string::npos) {
        position = std::string::npos;
        return "";
    } else {
        position = end_position + tag_end.length();
        begin_position += tag_begin.length();
        std::size_t size = end_position - begin_position;
        return xml.substr(begin_position, size);
    }
}
