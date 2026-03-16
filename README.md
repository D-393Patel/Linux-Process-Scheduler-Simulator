# Linux Process Scheduler Simulator (C)

A **Linux-like CPU scheduling simulator** written in **C**, demonstrating fundamental Operating System scheduling algorithms. This project is ideal for learning and showcasing **process scheduling, turnaround time, and waiting time calculations** in a systems programming context.

---

## Features

- Implements three CPU scheduling algorithms:
  - **First Come First Serve (FCFS)**
  - **Shortest Job First (SJF – Non-Preemptive)**
  - **Round Robin (RR)**
- Calculates **Completion Time (CT)**, **Turnaround Time (TAT)**, and **Waiting Time (WT)** for each process.
- Simulates processes based on **arrival times** and **burst times**.
- Designed for **Linux/Unix environments**, easy to compile and run using **GCC**.

---

## Usage

### Compile

```bash
gcc scheduler.c -o scheduler
