#include <iostream>
#define dugum_sayisi 7

using namespace std;

class Graph{
public:
    int kenar_agirlik_matrisi[dugum_sayisi][dugum_sayisi];

    int kenar_sayisi = 0;
    int iterator_sayisi =0;
    int counter=0;
    int kopru_counter=0;


    void graf_olustur(){
        cout << "Lutfen dugumlerin birbiriyle iliskilerini giriniz." << endl;
        for(int i=0;i<dugum_sayisi;i++){
            for(int j=0;j<dugum_sayisi;j++){
                cout << i << " v " << j << " = ";
                cin >> kenar_agirlik_matrisi[i][j];
                cout << endl;
            }
        }

        cout << "Lutfen graf in kenar sayisini giriniz :";
        cin >> kenar_sayisi;
        iterator_sayisi = kenar_sayisi - dugum_sayisi;
    }

    void print_matrix(){
        for(int i=0;i<dugum_sayisi;i++){
            for(int j=0;j<dugum_sayisi;j++){
                cout << kenar_agirlik_matrisi[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool kopru_koptu_mu(int x,int y){
        int temp[2] = {kenar_agirlik_matrisi[x][y],kenar_agirlik_matrisi[y][x]};
        bool first = true;
        bool second = true;
        for(int i=0;i<2;i++){
            for(int j=0;j<dugum_sayisi;j++){
                kenar_agirlik_matrisi[x][y] =0;
                kenar_agirlik_matrisi[y][x] =0;
                if(kenar_agirlik_matrisi[x][j] != 0){
                    first = false;
                }
                if(kenar_agirlik_matrisi[y][j] != 0){
                    second = false;
                }
            }
        }
        kenar_agirlik_matrisi[x][y] =temp[0];
        kenar_agirlik_matrisi[y][x] =temp[1];
        return first || second;
    }

    int max_bul(){
        int max = 0;
        for(int i=0;i<dugum_sayisi;i++){
            for(int j=0;j<dugum_sayisi;j++){
                if(kenar_agirlik_matrisi[i][j] > max){
                    max = kenar_agirlik_matrisi[i][j];
                }
            }
        }
        return max;
    }

    int* max_index(int a[2]){
        int max = max_bul();
        for(int i=0;i<dugum_sayisi;i++){
            for(int j=0;j<dugum_sayisi;j++){
                if(kenar_agirlik_matrisi[i][j] == max){
                    a[0] = i;
                    a[1] = j;
                    return a;
                }
            }
        }
        return nullptr;
    }


    void ana_fonksiyon(){
        if(counter > iterator_sayisi) { return;}
        int max_index_array[2];
        max_index(max_index_array);
        if( !(kopru_koptu_mu(max_index_array[0],max_index_array[1])) ){
            kenar_agirlik_matrisi[max_index_array[0]][max_index_array[1]] = 0;
            kenar_agirlik_matrisi[max_index_array[1]][max_index_array[0]] = 0;

        }else{
            kenar_agirlik_matrisi[max_index_array[0]][max_index_array[1]] *= -1;
            kenar_agirlik_matrisi[max_index_array[1]][max_index_array[0]] *= -1;
            counter--;
            kopru_counter++;
        }
        counter++;
        ana_fonksiyon();

    }

    void matrixi_tamamla(){
        for(int i=0;i<dugum_sayisi;i++){
            for(int j=0;j<dugum_sayisi;j++){
                kenar_agirlik_matrisi[i][j] = abs(kenar_agirlik_matrisi[i][j]);
            }
        }
    }
    
};


int main() {

    Graph obj;

    //obj.graf_olustur();

    obj.ana_fonksiyon();

    obj.matrixi_tamamla();

    obj.print_matrix();
    return 0;
}

/*
int kenar_agirlik_matrisi[dugum_sayisi][dugum_sayisi] = {{0, 6, 0, 0, 0, 0, 3},
                                                         {6,0,9,7,0,0,12},
                                                         {0,9,0,4,0,0,0},
                                                         {0,7,4,0,11,8,18},
                                                         {0,0,0,11,0,13,0},
                                                         {0,0,0,8,13,0,5},
                                                         {3,12,0,18,0,5,0}};*/