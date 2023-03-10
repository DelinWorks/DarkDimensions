#ifndef __EXTRA_MATH_H__
#define __EXTRA_MATH_H__

#include "short_types.h"
#include <cmath>
#include <vector>
#include "axmol.h"

namespace Math
{
    // takes a value and limits it to be within a specified range defined by the minimumand maximum values. If the value is greater than the maximum, it returns the maximum value. If the value is less than the minimum, it returns the minimum value. Otherwise, it returns the original value.
    inline f32 clamp(f32 current, f32 min, f32 max) {
        if (current > max)
            return max;
        if (current < min)
            return min;
        return current;
    }

    // takes a floating-point number and snaps it to the nearest multiple of an integer interval. It rounds the input number divided by the interval to get an integer result and then multiplies that result by the interval to get the snapped value.
    inline i32 snap(f32 i, i32 v) { return (i32)(round(i / v) * v); }

    // similar to "snap" but allows for snapping to a fractional interval. It takes an original floating-point number and snaps it to the nearest multiple of a fraction defined by numerator and denominator values. It rounds the original number multiplied by denominator divided by numerator to get an integer result and then multiplies that result by numerator divided by denominator to get the snapped value.
    inline f64 snap_interval(f64 original, f64 numerator, f64 denominator)
    { 
        return round(original * denominator / numerator) * numerator / denominator;
    }

    // maps a given input value from one range of values into another range of values. It takes an input value x and maps it from an input range defined by in_min and in_max into an output range defined by out_min and out_max using linear interpolation.
    inline f32 map(f32 x, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
    {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    inline void getVec2Average(ax::Vec2& d, ax::Vec2* s, int c) {
        d = { 0, 0 };
        for (int i = 0; i < c; i++) {
            d.x += s[i].x;
            d.y += s[i].y;
        }
        d.x /= static_cast<float>(c);
        d.y /= static_cast<float>(c);
    }
}

#endif
