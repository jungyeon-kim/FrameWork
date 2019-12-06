#include "stdafx.h"
#include "Enemy.h"
#include "Physics.h"
#include "Renderer.h"
#include "TexMgr.h"

Enemy::Enemy(const Vector& pos)
{
	init(pos);
}

Enemy::~Enemy()
{
}

void Enemy::init(const Vector& pos)
{
	texID.emplace_back(texMgr->getTexture(Tex::TEST));
	maxHP = 100.0f;
	currHP = maxHP;
	damage = 10.0f;

	forceAmount = 9.0f;
	fricCoef = 0.8f;
	objForce;
	objPos = pos;
	objVel;
	objAcc;
	objVol = { meter(), meter(), meter() };
	objCol = { 1.0f, 1.0f, 1.0f, 1.0f };
	objMass = 2.0f;
}

void Enemy::update(float eTime)
{
	GameActor::update(eTime);

	objForce = { 0.0f, 0.0f, 0.0f };
	addForce();

	// update Physics
	objAcc = physics->getAcc(objAcc, objForce, objMass);
	objVel = physics->getVel(objVel, objAcc, eTime);
	objVel = physics->getVelByFric(objVel, objMass, fricCoef, eTime);
	objPos = physics->getPos(objPos, objVel, objAcc, eTime);
}

void Enemy::render()
{
	renderer->DrawTextureRect(objPos, objVol, objCol, texID[0]);
	renderer->DrawSolidRectGauge(objPos, { 0.0f, meter(0.7), 0.0f }, { objVol.x, meter(0.15), 0.0f },
		{ 0.8f, 0.8f, 0.8f, 0.8f }, 100.0f);
	renderer->DrawSolidRectGauge(objPos, { 0.0f, meter(0.7), 0.0f }, { objVol.x, meter(0.15), 0.0f },
		{ 1.0f, 0.0f, 0.0f, 0.8f }, (currHP / maxHP) * 100.0f);

	GameObj::render();		// 셰이더가 z축 기준으로 렌더링 되게 바뀌면 맨 앞에서 호출할 예정
}

void Enemy::addForce()
{
}