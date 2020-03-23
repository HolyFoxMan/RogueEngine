#pragma once

#include <cstdint>
#include <mutex>

namespace Gameplay {

/* Victim declaring (thread-safe) */
class Victim {

public:
    enum RVictim {
        SUCCESSFUL,
        NO_RANGE_ARG,
        NO_EFFECT
    };

    static const uint32_t INIT_HEALTH_DEF = 100;
    static const uint32_t MAX_HEALTH_DEF = 100;

    Victim(uint32_t initHealth = INIT_HEALTH_DEF, uint32_t customMaxHealth = MAX_HEALTH_DEF) noexcept;

    RVictim TakeDamage(uint32_t damage) noexcept;
    RVictim TakeDamage(void) noexcept;  // decrement health
    RVictim TakeFullDamage(void) noexcept;

    RVictim TakeHeal(uint32_t heal) noexcept;
    RVictim TakeHeal(void) noexcept;    // increment health
    RVictim TakeFullHeal(void) noexcept;

    uint32_t GetHealth(void) const noexcept;
    bool GetLifeStatus(void) const noexcept;

protected:
    uint32_t maxHealth;

private:
    uint32_t health;
    std::mutex healthHandleMtx;
};

}
