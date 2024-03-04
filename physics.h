#include <cmath>

#define SEC_PER_FRAME 48

inline float calculateRadius(float x, float y)
{
   return atan2(x, y);
}

inline float calculateDDX(float gravity, float angleRadians)
{
   return gravity * sin(angleRadians);
}

inline float calculateDDY(float gravity, float angleRadians)
{
   return gravity * cos(angleRadians);
}

inline float calculateDX(float dx, float ddx, float time)
{
   return dx + ddx * time;
}

inline float calculateDY(float dy, float ddy, float time)
{
   return dy + ddy * time;
}


