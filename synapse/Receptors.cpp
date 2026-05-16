#include <cmath>

class MarkovReceptor {
private:

public:
	float p_C;
	float p_O;
	float p_D;
	float g_max;
	float E_rev;
	float kon, koff, kdes, krec;


	virtual void step(float C_NT, float dt) {

	}

	virtual float current(float V) {
		return g_max * p_O * (E_rev - V);
	}

	void reset() {

	}
};

class NMDAReceptor : MarkovReceptor {
public:
	const float kon = 0.05;
	const float koff = 0.003;
	const float kdes = 0.001;
	const float krec = 0.0005;

	const float Mg_conc = 1.0;
	const float eta = 0.062;
	const float gamma = 3.57;

	const float E_Ca = 130.0;


	float Mg_block(float V) {
		return 1 / (1 + (Mg_conc / gamma) * exp(-eta * V));
	}

	void step(float C_NT, float V_post, float dt) {

	}

	float current(float V) {
		return g_max * p_O * Mg_block(V) * (0 - V);
	}

	float Ca_influx(float V) {
		return 0.1 * g_max * p_O * Mg_block(V) * (E_Ca - V);
	}
};

class GABAAReceptor : MarkovReceptor {

};

class AMPAReceptor : MarkovReceptor {
private:
	float tau_rise = 0.5f; // 0.5 ms
	float tau_decay = 5.0f; // 5 ms
public:
	void step(float C_NT, float dt) {
	}

	float current(float V) {
		return
	}

};