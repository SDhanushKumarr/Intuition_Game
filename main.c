#include <stdio.h>
#include <time.h>
#include <math.h>

void rating(double avg, double diff[])
{
    double sum_of_squares = 0;
    double mean_diff = avg / 5;

    for (int i = 0; i < 5; i++)
    {
        sum_of_squares += (diff[i] - mean_diff) * (diff[i] - mean_diff);
    }

    double std_dev = sqrt(sum_of_squares / 5);
    double basis = std_dev + avg;

    printf("\nOn a scale of 1–5, we rate your intuition as... ");

    if (basis < 0.75)
        printf("5!! (Exceptional)\n");
    else if (basis < 1.25)
        printf("4! (Great)\n");
    else if (basis < 2)
        printf("3 (Decent)\n");
    else if (basis < 2.25)
        printf("2 (Weak)\n");
    else
        printf("1 (Very poor... keep practicing!)\n");
}

int get_result_rating(double di)
{
    if (di < 0.25) return 1;
    if (di < 0.5) return 2;
    if (di < 1.44) return 3;
    if (di < 2.25) return 4;
    return 5;
}

void response(int result, double diff)
{
    if (result == 1)
        printf("Wow! That was super close. You were");
    else if (result == 2)
        printf("Nice! You were only");
    else if (result == 3)
        printf("Not bad. You were");
    else if (result == 4)
        printf("Hmm... you were");
    else
        printf("Ouch! That was off. You were");

    if (diff > 0)
        printf(" %.2f seconds early.\n", diff);
    else
        printf(" %.2f seconds late.\n", -diff);
}

void display_results(double diff[])
{
    printf("\n🔎 Summary of All Rounds:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        int res = get_result_rating(fabs(diff[i]));
        printf("Round %d: ", i + 1);
        if (diff[i] > 0)
            printf("%.2f sec early", diff[i]);
        else
            printf("%.2f sec late", -diff[i]);
        printf(" → Rating: %d\n", res);
    }
    printf("--------------------------------------------------\n");
}

int main()
{
    clock_t start, end;
    double diff[5], avg = 0;
    int seconds[5];

    printf("🎯 Welcome to the Intuition Game!\n");
    printf("Rules:\n- You enter a number of seconds.\n- Then try to press Enter when you think that much time has passed.\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Round %d:\n", i + 1);
        printf("⏱️  Enter how many seconds you want to wait: ");
        scanf("%d", &seconds[i]);
        getchar(); // consume newline

        printf("OK! Press Enter when you're ready to start...\n");
        getchar();

        printf("Timer started! Press Enter when you think %d seconds have passed...\n", seconds[i]);
        start = clock();
        getchar();
        end = clock();

        diff[i] = seconds[i] - ((double)(end - start) / CLOCKS_PER_SEC);
        response(get_result_rating(fabs(diff[i])), diff[i]);

        avg += fabs(diff[i]);

        printf("--------------------------------------------------\n\n");
    }

    printf("All done! Press Enter to see your final results.\n");
    getchar();

    display_results(diff);

    printf("\n📊 Your average error was: %.2f seconds.\n", avg / 5);
    rating(avg / 5, diff);

    printf("\n🎉 Thanks for playing the Intuition Game!\n");

    return 0;
}
