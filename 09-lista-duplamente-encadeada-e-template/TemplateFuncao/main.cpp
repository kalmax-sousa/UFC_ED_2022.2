#include <iostream>
#include <vector>
using namespace std;

namespace ufc{
    template< typename T>
    T max(T x, T y) {
        return (x >= y) ? x : y;
    }

    template< typename T>
    void print(vector<T>& vec){
        for(T& element : vec)
            cout << element << " ";
        cout << endl;
        
    }
}

int main(){
    cout << ufc::max(4, 7) << endl;
    cout << ufc::max(4.5, 1.3) << endl;
    cout << ufc::max("s", "d") << endl;
}