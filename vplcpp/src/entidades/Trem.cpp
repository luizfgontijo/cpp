#include "Trem.hpp"

Trem::Trem(int capacidade, float valor_passagem)
    : Transporte(capacidade, valor_passagem) {}

Trem::~Trem() {
    std::cout << "Destrutor Trem" << std::endl;
}

bool Trem::pagar_passagem(std::shared_ptr<Passageiro> passageiro) {
    float _valor_passagem;
    if (passageiro->_saldo_passagem < _valor_passagem) { 
        return false;
    } else {
        passageiro->descontar_valor_passagem(_valor_passagem);
        return true; 
    }
}

void Trem::mover() {
    float ocupacao = ((float)_passageiros.size() / _capacidade) * 100;
    std::cout << "Trem deslocando com " << ocupacao << "% da capacidade" << std::endl;
}

void Trem::embarcar(std::shared_ptr<Passageiro> passageiro) {
    if (pagar_passagem(passageiro)) {
        _passageiros.push_back(passageiro);
    }
}

void Trem::desembarcar() {
    std::cout << _passageiros.size() << " passageiros desembarcaram do trem" << std::endl;
    _passageiros.clear();
}
