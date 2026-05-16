class SynapticCleft {
private:
	float C_NT;
	float C_peak;
	float tau_clear;
	float D_coeff;
	float cleft_width;
public:
	void release(float fraction) {
	
	}

	void step(float dt) {
	
	}

	float concentration() {
		return C_NT;
	}
};

class ReuptakeTransporter {
private:
	float Vmax;
	float Km;
	TransporterType type;
public:
	float uptake_rate(float C) {
		return (Vmax * C) / (Km + C)
	}

	void apply(SynapticCleft& cleft, float dt) {

	}

	void apply(VolumeField& field, Vec3 pos, float dt) {

	}
};