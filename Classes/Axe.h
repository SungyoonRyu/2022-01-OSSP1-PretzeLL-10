#ifndef __AXE_H__
#define __AXE_H__

#include "BaseWeapon.h"
#include "AxeProjectile.h"

class Axe : public BaseWeapon
{
protected:
	Axe() : BaseWeapon("axe", 1, 0.2f, 0.0f) {}
	virtual ~Axe() {}

public:
	CREATE_FUNC(Axe);

	void attack(bool flipped, const b2Vec2 &direction) final
	{
		if (!isAttackAble())
			return;

		auto axe = AxeProjectile::create();

		if (!axe)
			return;
		addBullet(axe);
		axe->setParent(this);
		axe->setSpeed(25.0f);
		axe->setRotation(VecToDegree(direction));
		axe->setVelocity(direction);
		axe->PhysicsObject::scale(0.5f);
		axe->move();
		axe->setInitialPos();

		float angle = 30.0f;
		if (flipped)
			angle *= -1;
		auto up = cocos2d::RotateBy::create(0.0f, angle);
		auto down = cocos2d::RotateBy::create(0.07f, angle * -3.0f);
		auto revoke = cocos2d::RotateTo::create(0.03f, getRotation());
		auto seq = cocos2d::Sequence::create(up, down, revoke, nullptr);
		runAction(seq);
	}
};

#endif /* __AXE_H__ */
