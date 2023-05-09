# Specifikáció

## A játék lényege
A Space Invaders-hez hasonló játék, csak itt űrlények helyett csirkékkel kell megküzdenünk. A játék végtelen, a legmagasabb pontszám elérése a cél.

## A program felépítése
A program két képernyőből áll: kezdő képernyő és maga a játék.

### Kezdő képernyő
Korábbi játékok legjobb eredményeit láthatjuk és elindíthatjuk a játékot, illetve ide térünk vissza, miután a játékos veszített.

### Játék
Itt zajlik maga a játék. Miután a játékos elveszítette az összes életét beírhat egy nevet, ami majd a toplistában megjelenik, majd visszatér a kezdő képernyőre.

## Pontos játékmenet
A játék végtelen sok szintből áll, szinteken belül pedig körökre van osztva. A körökben különböző viselkedésű ellenségekkel kell megküzdenünk. A körök minden szinten ugyanolyan sorrendben követik egymást. Miután végeztünk egy szinttel, a következő szint ugyanilyen körökből áll, csak növeljük a nehézséget.

A játékosnak 3 élete van, a csirkéknek pedig szinttől függ. A csirkék tojásokkal bombázzák a játékost, ezeket kell elkerülnie különben veszít egy életet. A játékos űrhajója fel van szerelve egy lézerfegyverrel, amivel le tudja lőni a csirkéket, illetve a játék során felvehet fejlesztéseket, így egyszerre többet tud lőni. Hogyha a játékost eltalálja egy tojás elveszít egy életet és fegyvere visszaáll az alap egy lövetű változatra.

## Irányítás
Az űrhajót `A` illetve `D` segítségével mozgathatjuk jobbra illetve balra. `Space` lenyomásával pedig lőni tudunk.

## Fájlkezelés
A toplista elemeit egy `csv` formátumú fájlban tároljuk, illetve onnan olvassuk be a program indításakor.