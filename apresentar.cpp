#define SQLITE_HAS_CODEC
#define SQLITE_TEMP_STORE 3

#include <iostream>
#include <sqlcipher/sqlite3.h>
#include <string>

using namespace std;

static int imprimir(void* dados, int qt, char** linha, char** coluna)
{
    int i;
    cout << (const char*)dados << ": " << endl;

    for (i = 0; i < qt; i++) {
        cout << coluna[i] << " = " << linha[i] << endl;
    }

    cout << endl;
    return 0;
}

int main()
{
    sqlite3* BD;
    int saida = 0;
    saida = sqlite3_open("projeto_formacao.db", &BD);
    saida = sqlite3_key(BD, "teste123", 8);
    string dados("Função Imprimir");

    string sql("SELECT * FROM Heroi;");
    if (saida) {
        cerr << "Erro ao aceder base de dados " << sqlite3_errmsg(BD) << endl;
        return (-1);
    }
    else
        cout << "Operação realizada com sucesso!" << endl << endl;

    int retorno = sqlite3_exec(BD, sql.c_str(), imprimir, (void*)dados.c_str(), NULL);

    if (retorno != SQLITE_OK)
        cerr << "Erro ao retornar" << endl;
    else {
        cout << "Retorno com sucesso!" << endl;
    }

    sqlite3_close(BD);

}
