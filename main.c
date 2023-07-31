#define WORD_ARRAY_LENGTH 23

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


int main() {
    srand(time(NULL));
    
    int correct_flag;
    int answer, attempts, difficulty;
    short int alpha_flag;
    
    char random_element[64];
    char guessed_word[64];
    char current_alpha;
    
    char array[WORD_ARRAY_LENGTH][64] = {
        "mouse",
        "elephant",
        "whale",
        "tree",
        "potato",
        "computer",
        "alphabet",
        "furniture",
        "human",
        "underwater",
        "wall",
        "table",
        "snake",
        "apple",
        "python",
        "c",
        "river",
        "fortran",
        "ruby",
        "cmd",
        "powershell",
        "rust",
        "egg"
    };
    
    while (1) {
        attempts = -1;
        printf("\nWelcome to the game 'Gallow'");
        printf("\nFirstly you need to select difficutly");
        
        
        while (1) {
            printf("\n\n1) Easy\n2) Midium\n3) Hard\n\n");
            printf("Enter statement number > ");
            scanf("%d", &difficulty);
            
            switch (difficulty) {
                case 1:
                    attempts = 10;
                    break;
                case 2:
                    attempts = 5;
                    break;
                case 3:
                    attempts = 3;
                    break;
                default:
                    printf("\nIncorrect answer, please try again \n");
            }
            
            if (attempts != -1) break;
        }
        
        strcpy(random_element, array[rand() % WORD_ARRAY_LENGTH]);
        
        for (int i = 0; i < 64; i++) {
            guessed_word[i] = '\0';
        }
        
        for (int i = 0; i < strlen(random_element); i++) {
            guessed_word[i] = '_';
        }
        
        while ((attempts > 0) && (guessed_word != random_element)) {
            printf("\n\nYou have %d attempts", attempts);
            printf("\nLength of the word: %ld", strlen(random_element));
            printf("\nState of your word now: %s\n", guessed_word);

            printf("\n\nEnter new english alpha > ");
            scanf("\n%c", &current_alpha);
        
            alpha_flag = 0;
            for (int i = 0; i < strlen(random_element); i++) {
                if (random_element[i] == current_alpha) {
                    guessed_word[i] = current_alpha;
                    alpha_flag = 1;
                }
            }
            
            if (alpha_flag == 0) {
                printf("Unfortunately, you didn't guess =(");
                attempts--;
            } else {
                printf("Fortunately, you guessed right =)");
            }
            
            if (attempts == 0) {
                printf("\n\nYou are lose :<");
            } else {
                correct_flag = 0;
                for (int i = 0; i < strlen(guessed_word); i++) {
                    if (guessed_word[i] == '_') {
                        correct_flag = 1;
                        break;
                    }
                }
                
                if (correct_flag == 0) {
                    printf("\n\nYou are win :>");
                    printf("\nThe hidden word was: %s", random_element);
                    break;
                }
                
            }
            
        } 
        
        printf("\n\n1) Play again\n2) Leave the game\n");
        printf("Enter statement number > ");
        scanf("%d", &answer);
        
        if (answer == 2) {break;}
    }
    
    return 0;
}
