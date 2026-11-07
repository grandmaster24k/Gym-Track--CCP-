 GymTrack – Gym & Health Tracker

(In Progress..)

📌 Project Introduction

GymTrack is a console-based Gym & Health Tracking System developed in C. It is designed to help users track their workouts, monitor exercise progress, generate workout plans, and estimate daily calorie requirements.

The system records the weights used for each exercise, creates simple workout plans, and calculates daily calorie targets. All weights are displayed in both kilograms (kg) and pounds (lb).

GymTrack also uses file handling to store user data, ensuring that workout records persist between sessions.

⚙️ Project Structure

The project uses a custom header file, tracker.h, which contains function declarations and serves as a shared library for the different source files.

The program is divided into multiple .c files, each responsible for a specific part of the system.

File	Description
tracker.h	Header file containing shared function declarations.
features.c	Implements features such as calorie conversion and workout plan generation.
input.c	Handles input validation and error handling.
workout.c	Handles sorting and searching workout entries.
storage.c	Manages workout data storage and retrieval.
main.c	Contains the main program and menu system.

✨ Planned Features

The program will include the following menu options:

 Log Sets – Record workout sets and exercise weights.
 View History – Display previously recorded workouts.
 Search – Search for specific workout entries.
 Sort History – Organize workout records.
 Edit Entry – Modify existing workout records.
 Delete Entry – Remove unwanted entries.
 Workout Plans – Generate simple workout plans.
 Calorie Estimate – Calculate daily calorie targets.
 Personal Records – Keep track of personal bests.
 Save Data – Save workout information to files.
 Load Data – Retrieve previously saved workout information.
 Exit – Exit the program (save data first!).
 

Programming Language: C
Data Persistence: File Handling
Project Type: Console-Based Application
Header Files: Custom tracker.h library



This project is part of our 1st Year CCP (Complex Coding Project) at NED University of Engineering & Technology.

Built with C, teamwork, and plenty of debugging! :)

⭐ GymTrack – Track your workouts, monitor your progress, and keep getting stronger!
