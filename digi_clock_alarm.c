#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void displayClock();
void setAlarm();
void manageAlarms();
void delay(int seconds);

int main() {
    while (1) {
        system("cls");
        displayClock();
        printf("\n\n1. Set Alarm\n");
        printf("2. Manage Alarms\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        char choice = getch();
        switch (choice) {
            case '1':
                setAlarm();
                break;
            case '2':
                manageAlarms();
                break;
            case '3':
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                delay(2);
                break;
        }
    }
    return 0;
}

void displayClock() {
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    printf("Current Time: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}

void setAlarm() {
    int hour, minute, second;
    printf("Enter alarm time (HH:MM:SS format): ");
    scanf("%d:%d:%d", &hour, &minute, &second);
    printf("Alarm set for %02d:%02d:%02d\n", hour, minute, second);
    delay(2);
}

void manageAlarms() {
    printf("No alarms set at the moment.\n");
    delay(2);
}

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}