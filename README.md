# 🎯 Intuition Game

A precision-based command-line challenge written in C. This program tests your "biological clock" by measuring how accurately you can perceive the passage of time without a stopwatch.

---

## 🚀 Overview

The **Intuition Game** challenges you to estimate a self-defined number of seconds over 5 rounds. It doesn't just look at your average error; it uses statistical variance to determine if your timing is truly consistent or just lucky.

## 🛠️ Features

- **Custom Challenges:** You choose the duration for each round.
- **High Precision:** Utilizes the `<time.h>` library and `CLOCKS_PER_SEC` for microsecond-level measurement.
- **Statistical Scoring:** Calculates **Standard Deviation** and **Mean Absolute Error** to provide a weighted final rating.
- **Detailed Summary:** A clean summary table of all 5 rounds is displayed at the end of the session.

---

## 💻 Installation & Running

### Prerequisites
You will need a C compiler installed on your system (e.g., `gcc`, `clang`, or `MinGW`).

### Compilation
Open your terminal and run the following command:

```bash
gcc intuition_game.c -o intuition_game -lm
