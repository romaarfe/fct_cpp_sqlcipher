#define SQLITE_HAS_CODEC
#define SQLITE_TEMP_STORE 3

#include <iostream>
#include <sqlcipher/sqlite3.h>
#include <string>

using namespace std;

int main()
{
    sqlite3* BD;
    char* mensagem_erro;
    int saida = sqlite3_open("projeto_formacao.db", &BD);
    saida = sqlite3_key(BD, "teste123", 8);

    string sql("INSERT INTO Heroi VALUES(1, 'Luke', 'Skywalker');"
               "INSERT INTO Heroi VALUES(2, 'Leia', 'Organa');"
               "INSERT INTO Heroi VALUES(3, 'Han', 'Solo');"
               "INSERT INTO Heroi VALUES(4, 'Obiwan', 'Kenobi');");

    saida = sqlite3_exec(BD, sql.c_str(), NULL, 0, &mensagem_erro);
    if (saida != SQLITE_OK) {
        cerr << "Erro ao inserir dados" << endl;
        sqlite3_free(mensagem_erro);
    }
    else
        cout << "Registos criados com sucesso!" << endl;

    sqlite3_close(BD);
}
