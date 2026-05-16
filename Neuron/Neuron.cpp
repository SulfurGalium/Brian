#include "Vec3.cpp"
#include "HHCompartment.cpp"


class Neuron {
private:
	int id;
	NeuronType type;
	std::vector compartments;
	float last_spike_time;
	float refractory_timer;
	float Ca_soma;
	float avg_firing_rate = 5; //HZ
	SecondMessengerState sms;
	Vec3 soma_position;
public:
	void build_morphology(NeuronType t) {
	
	}

	void step(float dt, float t) {
	
	}

	void propagate_axial_currents() {
	
	}

	bool check_spike(float t) {
	
	}

	void apply_refractory(float dt) {
	
	}

	void update_calcium(float dt) {
	
	}

	void homeostatic_scale(float dt) {
	
	}

	HHCompartment& soma() {
	
	}

	HHCompartment& ais() {
	
	}

	float dendritic_voltage(int comp_id) {
	
	}
};

enum NeuronType {
	PYRAMIDAL_L2_3,
	PYRAMIDAL_L5,
	PYRIMIDAL_L6,
	BASKET_PV,
	CHANDELIER,
	MARTINOTTI,
	VIP,
	STELLATE
};