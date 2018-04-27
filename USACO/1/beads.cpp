/*
ID: Young Le
PROG: beads
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fin, *fout;
    fin = fopen("beads.in", "r");
    fout = fopen("beads.out", "w");

    int N;
    fscanf(fin, "%d", &N);
    char *bead = new char[N];
    fscanf(fin, "%s", bead);

    int cur = 0, max = 0;
    char color;
    bool switched;

    for(int i=0; i<N; i++){
        cur = 0;
        switched = false;
        color = 'w';
        for(int j=0; j<N; j++){
            const char cur_c = bead[(i+j) % N];
            if(cur_c != 'w'){
                if(color == 'w'){
                    color = cur_c;
                }
                else if(color != cur_c){
                    if(switched)
                        break;
                    else{
                        color = cur_c;
                        switched = true;
                    }
                }
            }
            ++cur;
        }
        if(cur > max)
            max = cur;
    }

    fprintf(fout, "%d\n", max);

    delete [] bead;

    return 0;
}
