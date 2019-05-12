#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define KEY_LEFT    0x0107
#define KEY_RIGHT   0x0108


void display_game_state(char* pCurrent_letters,char* pTarget_letters,const int NUMBER_OF_LETTERS, const int cursor_position, const int number_of_letter_changes) {

//prints each element in the target array along with its address and
//prints the current array
//and display the cursor position of the current array and number of changes made

const char DASH = '-';
const char SPACE = '   ';
 printf("\n---Game Start ---\n \n");//get both by looping around and printing each char
 int i =0;
 printf("\n -------------------");
       printf("\n Target : \n ");
    for( i = 0; i < NUMBER_OF_LETTERS; i++)
    {
           printf (" %c  %c   %c", *pTarget_letters, SPACE, DASH);
           printf (" %c  %p %c\n ",SPACE, pTarget_letters, SPACE);
           pTarget_letters++;
    }

     printf("\n -------------------");
     printf("\n Current : \n ");
     for( i = 0; i < NUMBER_OF_LETTERS; i++)
           {
            printf ("%c", *pCurrent_letters);
            pCurrent_letters++;
           }

    printf("              ");
    printf ("\n");
    int u = 0;
    for (u; u<cursor_position;u++) {
              printf ("%c", SPACE);
    }
    printf (" %c", DASH);//for loop and this printf used to have the mark under to position of the pointer move left and right as the pointer moves left and right
    printf("\n\nNumber of changes :  %d", (number_of_letter_changes));
}


bool compareletters(char* pCurrent_letters, char* pTarget_letters, int size_of_array){
    //compares both the Target and Current arrays to see if they match, returns boolean
	int i=0;
    bool sameArray = false;
	for(i=0; i<size_of_array; i++){
		    if(*pCurrent_letters == *pTarget_letters){
			sameArray =true;
            }
            else{
            sameArray = false;
            return sameArray;
         }
     pCurrent_letters++;// Add to the address to get the next char in line
     pTarget_letters++;
	}
	return sameArray;
}


int matching_letters(char* pCurrent_letters, char* pTarget_letters, int size_of_array) {
    //counts how many char on the current list are matching the target at a given time
	int same = 0;
    int i = 0;
    for (i; i<size_of_array;i++) {
        if (*pCurrent_letters == *pTarget_letters) {//loop around in order to increase the counter every time it finds a match and not just a change
            same++;
        }
        pCurrent_letters++;
        pTarget_letters++;
    }
	return same;
    }

void move_cursor_right( int* pPosition_of_cursor, const int size_of_array){
//move cursor right

	if ((*pPosition_of_cursor+1) < size_of_array && *pPosition_of_cursor > -1) {
               *pPosition_of_cursor=*pPosition_of_cursor +1;
        }
        else{
                printf("Error");
        }
}//check if able t move right and if unavailable end with error

void move_cursor_left( int* pPosition_of_cursor, const int size_of_array){
//move cursor left
	if ((*pPosition_of_cursor-1) > -1 && (*pPosition_of_cursor-1) < size_of_array) {
              *pPosition_of_cursor= *pPosition_of_cursor -1;//otherwise it moves the position left /right
        }
        else {
                printf("Error");
        }
}
void change_letter(char * pCurrent, int position_of_cursor,char letter, int size_of_array) {

   if (position_of_cursor< size_of_array){
            char* pAddressOfLetterToChange  = pCurrent +position_of_cursor;//changes the letter in the array at the given position of the cursor
            *pAddressOfLetterToChange = letter;
   }
   else{
     printf("Error");
   }
}

//void letterList(char* pCurrent, char* nlist, int* pI, const int size_of_array) {//print out all leters used within the changes in the game
//int u;
//    char newChar;
//    int i = *pI;
//    for (u; u<size_of_array;u++) {
//            newChar = pCurrent[u];
//            nlist[i] = newChar;
//            i = i + 1;
//            *pI= *pI + 1;
//
//            }
//    }


char myGetChar() { // This method take in a input from the user

    char res = getchar();

    bool finish = false;
    char dummy_char = ' ';

    while (finish == false) {
        dummy_char = getchar();
        if (dummy_char == '\n')
            finish = true;
    }

        return res;
    //returns the output to be used in main.c
}




void processCommand(char *pCurrent, int size, int *position_of_cursor, char command,int* pnumber_of_letter_changes  )
{

     bool isValid = false;
	char validCharacters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//processes user input
//if left < move cursor left
//if right > move cursor right
//if valid letter, replace letter
printf("                  ===           %c",command);
	switch (command)
	{
	case '<':
		move_cursor_left( position_of_cursor,size);
		break;
	case '>':
		move_cursor_right( position_of_cursor,size);
		break;
    default:

	while (!isValid)
	{
		if (strchr(validCharacters, command)){
        isValid = true;
       (*pnumber_of_letter_changes)++;//increases after every character change forcing it to end at 8 changes

        change_letter(pCurrent,*position_of_cursor,  command, size);


	}
	else{
        printf("\n Error, you entered an incorrect char, please only use alphabetical characters");
        exit(0);
	}
}
	}
}
