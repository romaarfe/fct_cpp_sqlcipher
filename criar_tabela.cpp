#define SQLITE_HAS_CODEC
#define SQLITE_TEMP_STORE 3

#include <iostream>
#include <sqlcipher/sqlite3.h>
#include <string>

using namespace std;

int main()
{
    sqlite3* BD;
    string sql = "CREATE TABLE Heroi("
                  "id INT PRIMARY KEY     NOT NULL, "
                  "nome TEXT    NOT NULL, "
                  "sobrenome    TEXT    NOT NULL);";
    int saida = 0;
    saida = sqlite3_open("projeto_formacao.db", &BD);
    saida = sqlite3_key(BD, "teste123", 8);
    char* mensagem_erro;
    saida = sqlite3_exec(BD, sql.c_str(), NULL, 0, &mensagem_erro);

    if (saida != SQLITE_OK) {
        cerr << "Erro ao criar tabela" << endl;
        sqlite3_free(mensagem_erro);
    }
    else
        cout << "Tabela criada com sucesso!" << endl;
    sqlite3_close(BD);
}
