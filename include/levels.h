#ifndef LEVELS_H
#define LEVELS_H

class Game;

class Level {
public:
	Level();
	virtual void operator()(Game* game) = 0;
	int getDifficulty() const;
	void increaseDifficulty();

private:
	int _difficulty;
};

class OrderedLevel : public Level {
public:
	void operator()(Game* game) override;
};

class RandomLevel : public Level {
public:
	void operator()(Game* game) override;
};

class OrderedDescendingLevel : public Level {
public:
	void operator()(Game* game) override;
};

#endif