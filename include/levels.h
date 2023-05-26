#ifndef LEVELS_H
#define LEVELS_H

class Game;

class Level {
public:
	Level();
	virtual ~Level() = default;
	virtual int operator()(Game* game) = 0;
	int getDifficulty() const;
	void increaseDifficulty();

private:
	int _difficulty;
};

class OrderedLevel : public Level {
public:
	int operator()(Game* game) override;
};

class RandomLevel : public Level {
public:
	int operator()(Game* game) override;
};

class DescendingLevel : public Level {
public:
	int operator()(Game* game) override;
};

#endif