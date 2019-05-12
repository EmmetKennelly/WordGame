#ifndef WORD_GAME_H_INCLUDED
#define WORD_GAME_H_INCLUDED
void display_game_state(char* pCurrent_letters,char* pTarget_letters, const int NUMBER_OF_LETTERS, const int cursor_position, const int number_of_letter_changes);
bool compareletters(char* pCurrent_letters,char* pTarget_letters, int size_of_array);

void change_letter(char * pCurrent, int position_of_cursor,char letter, int size_of_array);

int matching_letters(char* pCurrent_letters,char* pTarget_letters, int size_of_array);
void processCommand(char *pCurrent, int size, int *position_of_cursor, char command,int* pnumber_of_letter_changes);
void move_cursor_right( int* pPosition_of_cursor, const int max);
void move_cursor_left( int* pPosition_of_cursor, const int max);
void replace_char(char * input, int* pPosition_of_cursor,char* pCurrent_letters, char replace);
void letterList(char* pCurrent, char* newList, int* pIndex, const int size_of_word);

char myGetChar() ;
#endif // WORD_GAME_H_INCLUDED
