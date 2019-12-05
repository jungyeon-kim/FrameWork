#pragma once

#include "GameActor.h"

class Player : public GameActor
{
private:
	using CoolTimeContainer = std::unique_ptr<std::map<Skill, float>>;
private:
	static constexpr float MAX_VEL{ 7 };
	int animCycle{};
	int nextHeadAnimX{};
	int nextBodyAnimX{};
	int alphaCnt{};

	class GameController* gameCon{};
	CoolTimeContainer maxCoolTime{};
	CoolTimeContainer currCoolTime{};
public:
	Player(const Vector& pos);
	virtual ~Player() override;

	virtual void init(const Vector& pos) override;
	virtual void update(float eTime) override;
	virtual void render() override;
	virtual void addForce() override;
	virtual void takeDamage(float damage) override;

	bool isEndCoolTime(Skill name) const;
	void resetCoolTime(Skill name);
	void setCoolTime();
};