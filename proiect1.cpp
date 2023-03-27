#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
int main() {

    int n, m, q, f, delta[100][100], final[100], sol[100];
    char s[100];
    fin >> n >> m; // nr de stari si nr de simboluri
    for (int i = 0; i < m; i++)
        fin >> s[i]; // simbolurile
    fin >> f; // nr de stari finale
    for (int i = 0; i < f; i++) {
        int x;
        fin >> x;
        final[i] = x; // vector cu stari finale
    }
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            delta[i][j] = -1;

    fin >> q; // nr de tranzitii
    for (int i = 0; i < q; i++)
    {
        int x, y;
        char c;
        fin >> x >> c >> y;
        delta[x][c - 'a'] = y;
    }

    string cuv;
    fin >> cuv;

    fin.close();

    int stareActuala = 0;
    int k = 0;

    for (int i = 0; i < cuv.length(); i++)
    {
        stareActuala = delta[stareActuala][cuv[i] - 'a'];
        if (stareActuala == -1)
        {
            cout << "nu este acceptat";
            return 0;
        }
        else sol[k++] = stareActuala;
    }

    bool verif = false;
    for (int i = 0; i < f; i++)
    {
        if (stareActuala == final[i]) {
            verif = true;
            break;
        }
    }

    if (verif)
    {
        cout << "Cuvantul este acceptat!" << endl;

        for (int i = 0; i < k - 1; i++) {
            cout << "q" << sol[i] << " -> ";
        }
        cout << "q" << sol[k - 1];
    }
    else
    {
        cout << "Cuvantul nu este acceptat!" << endl;
    }
    cout << ' ';

    return 0;
}
