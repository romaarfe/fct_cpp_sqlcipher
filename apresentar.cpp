// Define o uso da biblioteca SQLCipher para criptografia.
#define SQLITE_HAS_CODEC

// Define o modo de armazenamento temporário na base de dados como ficheiro temporário.
#define SQLITE_TEMP_STORE 3

#include <iostream> // Inclusão da biblioteca de entrada/saída padrão.
#include <sqlcipher/sqlite3.h> // Inclusão da biblioteca SQLCipher para SQLite com criptografia.
#include <string> // Inclusão da biblioteca de strings de C++.

// Permite o uso de funções e objetos da biblioteca padrão sem o prefixo "std::".
using namespace std;

// Função de callback para imprimir os resultados de uma consulta.
static int imprimir(void* dados, int qt, char** linha, char** coluna)
{
    int i;

    // Imprime a string passada através do parâmetro "dados".
    cout << (const char*)dados << ": " << endl;

    for (i = 0; i < qt; i++) {

        // Imprime o nome da coluna e o valor da linha correspondente.
        cout << coluna[i] << " = " << linha[i] << endl;
    }

    // Imprime uma linha em branco para separar os resultados.
    cout << endl;

    // Retorna 0 para indicar que a operação foi bem-sucedida.
    return 0;
}

// Função principal do programa.
int main()
{
    // Ponteiro para um objeto que representa a base de dados SQLite/SQLCipher.
    sqlite3* BD;

    // Variável para armazenar o resultado das operações SQLite/SQLCipher.
    int saida = 0;

    // Abre a base de dados "projeto_formacao.db" e armazena o resultado em "saida".
    saida = sqlite3_open("projeto_formacao.db", &BD);

    // Define a chave de criptografia para a base de dados "BD" com a chave "teste123" (8 caracteres).
    saida = sqlite3_key(BD, "teste123", 8);

    // Cria uma string de C++ chamada "dados" com o valor "Função Imprimir".
    string dados("Função Imprimir");

    // Define uma string SQL com a consulta a ser executada.
    string sql("SELECT * FROM Heroi;");

    // Verifica se houve erro na abertura da base de dados.
    if (saida) {

        // Imprime a mensagem de erro.
        cerr << "Erro ao aceder base de dados " << sqlite3_errmsg(BD) << endl;

        // Retorna -1 para indicar que houve um erro.
        return (-1);
    }
    else
        // Imprime uma mensagem de sucesso.
        cout << "Operação realizada com sucesso!" << endl << endl;

    // Executa a consulta SQL no banco de dados "BD" e passa a função de callback "imprimir" para tratar os resultados.
    int retorno = sqlite3_exec(BD, sql.c_str(), imprimir, (void*)dados.c_str(), NULL);

    // Verifica se houve erro na execução da consulta.
    if (retorno != SQLITE_OK){
        // Imprime uma mensagem de erro.
        cerr << "Erro ao retornar" << endl;
    }
    else {
        // Imprime uma mensagem de sucesso.
        cout << "Retorno com sucesso!" << endl;
    }

    // Fecha o banco de dados para liberar os recursos.
    sqlite3_close(BD);

}
