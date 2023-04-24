#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        printf("How many cents is the customer owed? ");
        scanf("%d", &cents);
    }
    while (cents < 0);
    if (cents == 0)
    {
        printf("The customer is owed 0 cents ");
    }
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    // for loop, though this could've been done with simple division i think
    for (int q = 0; q < cents; q += 25)
    {
        // if loop so if q < cents is by less than 25, quarters don't get added
        if (cents - q >= 25)
        {
            quarters++;
        }
    }
    return (quarters);
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    for (int d = 0; d < cents; d += 10)
    {
        if (cents - d >= 10)
        {
            dimes++;
        }
    }
    return (dimes);
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    for (int n = 0; n < cents; n += 5)
    {
        if (cents - n >= 5)
        {
            nickels++;
        }
    }
    return (nickels);
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    for (int p = 0; p < cents; p += 1)
    {
        pennies++;
    }
    return (pennies);
}
