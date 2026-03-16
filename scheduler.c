#include <stdio.h>

#define MAX 20

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
} Process;

void calculateMetrics(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }
}

void printResults(Process p[], int n) {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }
}

/* FCFS Scheduling */

void fcfs(Process p[], int n) {
    int time = 0;

    for (int i = 0; i < n; i++) {

        if (time < p[i].arrival)
            time = p[i].arrival;

        time += p[i].burst;
        p[i].completion = time;
    }

    calculateMetrics(p, n);
    printf("\nFCFS Scheduling Results\n");
    printResults(p, n);
}

/* SJF Scheduling */

void sjf(Process p[], int n) {

    int completed = 0;
    int time = 0;
    int visited[MAX] = {0};

    while (completed < n) {

        int idx = -1;
        int minBurst = 9999;

        for (int i = 0; i < n; i++) {

            if (p[i].arrival <= time && !visited[i]) {

                if (p[i].burst < minBurst) {
                    minBurst = p[i].burst;
                    idx = i;
                }
            }
        }

        if (idx != -1) {

            time += p[idx].burst;
            p[idx].completion = time;
            visited[idx] = 1;
            completed++;
        }
        else {
            time++;
        }
    }

    calculateMetrics(p, n);

    printf("\nSJF Scheduling Results\n");
    printResults(p, n);
}

/* Round Robin Scheduling */

void roundRobin(Process p[], int n, int quantum) {

    int time = 0;
    int done;

    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;

    do {

        done = 1;

        for (int i = 0; i < n; i++) {

            if (p[i].remaining > 0) {

                done = 0;

                if (p[i].remaining > quantum) {

                    time += quantum;
                    p[i].remaining -= quantum;
                }
                else {

                    time += p[i].remaining;
                    p[i].remaining = 0;
                    p[i].completion = time;
                }
            }
        }

    } while (!done);

    calculateMetrics(p, n);

    printf("\nRound Robin Scheduling Results\n");
    printResults(p, n);
}

/* MAIN */

int main() {

    int n;
    int quantum;

    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        p[i].pid = i + 1;

        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival);

        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
    }

    Process fcfs_p[MAX];
    Process sjf_p[MAX];
    Process rr_p[MAX];

    for (int i = 0; i < n; i++) {
        fcfs_p[i] = p[i];
        sjf_p[i] = p[i];
        rr_p[i] = p[i];
    }

    fcfs(fcfs_p, n);

    sjf(sjf_p, n);

    printf("\nEnter Time Quantum for Round Robin: ");
    scanf("%d", &quantum);

    roundRobin(rr_p, n, quantum);

    return 0;
}
