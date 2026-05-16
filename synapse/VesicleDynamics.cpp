class CaTerminal {
private:
	float Ca;
	float Ca_influx_per_spike;
	float pump_rate;
	float buffer_rate;
	float tau_Ca;

public:
	void step(float dt, bool spike) {

	}

	float residual() {

	}

	float release_probability{

	}
};

class VesiclePool {
private:
	float X;
	float Y;
	float Z;
	float U;
	float tau_rec;
	float tau_in;
	float U_se;

public:

	VesiclePool() {
		X = 1.0;
		U = 0.2;
		tau_rec = 800;
		tau_in = 3;
	}

	void step(float dt) {

	}

	float release() {
		float temp = U * X;
		X -= temp;

		return temp;
	}

	void facilitate(float delta_U) {

	}

	float transmitter_released() {

	}
};