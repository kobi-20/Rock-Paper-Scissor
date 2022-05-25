#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int game(char user , char comp){
    /*  rr , pp , ss =draw
        sp = user win
        pr = user win
        rs = user win
        sr = comp win
        ps = com wins
        rp = comp win*/
    if(comp == user){
        return 0 ; // 0 for draw...
    }
    //user win condition ..
    if(user=='s' && comp == 'p'){
        return 1 ;
    }
    if(user=='p' && comp == 'r'){
        return 1 ;
    }
    if(user=='r' && comp == 's'){
        return 1 ;
    }
    //comp win condition
    if(user=='s' && comp == 'r'){
        return -1 ;
    }
    if(user=='p' && comp == 's'){
        return -1 ;
    }
    if(user=='r' && comp == 'p'){
        return -1 ;
    }
    return 0 ;
}
int main(){
    char user , comp , get;
    srand(time(0));
    int y = rand()%100 + 1 ; // generating random number between 1 and 100 
    //printf("%d\n", y);
    if(y<33){        // alloting 's' 'p' 'r' to comp on basis of random 3 
        comp = 'r' ;
    }
    if(y>=33 && y<64){
        comp = 'p' ;
    }
    if(y>=64 && y<100){
        comp = 's' ;
    }
    //comp = 'r' ;
    printf("Enter 'r' for rock 'p' for paper 's' scissor :\n");
    scanf("%c" , &user);
    int x = game(user , comp);
    if(x==0){
        printf("you choose %c and computer choose %c\n" , user , comp );
        printf("hence Draw");
    }
    else if(x==1){
        printf("you choose %c and computer choose %c\n" , user , comp );
        printf("You WIN!! :)\n");
    }
    else if(x==-1){
        printf("you choose %c and computer choose %c hence Draw\n" , user , comp );
        printf("You lose..");
    }
    scanf("%c" , &get);
    return 0;
}