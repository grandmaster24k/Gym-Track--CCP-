#ifndef TRACKER_H
#define TRACKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>

#define NAME_LEN 48
#define MAX_RECORDS 10000
#define DATA_FILE "workouts.txt"
#define KG_TO_LB 2.20462


typedef struct {
    int id; // Unique Ids for each entry
    int sessionId; // same if same session, different if different session
    char exercise[NAME_LEN];
    int weight100; // take weight as weight * 100 to avoid floating point issues
    int reps;
    int setNumber;
    char date[11]; 
} WorkoutEntry;


typedef struct {
    WorkoutEntry *data;
    size_t count;
    size_t capacity;
    int nextId;
    int nextSession;
} WorkoutDB;


int readLine(const char *prompt, char *out, size_t size);

int readInt(const char *prompt, int low, int high, int *out);

int readDouble(const char *prompt, double low, double high, double *out);

void convertWeight(double value, int toPounds, double *out);

void calculateCalories(void);

void generatePlan(void);

#endif
