
// the main reading functions which will take input prompt from the user in strings and then later cnovert.
int readLine(const char *prompt, char *out, size_t size) // parameters
 2 {
 3 for (;;) { // runs and infinite loop until something is returned
 4 fputs(prompt, stdout);
 5 fflush(stdout); //for clearing memory buffer
 6 /* fgets leaves room for the terminating zero character. */
 7 if (!fgets(out, (int)size, stdin)) return 0; //makes sure that prompt is not more than the size declared
 8 size_t n = strcspn(out, "\r\n");
 9 if (out[n]) { //checks for new line
10 out[n] = '\0';
11 return 1;
12 }
13 if (n < size - 1) return 1;
14 /* Discard the rest of an overlong answer before retrying. */
15 int c = getchar();
16 if (c == '\n' || c == EOF) return 1;
17 while (c != '\n' && c != EOF) c = getchar(); //if input is too long for buffer
18 puts("Input too long. Please try again.");
19 }
20 }


int readInt(const char *prompt, int low, int high, int *out)
 2 {
 3 char line[128]; //to temporarily hold the input prompt
 4 long x;
 5 char *end;
 6 while (readLine(prompt, line, sizeof line)) { // runs a loop jab tk user prompt enter krrha hai
 7 errno = 0;
 8 x = strtol(line, &end, 10);
 9 int consumed = end != line;
10 while (isspace((unsigned char)*end)) ++end;
11 if (consumed && *end == '\0' && errno != ERANGE && //for validation , to check if the number is too massive or small
12 x >= low && x <= high) {
13 *out = (int)x; // stores the output integer x in end through pointer
14 return 1;
15 }
16 printf("Enter a whole number from %d to %d.\n", low, high); // runs when input is something other than integer
17 }
18 return 0;
19 }



// reading double / floating point from readline()
int readDouble(const char *prompt, double low, double high,
 2 double *out)
 3 {
 4 char line[128];
 5 while (readLine(prompt, line, sizeof line)) { // runs a loop to take input from user until EOF (end of file)
 6 char *end; // to track where the input stopped or if there was any input or not
 7 errno = 0; // to set the error count to 0;
 8 double x = strtod(line, &end); //strtod built in function for string to double
 9 int consumed = end != line;
10 while (isspace((unsigned char)*end)) ++end; //ignores spaces
11 if (consumed && *end == '\0' && errno != ERANGE && //for validation , to check if the number is too massive or small
12 isfinite(x) && x >= low && x <= high) {
13 *out = x;
14 return 1; // if everything is done correct  ,exit properly
15 }
16 printf("Enter a finite number from %.2f to %.2f.\n",
17 low, high);
18 }
19 return 0;  //returns 0 if input is not correct and will run again
20 }
