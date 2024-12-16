#include <iostream>
#include <list>
#include <memory>
#include <iomanip>
#include "Passageiro.hpp"
#include "Trem.hpp"
#include "Metro.hpp"
#include "Onibus.hpp"

int main() {
    std::list<std::shared_ptr<Passageiro>> l_passageiro;
    std::unique_ptr<Trem> trem;
    std::unique_ptr<Metro> metro;
    std::unique_ptr<Onibus> onibus;

    std::string comando;
    while (std::cin >> comando) {
        if (comando == "add") {
            std::string nome;
            int idade;
            float saldo;
            std::cin >> nome >> idade >> saldo;
            l_passageiro.push_back(std::make_shared<Passageiro>(nome, idade, saldo));
        }
        if (comando == "trem") {
            int capacidade;
            float valor_passagem;
            std::cin >> capacidade >> valor_passagem;
            trem = std::make_unique<Trem>(capacidade, valor_passagem);

            for (auto& p : l_passageiro) {
                if (!trem->pagar_passagem(p)) { 
                    std::cout << "Saldo insuficiente:\n";
                    std::cout << "nome: " << p->_nome << "\n";
                    std::cout << std::fixed << std::setprecision(2) << "saldo: R$ " << p->_saldo_passagem << "\n";
                }
                else {
                    trem->embarcar(p);
                }
            }
            trem->mover();
            trem->desembarcar();
        }
        if (comando == "metro") {
            int capacidade;
            float valor_passagem;
            std::cin >> capacidade >> valor_passagem;
            metro = std::make_unique<Metro>(capacidade, valor_passagem);

            for (auto& p : l_passageiro) {
                if (!metro->pagar_passagem(p)) {  
                    std::cout << "Saldo insuficiente:\n";
                    std::cout << "nome: " << p->_nome << "\n";
                    std::cout << std::fixed << std::setprecision(2) << "saldo: R$ " << p->_saldo_passagem << "\n";
                }
                else {
                    metro->embarcar(p);
                }
            }
            metro->mover();
            metro->desembarcar();
        }

        if (comando == "onibus") {
            int capacidade;
            float valor_passagem;
            std::cin >> capacidade >> valor_passagem;
            onibus = std::make_unique<Onibus>(capacidade, valor_passagem);

            for (auto& p : l_passageiro) {
                if (p->_idade >= 65) { 
                    std::cout << "Passagem gratuita:" << p->_nome << "\n";
                    onibus->embarcar(p);
                }
                else if (!onibus->pagar_passagem(p)) { 
                    std::cout << "Saldo insuficiente:\n";
                    std::cout << "nome: " << p->_nome << "\n";
                    std::cout << std::fixed << std::setprecision(2) << "saldo: R$ " << p->_saldo_passagem << "\n";
                }
                else {
                    onibus->embarcar(p);
                }
            }
            onibus->mover();
            onibus->desembarcar();
        }
        
        else if (comando == "sair") {
            std::cout << "" << std::endl;
            break;
        }
    }
    return 0;
}
