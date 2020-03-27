#pragma once

class Activity {
public:
    enum States {
        FINISHED = -1,
        FROZEN,
        ACTIVE
    };

    enum Types {
        LEVEL,
        DYNAMIC,
        PLAYER_CHUNK,
        PLAYER_CLUSTER
    };

    Activity(Types type) noexcept;
    virtual ~Activity(void);
    virtual void Update(void) = 0;

private:
    Types type;
    States state;
};
