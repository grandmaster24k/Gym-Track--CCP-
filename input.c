#include "tracker.h"

int readLine(const char *prompt, char *out, size_t size)
{
for (;;) {
fputs(prompt, stdout);
fflush(stdout);
/* fgets leaves room for the terminating zero character. */
if (!fgets(out, (int)size, stdin)) return 0;
size_t n = strcspn(out, "\r\n");
if (out[n]) {
out[n] = '\0';
return 1;
}
if (n < size - 1) return 1;
/* Discard the rest of an overlong answer before retrying. */
int c = getchar();
if (c == '\n' || c == EOF) return 1;
while (c != '\n' && c != EOF) c = getchar();
puts("Input too long. Please try again.");
}
}



int readInt(const char *prompt, int low, int high, int *out)
{
char line[128];
while (readLine(prompt, line, sizeof line)) {
char *end;
errno = 0;
long x = strtol(line, &end, 10);
int consumed = end != line;
while (isspace((unsigned char)*end)) ++end;
if (consumed && *end == '\0' && errno != ERANGE &&
x >= low && x <= high) {
*out = (int)x;
return 1;
}
printf("Enter a whole number from %d to %d.\n", low, high);
}
return 0;
}




int readDouble(const char *prompt, double low, double high,
double *out)
{
char line[128];
while (readLine(prompt, line, sizeof line)) {
char *end;
errno = 0;
double x = strtod(line, &end);
int consumed = end != line;
while (isspace((unsigned char)*end)) ++end;
if (consumed && *end == '\0' && errno != ERANGE &&
isfinite(x) && x >= low && x <= high) {
*out = x;
return 1;
}
printf("Enter a finite number from %.2f to %.2f.\n",
low, high);
}
return 0;
}