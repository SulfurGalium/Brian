class SecondMessengerState {
private:
	float cAMP;
	float IP3;
	float PKA;
	float PKC;
	float tau_cAMP;
	float tau_IP3;
	float tau_PKA;
public:
	void step(float dt) {
		cAMP -= cAMP / tau_cAMP * dt;
		IP3 -= IP3 / tau_IP3 * dt;
		PKA -= PKA / tau_PKA * dt;
		PKC -= PKA / tau_PKA * dt;

		PKA += (cAMP / Km_cAMP - PKA) / tau_PKA * dt;
	}

	void activate_cAMP(float amount) {
		cAMP += amount;
	}

	void activate_IP3(float amount) {
		IP3 += amount;
	}

	float AMPA_trafficking_factor() {
		return 1.0 + 0.5 * PKA;
	}

	float excitability_modifier() {
	
	}
};