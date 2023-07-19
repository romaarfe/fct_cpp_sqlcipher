// Define o uso da biblioteca SQLCipher para criptografia.
#define SQLITE_HAS_CODEC

// Define o modo de armazenamento temporário na base de dados como arquivo temporário.
#define SQLITE_TEMP_STORE 3

#include <iostream> // Inclusão da biblioteca de entrada/saída padrão.
#include <sqlcipher/sqlite3.h> // Inclusão da biblioteca SQLCipher para SQLite com criptografia.
#include <string> // Inclusão da biblioteca de strings de C++.

// Permite o uso de funções e objetos da biblioteca padrão sem o prefixo "std::".
using namespace std;

int main()
{
    // Ponteiro para um objeto que representa a base de dados SQLite.
    sqlite3* BD;

    // Ponteiro para armazenar mensagens de erro.
    char* mensagem_erro;

    // Abre a base de dados e armazena o resultado em "saida".
    int saida = sqlite3_open("projeto_formacao.db", &BD);

    // Define a chave de criptografia para a base de dados "BD" com a chave "teste123" (8 caracteres).
    saida = sqlite3_key(BD, "teste123", 8);

    // Declaração da consulta SQL para inserir registros.
    string sql("INSERT INTO Heroi VALUES(1, 'Luke', 'Skywalker');"
               "INSERT INTO Heroi VALUES(2, 'Leia', 'Organa');"
               "INSERT INTO Heroi VALUES(3, 'Han', 'Solo');"
               "INSERT INTO Heroi VALUES(4, 'Obiwan', 'Kenobi');");

    // Executa a consulta SQL para inserir registros na tabela "Heroi" da base de dados "BD" e armazena o resultado em "saida".
    saida = sqlite3_exec(BD, sql.c_str(), NULL, 0, &mensagem_erro);

    // Verifica se houve erro na execução da consulta.
    if (saida != SQLITE_OK) {
        // Imprime uma mensagem de erro.
        cerr << "Erro ao inserir dados" << endl;
        // Libera a memória alocada para a mensagem de erro.
        sqlite3_free(mensagem_erro);
    }
    else
        // Imprime uma mensagem de sucesso.
        cout << "Registos criados com sucesso!" << endl;

    // Fecha o banco de dados para liberar os recursos.
    sqlite3_close(BD);
}
