#include "Passageiro.hpp"

Passageiro::Passageiro(std::string nome, int idade, float saldo_passagem)
    : _nome(nome), _idade(idade), _saldo_passagem(saldo_passagem) {}

void Passageiro::descontar_valor_passagem(float valor) {
    _saldo_passagem = _saldo_passagem - valor;
}
