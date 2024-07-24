#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <variant>

using namespace std;

struct Produto {
    string nome;
    double preco;
    double desconto;
    double precoComDesconto() {
        if (desconto > 0) {
            return preco * (1 - desconto);
        } else {
            return preco;
        }
    }
};

struct Usuario {
    int id;
    string nome;
    string email;
    int idade;
    double salario_real;
    bool vip;
    double salario() {
        return salario_real;
    }
};

string ola() {
    return "Olá Mundo!";
}

time_t horaAtual() {
    return time(0);
}

Usuario usuarioLogado() {
    return {1, "Ana da Web", "ana@git.com", 23, 1234.56, true};
}

Produto produtoEmDestaque() {
    return {"Notebook", 4899.99, 0.15};
}

int main() {
    cout << "Executando em http://localhost:4000" << endl;

    // Exemplo de uso das funções
    cout << ola() << endl;
    time_t currentTime = horaAtual();
    cout << "Hora atual: " << ctime(&currentTime) << endl;

    Usuario usuario = usuarioLogado();
    cout << "Usuário logado: " << usuario.nome << ", Salário: " << usuario.salario() << endl;

    Produto produto = produtoEmDestaque();
    cout << "Produto em destaque: " << produto.nome << ", Preço com desconto: " << produto.precoComDesconto() << endl;

    return 0;
}
// Para executar o código, basta compilar e executar o arquivo gerado. Por exemplo, no Linux, você pode usar o seguinte comando:
// g++ index.cxx -o index && ./index