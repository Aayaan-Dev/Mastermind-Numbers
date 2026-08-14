#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = (rand() % 100) + 1;
    int num;
    int attempts = 0; // Attempts count करने के लिए

    // Fancy Title Screen
    printf("===================================================\n");
    printf("     🎯 WELCOME TO THE NUMBER GUESSING GAME 🎯    \n");
    printf("===================================================\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");
    printf("---------------------------------------------------\n");

    while (1) {
        printf("\n👉 Enter your guess (1-100): ");
        scanf("%d", &num);
        attempts++; // हर कोशिश पर count बढ़ाएं

        // Invalid Number Check
        if (num > 100 || num < 1) {
            printf("⚠️ INVALID INPUT! Please choose a number between 1 and 100.\n");
        } 
        // Too High
        else if (num > num1) {
            if (num - num1 <= 5) {
                printf("🔥 Very Close! But still a bit Too High.\n");
            } else {
                printf("📈 Too High! Try a smaller number.\n");
            }
        } 
        // Too Low
        else if (num < num1) {
            if (num1 - num <= 5) {
                printf("🔥 Very Close! But still a bit Too Low.\n");
            } else {
                printf("📉 Too Low! Try a bigger number.\n");
            }
        } 
        // Win Condition
        else {
            printf("\n===================================================\n");
            printf(" 🎉 EXCELLENT! You got it right! The number was %d. 🎉\n", num1);
            printf(" 🏆 Total Attempts: %d\n", attempts);
            
            // Performance Rating
            if (attempts <= 5) {
                printf(" ⭐ Rating: GENIUS! (Under 5 tries)\n");
            } else if (attempts <= 10) {
                printf(" ⭐ Rating: GREAT JOB!\n");
            } else {
                printf(" ⭐ Rating: GOOD EFFORT!\n");
            }
            
            printf("===================================================\n");
            printf("\n🎮 GAME OVER. THANK YOU FOR PLAYING! 🎮\n");
            break;
        }
    }

    return 0;
}