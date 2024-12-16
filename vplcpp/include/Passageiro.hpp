#define PASSAGEIRO_HPP
#include <string>

class Passageiro {
public:
    std::string _nome;
    int _idade;
    float _saldo_passagem;

    Passageiro(std::string nome, int idade, float saldo_passagem);
    void descontar_valor_passagem(float valor);
};

