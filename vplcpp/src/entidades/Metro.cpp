#include "Metro.hpp"

Metro::Metro(int capacidade, float valor_passagem)
    : Trem(capacidade, valor_passagem) {}

Metro::~Metro() {
    std::cout << "Destrutor Metro" << std::endl;
}

bool Metro::pagar_passagem(std::shared_ptr<Passageiro> passageiro) {
    float valor_total = _valor_passagem + 0.40f;
    if (passageiro->_saldo_passagem < valor_total) { 
        return false;
    } else {
        passageiro->descontar_valor_passagem(valor_total);
        return true; 
    }
}


void Metro::desembarcar() {
    std::cout << _passageiros.size() << " passageiros desembarcaram do metro" << std::endl;
    _passageiros.clear();
}
