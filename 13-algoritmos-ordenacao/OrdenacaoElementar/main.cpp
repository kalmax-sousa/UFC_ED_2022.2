#include <iostream>
#include <chrono>
using namespace std;

template <typename T>
void bubblesort(T A[], int l, int  r){
    bool trocou = true;
    for (int i = l; i < r && trocou; i++){
        trocou = false;
        for (int j = r; j > i; j--){
            if(A[j] < A[j-1]){
                T aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
                trocou = true;
            }
        }
    }
}

template <typename T>
void insertionsort(T A[], int l, int  r){
    for (int i = l+1; i <= r; i++){
        T key = A[i];
        int j = i-1;
        while(j >= l && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

template <typename T>
void selectionsort(T A[], int l, int  r){
    for (int i = l; i < r-1; i++){
        int indexMin = i;
        for (int j = i+1; j <= r; j++)
            if(A[j] < A[indexMin])
                indexMin = j;
            
        T aux = A[i];
        A[i] = A[indexMin];
        A[indexMin] = aux;
    }
}

template<typename T>
void print(T A[], int l, int r){
    for (int i = l; i <= r; i++){
        cout << A[i] << " ";
    }

    cout << endl;
}

template<typename T>
void time_function(T vec[], int l, int r, string function_name, void(*func_ptr)(T[], int, int)){
    auto start = std::chrono::steady_clock::now();
    func_ptr(vec, l, r);
    auto end = std::chrono::steady_clock::now();
    cout << endl;
    auto elapsed_time = end - start;
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(elapsed_time);
    cout << "time " << function_name << " : " <<  duration.count() << " seconds" << endl;
}

int main(){
    int n = 100000;
    int vec[n], vec2[n], vec3[n];
    for (int i = 0; i < n; i++){
        vec[i] = vec2[i] = vec[3] = rand() % 100;
    }

    time_function(vec, 0, n-1, "bubblesort", bubblesort);
    time_function(vec2, 0, n-1, "insertionsort", insertionsort);
    time_function(vec3, 0, n-1, "selectionsort", selectionsort);

    

    /*
    int vec[] = {3,7,6,5,88,77,12,11};
    int n = sizeof(vec) / sizeof(vec[0]);
    */
}