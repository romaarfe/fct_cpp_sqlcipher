// Define o uso da biblioteca SQLCipher para criptografia.
#define SQLITE_HAS_CODEC

// Define o modo de armazenamento temporário no banco de dados como arquivo temporário.
#define SQLITE_TEMP_STORE 3

#include <iostream> // Inclusão da biblioteca de entrada/saída padrão.
#include <string> // Inclusão da biblioteca de strings de C++.
#include <sqlcipher/sqlite3.h> // Inclusão da biblioteca SQLCipher para SQLite com criptografia.

// Permite o uso de funções e objetos da biblioteca padrão sem o prefixo "std::".
using namespace std;

// Função principal do programa.
int main()
{
    // Ponteiro para um objeto que representa o banco de dados SQLite.
    sqlite3* BD;

    // Variável para armazenar o resultado das operações SQLite.
    int saida = 0;

    // Abre o banco de dados "projeto_formacao.db" e armazena o resultado em "saida".
    saida = sqlite3_open("projeto_formacao.db", &BD);

    // Define a chave de criptografia para o banco de dados "BD" com a chave "teste123" (8 caracteres).
    saida = sqlite3_key(BD, "teste123", 8);

    // Verifica se houve erro na criação do banco de dados.
    if (saida) {
        // Imprime a mensagem de erro.
        cerr << "Erro ao criar base de dados!" << sqlite3_errmsg(BD) << endl;
        // Retorna -1 para indicar que houve um erro.
        return (-1);
    }
    else {
        // Imprime uma mensagem de sucesso.
        cout << "Base de dados criada com sucesso!" << endl;
    }

    // Fecha o banco de dados para liberar os recursos.
    sqlite3_close(BD);
}
