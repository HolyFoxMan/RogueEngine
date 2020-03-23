#include "Victim.hpp"

namespace Gameplay {

typedef Victim::RVictim   RVictim;

Victim::Victim(uint32_t initHealth, uint32_t maxHealth) noexcept
: maxHealth(maxHealth), health(initHealth), healthHandleMtx() {}

uint32_t Victim::GetHealth(void) const noexcept {

    return health;
}

bool Victim::GetLifeStatus(void) const noexcept {

   if (health)
        return true;

    return false;
}

RVictim Victim::TakeDamage(uint32_t damage) noexcept {

    if (!damage)
        return NO_RANGE_ARG;

    healthHandleMtx.lock();

    if (!health) {
        healthHandleMtx.unlock();
        return NO_EFFECT;
    }

    if (damage >= health)
        health = 0;
    else
        health -= damage;

    healthHandleMtx.unlock();
    return SUCCESSFUL;
}

RVictim Victim::TakeDamage(void) noexcept {

    healthHandleMtx.lock();
    if (health)
        --health;
    else {
        healthHandleMtx.unlock();
        return NO_EFFECT;
    }
    healthHandleMtx.unlock();
    return SUCCESSFUL;
}

RVictim Victim::TakeFullDamage(void) noexcept {

    healthHandleMtx.lock();
    if (!health) {
        healthHandleMtx.unlock();
        return NO_EFFECT;
    }

    health = 0;

    healthHandleMtx.unlock();
    return SUCCESSFUL;
}

RVictim Victim::TakeHeal(uint32_t heal) noexcept {

    if (!heal)
        return NO_RANGE_ARG;

    healthHandleMtx.lock();

    uint32_t injury = maxHealth - health;

    if (!injury) {
        healthHandleMtx.unlock();
        return NO_EFFECT;
    }

    if (injury <= heal)
        health = maxHealth;
    else
        health += heal;

    healthHandleMtx.unlock();
    return SUCCESSFUL;
}

RVictim Victim::TakeHeal(void) noexcept {

    healthHandleMtx.lock();
    if (health != maxHealth)
        ++health;
    else {
        healthHandleMtx.unlock();
        return NO_EFFECT;
    }
    healthHandleMtx.unlock();
    return SUCCESSFUL;
}

RVictim Victim::TakeFullHeal(void) noexcept {
    healthHandleMtx.lock();

    if (health == maxHealth) {
        healthHandleMtx.unlock();
        return NO_EFFECT;
    }

    health = maxHealth;

    healthHandleMtx.unlock();
    return SUCCESSFUL;
}

} // Gameplay
