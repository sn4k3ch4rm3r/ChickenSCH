#ifndef LEVELS_H
#define LEVELS_H

// Forward deklaráció.
class Game;

/// @brief Pályák ősosztálya.
/// @details A pályák functorok, melyek az adott szinthez tartozó objektumokat hozzáadják a játékhoz.
class Level {
public:
	Level();
	virtual ~Level() = default;

	/// @brief A pálya betöltése.
	/// @param game A játék, amihez hozzáadjuk az objektumokat.
	/// @return Hány objektumot adtunk hozzá a játékhoz.
	virtual int operator()(Game* game) = 0;

	/// @brief A pálya nehézségi szintjének lekérdezése.
	/// @return A pálya nehézségi szintje.
	int getDifficulty() const;

	/// @brief A pálya nehézségi szintjének növelése.
	void increaseDifficulty();

private:
	int _difficulty;
};

/// @brief 1. és 2. szintek.
class OrderedLevel : public Level {
public:
	int operator()(Game* game) override;
};

/// @brief 3. szint.
class RandomLevel : public Level {
public:
	int operator()(Game* game) override;
};

/// @brief 4. szint.
class DescendingLevel : public Level {
public:
	int operator()(Game* game) override;
};

#endif