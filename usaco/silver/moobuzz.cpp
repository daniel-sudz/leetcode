using namespace std;
#include <fstream>

int main() {
    ofstream fout("moobuzz.out");
    ifstream fin("moobuzz.in");

    long long N;
    fin >> N;

    long long low = 0;
    long long med; 
    long long high = 2000000000LL;

    while (true) {
        med = (low + high) / 2;
        long long result = med - (med / 3) - (med / 5) + (med / 15);
        if (result < N) {
            low = med + 1;
        }
        if (result > N) {
            high = med - 1;
        }
        if (result == N) {
            break; 
        }
    }
    while (!(med % 5 != 0LL && med % 3LL != 0)) {
        med--;
    }
    fout << med << endl;
    return 0;
}

