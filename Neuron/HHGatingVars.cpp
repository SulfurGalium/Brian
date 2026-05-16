#include <cmath>
#include "RungeKutta4.h"

class HHGatingVars {
private:
	RungeKutta4 rk4;
public:
	float m, h, n; //Na activiation gate, Na inactivation gate, K activation gate [0, 1]


	HHGatingVars() : rk4(4, 0.05f) {

	}

	float alpha_m(float V) {
		if (std::fabs(V + 54.0f) < 1e-5f) return 1.28f;//0.32f * 4.0f;
		return 0.32f * (V + 54.0f) / (1.0f - std::exp(-(V + 54.0f) / 4.0f));
	}

	float beta_m(float V) {
		return 0.28f * (V + 27.0f) / (std::exp((V + 27.0f) / 5.0f) - 1.0f);
	}

	float alpha_h(float V) {
		return 0.128f * std::exp(-(V + 50.0f) / 18.0f);
	}

	float beta_h(float V) {
		return 4.0f / (1.0f + std::exp(-(V + 27.0f) / 5.0f));
	}

	float alpha_n(float V) {
		if (std::fabs(V + 52.0f) < 1e-5f) return 0.16f;
		return 0.032f * (V + 52.0f) / (1.0f - std::exp(-(V + 52.0f) / 5.0f));
	}

	float beta_n(float V) {
		return 0.5f * std::exp(-(V + 57.0f) / 40.0f);
	}

	void step(float V, float dt) {
		float temp[] = {alpha_m(V), beta_m(V), alpha_h(V), beta_h(V), alpha_n(V), beta_n(V)};
	
	
	}

	float m_inf(float V) {
		return alpha_m(V) / (alpha_m(V) + beta_m(V));
	}

	float h_inf(float V) {
		return alpha_h(V) / (alpha_h(V) + beta_h(V));
	}

	float n_inf(float V) {
		return alpha_n(V) / (alpha_n(V) + beta_n(V));
	}
};