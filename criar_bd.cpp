#define SQLITE_HAS_CODEC
#define SQLITE_TEMP_STORE 3

#include <iostream>
#include <string>
#include <sqlcipher/sqlite3.h>

using namespace std;

int main()
{
    sqlite3* BD;
    int saida = 0;
    saida = sqlite3_open("projeto_formacao.db", &BD);

    saida = sqlite3_key(BD, "teste123", 8);

    if (saida) {
        cerr << "Erro ao criar base de dados!" << sqlite3_errmsg(BD) << endl;
        return (-1);
    }
    else
        cout << "Base de dados criada com sucesso!" << endl;

    sqlite3_close(BD);
}
