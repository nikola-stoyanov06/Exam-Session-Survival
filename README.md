# Exam Session Survival

## Course Project – Introduction to Programming (Pract.) 
Faculty of Mathematics and Informatics, Sofia University  
Winter Semester 2025/2026  

**Author:** Nikola Stoyanov  
**Faculty Number:** 3MI0600561  
**Compiler:** VS
**Language:** C++  

---

## Project Description

*Exam Session Survival* is a console-based game that simulates the exam session experience.

The player manages these resources:
- Energy
- Psyche
- Money
- Knowledge

The game lasts 45 days or until the player loses.

The player loses when he has no psyche or money. After 45 days, based on the number of exams passed, the player either succeeds in the session, has to redo exams later, or drops out completely.

The player, in each in-game day, has a choice of five actions(study, eat, party, rest and work), each with certain subactions. They each affect the player's stats in different ways. There is a chance of random events triggering on each action, with positive or negative outcomes.

The player enters a username when creating a new game, which is used to save his progress and later to load it back up.

---

## Summary of Gameplay Loop

1. Launch the game
2. Choose:
   - To create a new game
   - To load an old save
   - To exit
3. Upon choosing "New Game":
   - Choose difficulty
   - Enter username
4. Upon chooslng "Load Game":
   - Player inputs username
   - If such save file exists, the game loop begins from the last saved point of the user.
5. Each day:
   - Choose an action
   - User may choose to save game or exit
   - Random events may occur after choosing action
   - Stats are updated based on actions
6. An exam schedule is defined, with predetermined days for exams 1-3 and 5, and a random date for 4.
7. The game ends when
   - A critical stat reaches zero (psyche or money)
   - The session duration ends
8. With 5 taken exams, the player wins the game. With 1 to 4, he "carries" the exams forward, hoping to pass them in the future. With none, the game ends in total defeat.

---

## Features Implemented (So far)

- Console-based user interface
- Structured game loop
- Random good and bad events
- Exam logic with random "luck" factor included
- Save and load functionality using text files in the "/saves" folder
- Input validation

---

## Plans for the future

- Polish and redesign the UI
- Add more random events per action (By possibly storing events in a matrix, instead of an array)
- Consider storing random event data in .txt files instead of an array in a .cpp file.
- Incorporate difficulty better
  - Use difficulty to alter the stat changes (Using multiplier constants for each difficulty)
  - Change event probability based on difficulty (Higher difficulty -> higher chance of "Bad" events)
- Improve game-design
  - Add user warnings for low stats
  - Rebalance actions, so every one has a purpose
  - Add passwords for better security
  - Generally improve game quality
- Fully optimise the code
- Implement partially successful actions based on difficulty/energy level. {I saw it in the project requirements file too late)

---

## HOW TO USE

1. Clone repo in a chosen directory on your PC
2. Create a C++ console app project through Visual Studio in the same folder
3. Inside Visual Studio, at the **Solution Explorer** window, right click **Source Files**, then **Add -> Existing Item**
4. Navigate to the **/src** folder and add all files inside.
5. Run the program!

- If file save does not work initially: In **Solution Explorer**, right-click on your project. Then go to **Properties -> Configuration Properties -> Debugging**. Make sure the **Working Directory** is the same as the root of the cloned repository! You should be good to go now!

---
