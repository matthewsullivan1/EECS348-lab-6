#include <iostream>
#include <fstream>
#include <vector>

const int MAX_SIZE = 100;

using namespace std;

void display(const vector<vector<int>>& matrix);
void add(const vector<vector<int>>& a, const vector<vector<int>>& b);
void mult(const vector<vector<int>>& a, const vector<vector<int>>& b);
void sub(const vector<vector<int>>& a, const vector<vector<int>>& b);

int main() {
    ifstream file("matrix_input.txt");
    int n;
    file >> n;

    if (n <= 0 || n > MAX_SIZE) {
        return 1;
    }

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> a[i][j];
        }
    }

    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> b[i][j];
        }
    }
    file.close();

    cout << "Matthew Sullivan\nLab #6: Matrix Manipulation\n";
    cout << "\nMatrix A:";
    display(a);
    cout << "\nMatrix B:";
    display(b);
    cout << "\nMatrix Sum (A + B):";
    add(a,b);
    cout << "\nMatrix Product (A * B):";
    mult(a,b);
    cout << "\nMatrix Difference (A - B):";
    sub(a,b);

    return 0;
}

void display(const vector<vector<int>>& matrix){
    int n = matrix.size();
    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void add(const vector<vector<int>>& a, const vector<vector<int>>& b){
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    display(c);
}

void mult(const vector<vector<int>>& a, const vector<vector<int>>& b){
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    display(c);
}

void sub(const vector<vector<int>>& a, const vector<vector<int>>& b){
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    display(c);
}

