# Philosophers - 42 School Project (Lisbon)

### Table of Contents
* [Introduction](#introduction-)
* [Project Objectives](#project-objectives-)
* [How it Works](#how-it-works-)
* [Features](#features-)
* [Learning Outcomes](#learning-outcomes-)
* [Conclusion](#conclusion-)

## Introduction 📖

The *philosophers* project at 42 School is a well-known concurrency and synchronization challenge that explores the Dining Philosophers problem. This classic problem tests students' ability to manage multiple processes or threads while avoiding issues like deadlocks and starvation.

The project requires implementing a simulation where philosophers sit around a table, each alternating between thinking, eating, and sleeping. The challenge lies in ensuring that they can eat without running into race conditions, deadlocks, or resource starvation.

## Project Objectives 🏆

The objectives of the *philosophers* project are:

1. **Understanding Concurrency:** Develop a multi-threaded or multi-process program that models the behavior of philosophers dining at a table.
2. **Synchronization Techniques:** Use mutexes or other synchronization mechanisms to manage shared resources (forks).
3. **Avoiding Deadlocks:** Implement strategies to ensure that no philosopher gets permanently stuck waiting for a fork.
4. **Preventing Starvation:** Ensure that every philosopher gets a chance to eat instead of some being indefinitely deprived.

## How it Works 🔧

The *philosophers* program simulates a scenario where:

1. Each philosopher can be in one of three states: *thinking*, *eating*, or *sleeping*.
2. Each philosopher requires two forks to eat.
3. The forks are shared between adjacent philosophers.
4. The program must ensure proper synchronization to prevent two philosophers from picking up the same fork at the same time.
5. The simulation must continue until a stopping condition is met (e.g., a philosopher dies due to starvation or a predefined time limit is reached).

## Features ✨

1. **Thread Simulation:** The project can be implemented using either threads, with appropriate synchronization.
2. **Precise Timing:** The execution must handle precise timing, ensuring philosophers eat and sleep for specified durations.
3. **Logging Events:** The program should print actions in real-time, such as a philosopher picking up a fork, eating, thinking, or dying.
4. **Parameterization:** The simulation should accept parameters such as:
   - Number of philosophers
   - Time to die
   - Time to eat
   - Time to sleep
   - Optional: Number of times each philosopher must eat

## Learning Outcomes 🎓

By completing this project, you will:

- **Master Concurrency Handling:** Learn how to manage multiple threads.
- **Understand Synchronization Mechanisms:** Gain experience with mutexes and other synchronization techniques.
- **Develop Debugging Skills:** Debugging multi-threaded programs is challenging and requires careful thought.
- **Improve Algorithmic Thinking:** Design efficient algorithms to prevent deadlocks and starvation.

## Conclusion ✅

The *philosophers* project is an excellent introduction to concurrent programming and synchronization. By completing it, students gain crucial skills in managing shared resources, debugging complex multi-threaded applications, and ensuring efficient program execution. Mastering this project will provide a solid foundation for understanding real-world concurrency issues in software development.
