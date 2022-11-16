#include <iostream>
#include <iomanip>

struct aluno {
    float nota[3];
    float media;
};

void calcula_media(aluno *a){
    a->media = (a->nota[0]+a->nota[1]+a->nota[2])/3;
}

int main(){
    aluno a;
    int i;
    for (i = 0; i < 3; i++)
        std::cin >> a.nota[i];
   
   
    calcula_media(&a);
   
    std::cout << std::fixed;
    std::cout << std::setprecision(1) << a.media;
   
    return 0;
}