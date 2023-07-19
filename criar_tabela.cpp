// Define o uso da biblioteca SQLCipher para criptografia.
#define SQLITE_HAS_CODEC

// Define o modo de armazenamento temporário no banco de dados como arquivo temporário.
#define SQLITE_TEMP_STORE 3

#include <iostream> // Inclusão da biblioteca de entrada/saída padrão.
#include <sqlcipher/sqlite3.h> // Inclusão da biblioteca SQLCipher para SQLite com criptografia.
#include <string> // Inclusão da biblioteca de strings de C++.

// Permite o uso de funções e objetos da biblioteca padrão sem o prefixo "std::".
using namespace std;

int main()
{
    // Ponteiro para um objeto que representa o banco de dados SQLite.
    sqlite3* BD;

    // Declaração da consulta SQL para criar a tabela.
    string sql = "CREATE TABLE Heroi("
                  "id INT PRIMARY KEY     NOT NULL, "
                  "nome TEXT    NOT NULL, "
                  "sobrenome    TEXT    NOT NULL);";

    // Variável para armazenar o resultado das operações SQLite.
    int saida = 0;

    // Abre a base de dados "projeto_formacao.db" e armazena o resultado em "saida".
    saida = sqlite3_open("projeto_formacao.db", &BD);

    // Define a chave de criptografia para a base de dados "BD" com a chave "teste123" (8 caracteres).
    saida = sqlite3_key(BD, "teste123", 8);

    // Ponteiro para armazenar mensagens de erro.
    char* mensagem_erro;

    // Executa a consulta SQL para criar a tabela na base de dados "BD" e armazena o resultado em "saida".
    saida = sqlite3_exec(BD, sql.c_str(), NULL, 0, &mensagem_erro);

    // Verifica se houve erro na execução da consulta.
    if (saida != SQLITE_OK) {
        // Imprime uma mensagem de erro.
        cerr << "Erro ao criar tabela" << endl;
        // Libera a memória alocada para a mensagem de erro.
        sqlite3_free(mensagem_erro);
    }
    else
        // Imprime uma mensagem de sucesso.
        cout << "Tabela criada com sucesso!" << endl;

     // Fecha a base de dados para liberar os recursos.
    sqlite3_close(BD);
}
