#include "Activity.hpp"

Activity::Activity(Activity::Types type) noexcept : type(type), state(Activity::States::FROZEN) {}
Activity::~Activity(void) noexcept {}
