#ifndef __BASE_WEAPON_H__
#define __BASE_WEAPON_H__

#include "StaticObject.h"
#include "Bullet.h"


class BaseWeapon : public StaticObject {
private:
    typedef std::function<BaseWeapon*(void)> create_func_t;
    static std::map<int, create_func_t> __create_func;
    
protected:    
    float __attackTime;
    float __revertTime;
    float __chargeTime;
    
    bool* __fire_key;
    
    Timer __attackTimer;
    Timer __chargeTimer;
    
protected:
    BaseWeapon(std::string name,
               float attackTime = 0.2f,
               float revertTime = 0.0f,
               float chargeTime = 0.0f);
    virtual ~BaseWeapon();
    
public:
//    CREATE_FUNC(BaseWeapon);
    
    bool init() final;
    void update(float dt) final;
    void addBullet(bullet_t* bullet);
    
    void activate();
    void deactivate();
    void registerKey(bool* key);
    WEAPON getType();
    
    bool isAttacking();
    bool isAttackAble();
    bool isCharging();
    float getAttackTime();
    virtual void attack(bool flipped, const b2Vec2& direction);
    
    static void insertCreateFunc(int tag, create_func_t func);
    static BaseWeapon* getByTag(int tag);
};

#endif /* __BASE_WEAPON_H__ */
