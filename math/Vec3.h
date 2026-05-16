#pragma once

#include <cmath>

class Vec3 {
public:

	float x, y, z; //intentionally put as public, decreases function call stack time

	Vec3(float xi, float yi, float zi) {
		x = xi;
		y = yi;
		z = zi;
	}

	float distance(Vec3 b) {	
		return std::sqrtf(std::exp2(x-b.x) + std::exp2(y - b.y) + std::exp2(z - b.z));
	};

	float distance(Vec3 b) {
		return this->dot(*this);
	};

	Vec3 operator+(Vec3 b) {
		return Vec3(x + b.x,y + b.y,z + b.z);
	}

	Vec3 operator*(float s) {
		return Vec3(x * s, y * s, z * s);
	}

	float dot(Vec3 b) {
		return (x * b.x) + (y * b.y) + (z * b.z);
	}

	Vec3 normalize() {
		float magnitude = std::sqrtf(this->dot(*this));
		if (magnitude < 0.0f) return Vec3(0, 0, 0);

		magnitude = 1.0f / magnitude;

		return Vec3(x * magnitude, y * magnitude, z * magnitude);

		/*
			long i;
			float x2, y;
			const float threehalfs = 1.5F;

			x2 = number * 0.5F;
			y  = number;
			i  = * ( long * ) &y;                       // evil floating point bit level hacking
			i  = 0x5f3759df - ( i >> 1 );               // what the...
			y  = * ( float * ) &i;
			y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration of Newton's method
			return y;

		*/
	}


};