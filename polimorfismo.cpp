#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AtuadorLinha {
protected:
    string nome;

public:
    AtuadorLinha(string n) : nome(n) {}

    virtual void aplicarReferenciaPercentual(double ref) = 0;
    virtual void exibirResumo() = 0;

    virtual ~AtuadorLinha() {}
};

class MotorEsteira : public AtuadorLinha {
private:
    double velocidade;

public:
    MotorEsteira(string n) : AtuadorLinha(n), velocidade(0) {}

    void aplicarReferenciaPercentual(double ref) override {
        velocidade = ref * 10;
    }

    void exibirResumo() override {
        cout << "MotorEsteira [" << nome << "] - Velocidade: "
             << velocidade << " rpm" << endl;
    }
};

class ValvulaDosagem : public AtuadorLinha {
private:
    double vazao;

public:
    ValvulaDosagem(string n) : AtuadorLinha(n), vazao(0) {}

    void aplicarReferenciaPercentual(double ref) override {
        vazao = ref * 0.5;
    }

    void exibirResumo() override {
        cout << "ValvulaDosagem [" << nome << "] - Vazao: "
             << vazao << " L/min" << endl;
    }
};

int main() {
    vector<AtuadorLinha*> linha;

    linha.push_back(new MotorEsteira("Esteira 1"));
    linha.push_back(new ValvulaDosagem("Valvula A"));
    linha.push_back(new MotorEsteira("Esteira 2"));

    double comando = 50;

    for (auto atuador : linha) {
        atuador->aplicarReferenciaPercentual(comando);
    }

    cout << "Resumo dos equipamentos:\n";

    for (auto atuador : linha) {
        atuador->exibirResumo();
    }

    for (auto atuador : linha) {
        delete atuador;
    }

    return 0;
}