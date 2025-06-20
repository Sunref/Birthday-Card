#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib.h"
#include "config.h"

// Functions for text animation
void DrawAnimatedText(float time, const AnimationConfig* config);
void RunMessageAnimation(AnimationConfig* config, int fromWriteInterface);

#endif
