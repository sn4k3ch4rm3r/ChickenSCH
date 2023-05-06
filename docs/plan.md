# ChickenSCH - Terv

## A program magas szintű működése
```plantuml
@startuml

hide empty description

[*] -down-> Start

Start --> Game 

Start : Itt látjuk a toplistát a\njáték indítása előtt

state Game {
	[*] --> Level1
	Level1 -right-> Level2
	Level2 --> Level3
	Level3 --> Level4
	Level4 --> Level1 : Növeljük\na nehézséget

	Level1: Alap szint, rendezetten\nsorakoznak a csirkék
	Level2: Ugyan az, mint az első szint
	Level3: Össze-vissza mozognak a\ncsirkék, közelednek a játékoshoz
	Level4: Rendezett sorokban\nközelednek a játékoshoz
}

Game -right-> GameOver : Játékos veszít
GameOver -up-> Start 

GameOver : Itt adhatjuk meg, hogy milyen\nnév szerepeljen a toplistában 

@enduml
```

- Start
  - load leaderboard from disc
  - display leaderboard
  - display text indicating how to start the game
  - start game
- Game
  - level manager starts current level
  - level manager keeps track of level progress
  - once level is cleared load next level
  - if the player dies set scene to game over
- GameOver
  - Allow player to input their name
  - once enter is pressed the name is saved to the leaderboard
  - go back to the starting scene

