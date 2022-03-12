/*
Sample input:
.---
.--.
-...
----
Output: 2
*/

#include <bits/stdc++.h>
#define vt vector
using namespace std;

int row=0;	//matrix size global, accessed by input() and main()

vt<vt<char>> input(){               //input function
    vt<vt<char>> arr;
    string a;
    while(getline(cin,a)){          //input per-baris, simpan ke string a
        int size=a.size();          //size = banyaknya char di string a
        vt<char> temp;
        for(int i=0; i<size; i++){
            temp.push_back(a[i]);       //populate vector
        }
        arr.push_back(temp);
        row++;                          //+ penghitung baris
        if(row==size)                   //jika baris = banyaknya char di string a, hentikan input
            break;
    }
    return arr;
}

void mark(vt<vt<char>> a, int x, int y, vt<vt<bool>> &b, const int n){			//mark '.' as part of house, x= current row, y= current column, n=matrix size
    int relativex[] = {0,-1,1,0};
    int relativey[] = {-1,0,0,1};   //[0] atas, [1] kiri, [2] kanan, [3] bawah
    int iX, iY;
    b[x][y] = true;                 //MARK
    for(int i=0; i<4; i++){         //loop 4 direction
        iX=x+relativex[i];          //neighbour row
        iY=y+relativey[i];          //neighbour column
        if(iX>=0 && iX<n && iY>=0 && iY<n && (a[iX][iY]== '.' && !b[iX][iY])){  //check if index is inside matrix and have value of '.'
            mark(a, x+relativex[i], y+relativey[i], b, n);                      //mark neighbour recursively
        }
    }
}

int count(vt<vt<char>> a, const int n){
    vt<vt<bool>> b;
    vt<bool> temp(n, false);
    for(int i=0; i<n; i++){                     //create 2d array to assign mark status
        b.push_back(temp);
    }
    int counter = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //cout<<b[i][j];
            if(a[i][j] == '.' && !b[i][j]){    //if matrix index is not marked yet (not part of another house)= anchor point
                mark(a, i, j, b, n);           //mark
                counter++;                     //update counter
                //cout<<"is at "<<i<<" "<<j<<endl;
            }
        }
        //cout<<endl;
    }
   /* for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }*/							                //debug mark
    return counter;
}

int main(){
    vt<vt<char>> arr = input();
    cout<<endl<<count(arr, row);
}
