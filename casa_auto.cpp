#include <iostream>
#include <string>
using namespace std;

class SensorNivel {
private:
    float nivelMin;
    float nivelMax;

public:
    string id;

    SensorNivel(string idSensor) {
        id = idSensor;
        nivelMin = 0;
        nivelMax = 100;
    }

    SensorNivel(string idSensor, float min, float max) {
        id = idSensor;
        if (min < max) {
            nivelMin = min;
            nivelMax = max;
        } else {
            nivelMin = 0;
            nivelMax = 100;
        }
    }

    void exibirResumo() {
        cout << "SensorNivel [" << id << "] - Faixa: "
             << nivelMin << " a " << nivelMax << endl;
    }
};

class Bomba {
private:
    int velocidade;

public:
    string modelo;

    Bomba(string m) {
        modelo = m;
        velocidade = 0;
    }

    Bomba(string m, int vel) {
        modelo = m;
        if (vel >= 0 && vel <= 100) {
            velocidade = vel;
        } else {
            velocidade = 0;
        }
    }

    void exibirResumo() {
        cout << "Bomba [" << modelo << "] - Velocidade: "
             << velocidade << "%" << endl;
    }
};

class ControladorTanque {
private:
    float ganho;

public:
    string nome;

    ControladorTanque(string n) {
        nome = n;
        ganho = 1.0;
    }

    ControladorTanque(string n, float g) {
        nome = n;
        if (g > 0) {
            ganho = g;
        } else {
            ganho = 1.0;
        }
    }

    void exibirResumo() {
        cout << "Controlador [" << nome << "] - Ganho: "
             << ganho << endl;
    }
};

int main() {

    SensorNivel s1("S1");
    SensorNivel s2("S2", 10, 80);

    Bomba b1("B1");
    Bomba b2("B2", 75);

    ControladorTanque c1("C1");
    ControladorTanque c2("C2", 2.5);

    cout << "\n=== RESUMO DOS OBJETOS ===\n" << endl;

    s1.exibirResumo();
    s2.exibirResumo();

    b1.exibirResumo();
    b2.exibirResumo();

    c1.exibirResumo();
    c2.exibirResumo();

    return 0;
}