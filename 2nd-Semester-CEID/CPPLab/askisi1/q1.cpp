#include<iostream>
using namespace std;

int el(){
    int N;

    cout << "Enter the number of dimensions: ";
    cin >> N;

    int** first = new int*[N];
    int** second = new int*[N];
    for (int i = 0; i < N; i++){
        first[i] = new int[N];
        second[i] = new int[N];
    }

    cout << "First set of numbers: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> first[i][j];
        }
    }

    cout << "Enter the elements of the second matrix: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> second[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            first[i][j] = first[i][j] + second[i][j];
        }
    }
    cout << "The resulting matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << first[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] first[i];
        delete[] second[i];
    }
    delete[] first;
    delete[] second;

    return 0;
}
