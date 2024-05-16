#include <stdio.h>
#include <time.h>
#include <math.h>

#define ORANGE_Color "\x1b[38;5;208m"   // orange color
#define MAGENTA_Color "\x1b[35m"        // Magenta color
#define LAVENDER_Color "\x1b[38;5;183m" // Lavender color
#define GORESET_Color "\x1b[0m"         // Reset
#define GREEN_Color "\x1b[32m"          // Green color
#define RED_Color "\x1b[31m"            // red color
#define BLUE_Color "\x1b[34m"           // blue color
#define OLIVE_Color "\x1b[38;5;58m"     // Olive color
#define YELLOW_Color "\x1b[33m"         // yellow color
#define TURQUOISE_Color "\x1b[38;5;45m" // Turquoise color
#define CYAN_Color "\x1b[36m"           // Cyan color
#define AQUA_Color "\x1b[38;5;14m"      // Aqua color
#define CORAL_Color "\x1b[38;5;203m"    // Coral color
#define LIME_Color "\x1b[38;5;118m"     // Lime color

void rating(double avg, double diff[])
{
    double sum_of_squares = 0;
    double mean_diff = avg / 5;

    // Calculate the sum of squares of differences
    for (int i = 0; i < 5; i++)
    {
        sum_of_squares += (diff[i] - mean_diff) * (diff[i] - mean_diff);
    }

    // Calculate standard deviation
    double std_dev = sqrt(sum_of_squares / 5);
    int basis = std_dev + avg;
    printf(MAGENTA_Color "On a scale of 1-5 we rate your intuition a....\n" GORESET_Color);
    if (basis < 0.75)
    {
        printf(GREEN_Color "5!!\n");
    }
    if (basis < 1.25 && basis > 0.75)
    {
        printf(LIME_Color "4!! XD\n");
    }
    if (basis < 2 && basis > 1.25)
    {
        printf(YELLOW_Color "3 ;)\n");
    }
    if (basis < 2.25 && basis > 2)
    {
        printf(ORANGE_Color "2..\n");
    }
    if (basis > 2.25)
    {
        printf(RED_Color "1...:(\n");
    }
}

int result(double di)
{
    if (di < 0.25)
    {
        return 1;
    }
    else if (di > 0.25 && di < 0.5)
    {
        return 2;
    }
    else if (di > 0.5 && di < 1.44)
    {
        return 3;
    }
    else if (di > 1.44 && di < 2.25)
    {
        return 4;
    }
    else if (di > 2.25)
    {
        return 5;
    }
}

void response(int result, double diff)
{
    if (result == 1)
    {
        printf(BLUE_Color "Wow! That was really close, you were just");
    }
    else if (result == 2)
    {
        printf(GREEN_Color "Damn! That was pretty close, you were only");
    }
    else if (result == 3)
    {
        printf(YELLOW_Color "That was kinda close, you were");
    }
    else if (result == 4)
    {
        printf(ORANGE_Color "You were not focusing were you? Cuz you were");
    }
    else if (result == 5)
    {
        printf(RED_Color "Umm.... That was really bad cuz, you were");
    }

    if (diff > 0)
    {
        printf(" %.3f seconds early\n", diff);
    }
    else if (diff < 0)
    {
        printf(" %.3f seconds late\n", -diff);
    }
}

void display_results(double diff[])
{
    printf(LIME_Color "And the Scores are\n" GORESET_Color);
    for (int i = 0; i < 5; i++)
    {
        switch (result(diff[i]))
        {
        case 1:
            printf(BLUE_Color "In Round no. %d, you were ", i + 1);
            break;
        case 2:
            printf(GREEN_Color "In Round no. %d, you were ", i + 1);
            break;
        case 3:
            printf(YELLOW_Color "In Round no. %d, you were ", i + 1);
            break;
        case 4:
            printf(ORANGE_Color "In Round no. %d, you were ", i + 1);
            break;
        case 5:
            printf(RED_Color "In Round no. %d, you were ", i + 1);
            break;
        }
        if (diff[i] > 0)
        {
            printf("%.3f seconds early\n" GORESET_Color, diff[i]);
        }
        if (diff[i] < 0)
        {
            printf("%.3f seconds Late\n" GORESET_Color, -diff[i]);
        }
    }
}

int main()
{
    clock_t start, end;
    double total_time[5];
    int intuition[5];
    double diff[5];
    double di[5];
    double avg = 0;
    system("cls");
    printf(TURQUOISE_Color "THIS IS CALLED THE INTUITION GAME\nThe rules are simple\nYou enter a no. and you are supposed to press enter again once u feel like that \nthat no. of seconds have passed by \nDo you understand this game?\nIf yes press Enter\n");
    getchar();
    system("cls");
    for (int i = 0; i < 5; i++)
    {
        printf(CYAN_Color "ROUND NO. %d\nTo start this round please enter the no. of seconds after which you will press enter\n", i + 1);
        scanf("%d", &intuition[i]);
        getchar();

        start = clock();

        printf("Press Enter to check your intuition\n");
        getchar();

        end = clock();

        total_time[i] = (double)(end - start) / CLOCKS_PER_SEC;
        diff[i] = intuition[i] - total_time[i];
        di[i] = diff[i] * diff[i];
        response(result(di[i]), diff[i]);
        if (diff[i] > 0)
        {
            avg = avg + diff[i];
        }
        else if (diff[i] < 0)
        {
            avg = avg - diff[i];
        }
        if (i < 4)
        {
            printf(CYAN_Color "To continue to the next round please Press Enter");
            getchar();
            system("cls");
        }
    }
    printf(AQUA_Color "\nTo see your results please Press Enter" GORESET_Color);
    getchar();
    system("cls");
    display_results(diff);
    printf(CORAL_Color "If you wish to find how good your intuition is on average then press Enter\n");
    getchar();
    printf(LAVENDER_Color "On an average you were %.3f seconds away from the result\nTo rate your Intuition please press Enter again\n", avg / 5);
    getchar();
    system("cls");
    printf("Since your average was %.3f seconds......\n",avg/5);
    rating(avg / 5, diff);
    printf(OLIVE_Color "To End the Game please click Enter again\n" GORESET_Color);
    getchar();
    return 0;
}
