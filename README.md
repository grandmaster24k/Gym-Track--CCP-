GymTrack – Gym & Health Tracker

(In Progress...)

📌 Project Introduction

GymTrack is a console-based Gym & Health Tracking System developed in C. It is designed to help users track their workouts, monitor exercise progress, generate workout plans, and estimate daily calorie requirements.

The system records the weights used for each exercise, creates simple workout plans, and calculates daily calorie targets. All weights are displayed in both kilograms (kg) and pounds (lb).

GymTrack also uses file handling to store user data, ensuring that workout records persist between sessions.

⚙️ Project Structure:

The project uses a custom header file, tracker.h, which contains function declarations and serves as a shared library for the different source files.

The program is divided into multiple .c files, each responsible for a specific part of the system.

File	Description:

1.tracker.h | Header file containing shared function declarations.
2.features.c | Implements features such as calorie conversion and workout plan generation.
3.input.c | Handles input validation and error handling.
4.workout.c | Handles sorting and searching workout entries.
5.storage.c | Manages workout data storage and retrieval.
6.main.c | Contains the main program and menu system.

Planned Features:

The program will include the following menu options:

1.Log Sets – Record workout sets and exercise weights.
2.View History – Display previously recorded workouts.
3.Search – Search for specific workout entries.
4.Sort History – Organize workout records.
5.Edit Entry – Modify existing workout records.
6.Delete Entry – Remove unwanted entries.
7.Workout Plans – Generate simple workout plans.
8.Calorie Estimate – Calculate daily calorie targets.
9.Personal Records – Keep track of personal bests.
10.Save Data – Save workout information to files.
11.Load Data – Retrieve previously saved workout information.
12.Exit – Exit the program.

Programming Language: C

Project Type: Console-Based Application

Header Files: Custom tracker.h library

This project is part of our 1st Year CCP (Complex Coding Project) at NED University of Engineering & Technology.
