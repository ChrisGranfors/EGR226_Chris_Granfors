#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumberGenerator() //This function generates a random number from 1 to 6
{
    int num = (rand() % 6) + 1; //rand() gives any random number so we do rand()%6 + 1 to get a number from 1 and 6
    return num;
}

int getCredits()
{
    int n = 0;
    while (n <= 0) //This loop is to ensure that credits are always entered more than 0
    {
        printf("Enter the total credits (a positive amount) to start the game\n");
        scanf("%d", &n);fflush(stdin);
    }
    return n;
}

void playgame(int *tC) //This is the major play funtion
{
    printf("Total Credit = %d\n", *tC);
    int currentbet = 0, compdice, playerdice;
    while (1)
    {
        while (currentbet <= 0 || currentbet > *tC){
        printf("Enter the bet (less than total credit, but not negative) you want to place :");
        scanf("%d", &currentbet);fflush(stdin);
       }
        if (currentbet <= *tC) //If the current bet is less than or equal to tC we break out of loop
            break;
    }
    compdice = randomNumberGenerator();
    playerdice = randomNumberGenerator();
    printf("Computer dice rool = %d\nPlayer dice roll =%d\n", compdice, playerdice);
    if (compdice > playerdice) //Conditon for loss
    {
        printf("You lose this bet, total credit now is %d\n", *tC - currentbet);
        *tC -= currentbet;
        if (*tC <= 0)
        {
            printf("You cant play anymore, the credit amount has gone below 0\n");
        }
    }
    else if (playerdice > compdice) //Codition for a win
    {
        printf("You win this bet, total credit now is %d\n", *tC + currentbet);
        *tC += currentbet;
    }
    else //Else it is a draw
    {
        printf("Its a draw, your credit amount remains the same: %d\n", *tC);
    }
}



int main()
{
    srand(time(NULL));
    printf("Welcome to the dice game, this is a 6 face dice game that you play with the computer, place a bet. If your dice number is larger than computer dice number you win double the amonut of your current bet.\nIf computer get a larger number then you lose that bet.\nIn case of a draw you dont lose or win anything\n");
    int totalcredits, choice = 0;
    totalcredits = getCredits();             //Ask the player the credits
    while (choice != 2 && totalcredits >= 1) //We should allow play as long as credits > 0 and choice is 1
    {
        printf("What do you want to do?\n1.Place bet\n2.Cash out\n");
        scanf("%d", &choice);fflush(stdin);
        if (choice == 1)
            playgame(&totalcredits); //IMP: We pass the totalcredits by reference so that its actual value gets changed
    }
    printf("Thanku for playing the game, your total amount after playing is %d", totalcredits);
    return 0;
}
