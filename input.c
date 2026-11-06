#include "tracker.h"

// the main reading functions which will take input prompt from the user in strings and then later cnovert.
int readLine(const char *prompt, char *out, size_t size) // parameters
{
    for (;;)
    { // runs and infinite loop until something is returned
        fputs(prompt, stdout);
        fflush(stdout); // for clearing memory buffer
        // fgets leaves room for the terminating zero character
        if (!fgets(out, (int)size, stdin))
            return 0; // makes sure that prompt is not more than the size declared
        size_t n = strcspn(out, "\r\n");
        if (out[n])
        { // checks for new line
            out[n] = '\0';
            return 1;
        }
        if (n < size - 1)
            return 1;
        /* Discard the rest of an overlong answer before retrying. */
        int c = getchar();
        if (c == '\n' || c == EOF)
            return 1;
        while (c != '\n' && c != EOF)
            c = getchar(); // if input is too long for buffer
        puts("Input too long. Please try again.");
    }
}

// reading integer from readline()
int readInt(const char *prompt, int low, int high, int *out) // low and high are the limits of the function , for eg if a menu has options only from 1-4 so the low will be 1 and high 4 and out is the integer that is passed from function
{
    char line[128]; // to temporarily hold the input prompt
    long x;
    char *end;
    while (readLine(prompt, line, sizeof line))
    { // runs a loop jab tk user prompt enter krrha hai
        errno = 0;
        x = strtol(line, &end, 10);
        int consumed = end != line;
        while (isspace((unsigned char)*end))
            ++end;
        if (consumed && *end == '\0' && errno != ERANGE && // for validation , to check if the number is too massive or small
            x >= low && x <= high)
        {
            *out = (int)x; // stores the output integer x in end through pointer
            return 1;
        }
        printf("Enter a whole number from %d to %d.\n", low, high); // runs when input is something other than integer
    }
    return 0;
}

// reading double / floating point from readline()
int readDouble(const char *prompt, double low, double high,
               double *out)
{
    char line[128];
    while (readLine(prompt, line, sizeof line))
    {                                  // runs a loop to take input from user until EOF (end of file)
        char *end;                     // to track where the input stopped or if there was any input or not
        errno = 0;                     // to set the error count to 0;
        double x = strtod(line, &end); // strtod built in function for string to double
        int consumed = end != line;
        while (isspace((unsigned char)*end))
            ++end;                                         // ignores spaces
        if (consumed && *end == '\0' && errno != ERANGE && // for validation , to check if the number is too massive or small
            isfinite(x) && x >= low && x <= high)
        {
            *out = x;
            return 1; // if everything is done correct  ,exit properly
        }
        printf("Enter a finite number from %.2f to %.2f.\n",
               low, high);
    }
    return 0; // returns 0 if input is not correct and will run again
}

int dateOrdinal(const char *s) // takes a character pointer and returns an integer
{
    if (strlen(s) != 10 || s[4] != '-' || s[7] != '-') // to check if the format is of a date , eg;2026-11-09
        return -1;
    for (int i = 0; i < 10; ++i) // loops over the date string and validates except the two hyphens and checks that the character is from 0-9
        if (i != 4 && i != 7 && (s[i] < '0' || s[i] > '9'))
            return -1;
    int y = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + // these build the year,month and day from strings to integer respectively
            (s[2] - '0') * 10 + s[3] - '0';
    int m = (s[5] - '0') * 10 + s[6] - '0';
    int d = (s[8] - '0') * 10 + s[9] - '0';
    if (y < 2000 || y > 2099 || m < 1 || m > 12) // rejects outside 2000-2099
        return -1;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // # of days for each month
    // within 2000-2099 every year divisible by 4 is a leap year
    if (y % 4 == 0) // leap year check for february
        days[1] = 29;
    if (d < 1 || d > days[m - 1]) // checks if the day is valid for chosen month
        return -1;
    int total = 0;
    for (int year = 2000; year < y; ++year) // counts days from current date to 2000
    {
        total += 365;
        if (year % 4 == 0)
            ++total;
    }
    for (int month = 1; month < m; ++month)
        total += days[month - 1];
    return total + d - 1; // return the date
}
