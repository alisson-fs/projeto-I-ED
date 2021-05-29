/**
 * @file linked_queue.h
 * @authors Alisson Fabra da Silva e Eduardo Vinicius Betim.
 * @brief Código da fila encadeada.
 * 
 * @copyright Copyright [2021] <Alisson Fabra da Silva, Eduardo Vinicius Betim>
 */

#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <cstdint>
#include <stdexcept>

/// Estruturas de dados.
namespace structures {

/// Fila Encadeada.
template<typename T>
class LinkedQueue {
 public:
    /// Construtor padrão.
    LinkedQueue();
    /// Destrutor.
    ~LinkedQueue();
    /// Limpa fila.
    void clear();
    /// Enfilerar.
    void enqueue(const T& data);
    /// Desenfilerar.
    T dequeue();
    /// Primeiro dado da fila.
    T& front() const;
    /// Último dado da fila.
    T& back() const;
    /// Verifica se a fila está vazia.
    bool empty() const;
    /// Tamanho da fila.
    std::size_t size() const;

 private:
    /// Elemento da Fila Encadeada.
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}
        /// Getter: dado.
        T& data() {
            return data_;
        }
        /// Getter const: dado.
        const T& data() const {
            return data_;
        }
        /// Getter: próximo.
        Node* next() {
            return next_;
        }
        /// Getter const: próximo.
        const Node* next() const {
            return next_;
        }
        /// Setter: próximo.
        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };
    /// Primeiro Elemento da fila.
    Node* head;
    /// Último Elemento da fila.
    Node* tail;
    /// Tamanho da fila.
    std::size_t size_;
};

}  // namespace structures

#endif

template<typename T>
structures::LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

template<typename T>
structures::LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template<typename T>
void structures::LinkedQueue<T>::clear() {
    while (size_ > 0) {
        dequeue();
    }
}

template<typename T>
void structures::LinkedQueue<T>::enqueue(const T& data) {
    Node *new_value = new Node(data, tail);
    if (new_value == nullptr) {
        throw std::out_of_range("Fila cheia.");
    }
    if (empty()) {
        head = new_value;
    } else {
        tail->next(new_value);
    }
    tail = new_value;
    size_++;
}

template<typename T>
T structures::LinkedQueue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Fila vazia.");
    } else {
        Node *eliminate = head;
        T info_back = eliminate->data();
        head = eliminate->next();
        size_--;
        delete eliminate;
        return info_back;
    }
}

template<typename T>
T& structures::LinkedQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Fila vazia.");
    } else {
        return head->data();
    }
}

template<typename T>
T& structures::LinkedQueue<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Fila vazia.");
    } else {
        return tail->data();
    }
}

template<typename T>
bool structures::LinkedQueue<T>::empty() const {
    return (size_ == 0);
}

template<typename T>
std::size_t structures::LinkedQueue<T>::size() const {
    return size_;
}
