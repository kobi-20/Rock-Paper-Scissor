#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN  0
#define DRAW 1
#define LOSS 2
char* result_tostring(int result) {
  return ((char*[3]){"win", "draw", "loss"})[result];
} 

#define ROCK    0
#define PAPER   1
#define SCISSOR 2
char* choice_tostring(int choice) {
  return ((char*[3]){"rock", "paper", "scissor"})[choice];
}

int input_to_choice(char input) {
  if (input == 'r') return ROCK;
  if (input == 'p') return PAPER;
  if (input == 's') return SCISSOR;
}

static const int condition_map[3][3] = { // [user][comp] = result
  {DRAW, LOSS, WIN}, // rr, rp, rs
  {WIN, DRAW, LOSS}, // pr, pp, ps
  {LOSS, WIN, DRAW}, // sr, sp, ss
};

int endgame(int user, int comp) {
  char* result = result_tostring(condition_map[user][comp]);
  printf("you chose %s and computer chose %s, you %s", choice_tostring(user), choice_tostring(comp), result);
}

int main(){
    char input; 
    srand(time(0));
    int comp = rand() % 3; // generates computer's hand. defined above 
    printf("Enter 'r' for rock 'p' for paper 's' scissor: ");
    scanf("%c", &input);
    endgame(input_to_choice(input), comp);
}
