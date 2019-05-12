#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "word_game.h"


void start_game(char * pCurrent_letters,  char* pTarget_letters, const int size_of_word){//method to begin the game



    int position_of_cursor = 0;
    bool game_finished = false;
    int number_of_letter_changes = 0;
    const int max;
    int keystrokes =1;
    int limit = size_of_word*2;
    int i;
    int *pI =&i;
    //limit is number of chances to find the right character
    char list_of_char[size_of_word*limit];


    printf("Beginning the word game");

       while (compareletters(pCurrent_letters,pTarget_letters,size_of_word)== false ) {
            //loop as long as the return value of compare letters is still false

              if (number_of_letter_changes > limit) {
                  printf("\nYou have used all allowed attempts, game over.\n");
                  exit(0);
                }
                printf("\n* %d *\n", position_of_cursor);
                display_game_state(pCurrent_letters,pTarget_letters,size_of_word, position_of_cursor ,number_of_letter_changes);
                 //prints each element in the target array along with its address and
                 //prints the current array
                 //and display the cursor position of the current array while updating it and number of changes made

                int match_letters = matching_letters(pCurrent_letters, pTarget_letters, size_of_word);
                //counts how many char on the current list are matching the target at a given time
                printf("\nCurrent amount of matching characters: %d\n", match_letters);

                char letter = myGetChar();//takes in the char provided and passes it on to processCommand where it decides what is to be done with

                processCommand(pCurrent_letters,size_of_word, &position_of_cursor, letter,&number_of_letter_changes);
                //letterList(pCurrent_letters, list_of_char, pI, size_of_word);// adds the letter
                display_game_state(pCurrent_letters,pTarget_letters,size_of_word, position_of_cursor ,number_of_letter_changes);



        }

       printf("\nBoth words in the array match, you win\n");
        int u= 0;
    printf("\nThe list of words used =");
    for (u; u < i; u++) {
        printf("%c", list_of_char[i]);
    }
}


int main()
{


    char current_letters[] = {'b', 'e', 'l','l'};
    char target_letters[] = {'c','o','a','t'};

    const int NUMBER_OF_LETTERS = 4;
    start_game(current_letters,target_letters,NUMBER_OF_LETTERS);

    return 0;

}
