# Matamchkin_Game
## Description
Matamchkin is a strategic game where players, each assuming a unique role with distinct behaviors, engage in battles against various encounters to earn treasures and glory.
The game showcases the use of design patterns.
## Installation Instructions and Usage

To set up Matamchkin on your local machine, follow these steps:

1. **Clone the repository**
   - First, clone the Matamchkin repository from GitHub to your local computer using the following command:
     ```bash
     git clone git@github.com:AlexVeks/Matamchkin_Game.git
     cd matamchkin
     ```

2. **Compile the source code**
   - Compile the game using the g++ compiler with C++11 standard. This step involves compiling all `.cpp` files located in the root directory as well as those in the `Cards` and `Players` subdirectories. Execute the following command in the terminal:
     ```bash
     g++ --std=c++11 -o mtmchkin *.cpp Cards/*.cpp Players/*.cpp -I. -I./Players -I./Cards
     ```

3. **Run the game**
   - After compiling the code, you can run the game by providing text input files for the deck and players. Replace `deck.txt` and `players.txt` with your specific configuration files, or use the provided examples to start playing:
     ```bash
     ./mtmchkin examples/extra_example/deck.txt examples/extra_example/players.txt
     ```

By following these steps, you will be able to download, compile, and start playing Matamchkin on your system. Ensure you have g++ installed and configured correctly to handle C++11 syntax for a successful setup.

## Features

**Card-Based Encounters**
- Matamchkin features a diverse array of encounters, each represented as a card. These encounter cards are monsters that guard treasures, challenging players to strategic battles to win these coveted rewards.

**Dynamic Player Roles and Behaviors**
- Players assume unique roles with specific behaviors that significantly influence combat outcomes. These roles and the strategic decisions players make are crucial in overcoming the challenges posed by encounter cards.

**Treasure and Rewards**
- Victory in battles allows players to claim the treasures held by monsters. These treasures are instrumental in boosting players' abilities, offering significant advantages in the game.

**Event Cards**
- In addition to encounter cards, Matamchkin includes event cards that can alter gameplay unexpectedly. These cards can affect one player, multiple players, or the entire game environment, adding an element of surprise and requiring players to adapt their strategies on the fly.

**Progressive Leveling System**
- Each successful battle against an encounter card not only brings treasure but also experience, allowing players to level up. Advancing in levels enhances players' stats and abilities, with the game concluding when a player reaches Level 10.

**End-Game Scenario**
- The goal of reaching Level 10 sets the end-game condition. Achieving this milestone ends the game, with the leading player declared the winner, celebrated for their strategic prowess and successful navigation through the myriad challenges of Matamchkin.

## Code Organization and Design Patterns

**Overview**
Matamchkin's codebase is structured into a modular and scalable architecture, using various design patterns to enhance maintainability and separation of concerns.

**Player Components**
- `PlayerFactory`: Utilizes the Factory Method design pattern to create `Player` objects with distinct roles and behaviors.
- `Player`: Acts as the game's characters, each possessing a unique `Job` and `Behavior` that influence the game mechanics.
- `BehaviorFactory` & `JobFactory`: Follow the Abstract Factory design pattern to produce specific `Behavior` and `Job` instances.
- `Behavior` & `Job`: Abstract classes that are extended by concrete classes like `Responsible`, `RiskTaking`, `Sorcerer`, `Warrior`, etc., exemplifying the Strategy design pattern for dynamic behavior and job swapping.

**Card Components**
- `DeckFactory`: Adheres to the Factory Method design pattern to construct a deck of `Card` objects for the game.
- `Card`: An abstract entity that lays the foundation for `Event` and `Encounter` card types.
- `Event`: A subclass of `Card` that represents game-altering events.
- `Encounter`: Derived from `Card`, this class includes `Monster` cards as part of the game's challenges.
- `Monster`: An abstract class that forms the base for specific monsters like `Goblin`, `Giant`, `Dragon`, and group of monsters: `Gang`, demonstrating Polymorphism.

**Gameplay Components**
- `MtMchkin`: The central class that orchestrates the game flow, leverages other components, and manages the `Leaderboard`.
- `Leaderboard`: Tracks player scores and levels, updating as players progress through the game.

Matamchkin's design leverages Object-Oriented Programming principles and design patterns such as Factory Method, Abstract Factory, and Strategy, providing a flexible codebase that's ready for expansion and new feature integrations.

## System Architecture

Below is the UML diagram that outlines theclass relationships within Matamchkin.
This diagram reflects the current state of the system and will be updated as the project evolves.

![Matamchkin UML Diagram](https://private-user-images.githubusercontent.com/39146925/322212070-8f4bb1da-3c12-46e7-90c8-fce51bf0cf23.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTMwMTg4NzksIm5iZiI6MTcxMzAxODU3OSwicGF0aCI6Ii8zOTE0NjkyNS8zMjIyMTIwNzAtOGY0YmIxZGEtM2MxMi00NmU3LTkwYzgtZmNlNTFiZjBjZjIzLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDA0MTMlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQwNDEzVDE0MjkzOVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTg2NmM5NzEyNjE3OWNhMDI5NDBhNjZjODIwNjcxOTVmNjU5NjM0NzY1ODg5M2QwMjQ4MmNiMDI3ZGY5ZDc1ZmImWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JmFjdG9yX2lkPTAma2V5X2lkPTAmcmVwb19pZD0wIn0.4KYnd4QUE7L_gWL7qc_c-vAXAk6n9c4X2LXtHwQwslQ)


