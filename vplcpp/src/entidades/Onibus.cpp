#include "Onibus.hpp"

Onibus::Onibus(int capacidade, float valor_passagem)
    : Transporte(capacidade, valor_passagem) {}

Onibus::~Onibus() {
    std::cout << "Destrutor Onibus" << std::endl;
}

bool Onibus::pagar_passagem(std::shared_ptr<Passageiro> passageiro) {
    float _valor_passagem;
    if (passageiro->_saldo_passagem < _valor_passagem) { 
        return false;
    } else {
        passageiro->descontar_valor_passagem(_valor_passagem);
        return true; 
    }
}

void Onibus::mover() {
    float ocupacao = (((float)_passageiros.size())-1 / _capacidade) * 100;
    std::cout << "Onibus deslocando com " << ocupacao << "% da capacidade" << std::endl;
}

void Onibus::embarcar(std::shared_ptr<Passageiro> passageiro) {
    if (pagar_passagem(passageiro)) {
        passageiro= passageiro +1;
    }
}

void Onibus::desembarcar() {
    std::cout << _passageiros.size() << " passageiros desembarcaram do onibus" << std::endl;
    _passageiros.clear();
}
