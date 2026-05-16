#include <functional>

/*
potential improvments:

use std::array
*/


class RungeKutta4 {
private:
	int n;
	float dt;
	float* k1, * k2, * k3, * k4, * tmp;
	float half_dt;
	float sixth_dt;
public:
	RungeKutta4(int n, float dt) {
		this->n = n;
		this->dt = dt;
		k1 = new float[n];
		k2 = new float[n];
		k3 = new float[n];
		k4 = new float[n];
		tmp = new float[n];

		half_dt = dt / 2.0f;
		sixth_dt = half_dt / 3.0f;

		for (int i = 0; i < n; i++) tmp[i] = 0.0f;
	}

	~RungeKutta4() {
		delete[] k1;
		delete[] k2;
		delete[] k3;
		delete[] k4;
		delete[] tmp;
	}

	template<typename DerivFn>
	void step(float t, float* y, DerivFn&& deriv) {
		
		deriv(t, y, k1)
		
		for (int i = 0; i < n; i++) {
			tmp[i] = y[i] + half_dt * k1[i];
		}

		deriv(t + half_dt, tmp, k2)

		for (int i = 0; i < n; i++) {
			tmp[i] = y[i] + half_dt * k2[i];
		}

		deriv(t + half_dt, tmp, k3)

		for (int i = 0; i < n; i++) {
			tmp[i] = y[i] + dt * k3[i];
		}

		deriv(t + dt, tmp, k4)

		for (int i = 0; i < n; i++) {
			y[i] += sixth_dt * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
		}
	}
};