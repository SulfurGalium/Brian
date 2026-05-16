#include "HHGatingVars.cpp"
#include "Vec3.h"
#include <vector>
#include <numbers>
#include "RungeKutta4.h"

class HHCompartment {
private:
	float V;
	HHGatingVars gates;
	float Cm; //membrane capacitance
	float g_Na, g_K, g_L;
	float E_Na, E_K, E_L;
	float Ra;
	float I_syn;
	float I_axial;
	Vec3 postion;
	int parent_id;
	std::vector<int> child_ids;

public:
	enum CompartmentType { //theorhetically not fixed seperate types, they do form hybrids
		SOMA,
		BASAL,
		APICAL_TRUNK,
		APICAL_TUFT,
		OBLIQUE,
		AIS,
		AXON_NODE,
		AXON_TERMINAL,
		SPINE
	};

	HHCompartment(CompartmentType compType) {
		V = -65.0f;
		gates.m = gates.m_inf(-65);
		gates.h = gates.h_inf(-65);
		gates.n = gates.n_inf(-65);

		Cm = 1.0f;

		// default reversal potentials (placeholders)
		E_Na = 50.0f;
		E_K = -77.0f;
		E_L = -54.387f;

		// set conductances based on compartment type
		switch (compType) {
			case SOMA:
				g_Na = 120.0f; g_K = 36.0f; g_L = 0.3f;
				break;
			case AIS:
				g_Na = 800.0f; g_K = 100.0f; g_L = 0.3f;
				break;
			case BASAL:
			case APICAL_TRUNK:
			case APICAL_TUFT:
			case OBLIQUE:
				g_Na = 50.0f; g_K = 20.0f; g_L = 0.1f;
				break;
			case AXON_NODE:
			case AXON_TERMINAL:
			case SPINE:
				g_Na = 1200.0f; g_K = 36.0f; g_L = 0.005f;
				break;
			default:
				g_Na = 120.0f; g_K = 36.0f; g_L = 0.3f;
				break;
		}

		E_Na, E_K, E_L = 55.0f, -77.0f, 54.4f;

		Ra = 150 * L / std::numbers::pi; //p_a in ohms per cm_sq
		// initialize other members
		Ra = 0.0f;
		I_syn = 0.0f;
		I_axial = 0.0f;
		parent_id = -1;
		postion = Vec3(0.0f, 0.0f, 0.0f);
	}

	float I_Na() {
		// placeholder formula: g_Na * m^3 * h * (V - E_Na)
		return g_Na * gates.m * gates.m * gates.m * gates.h * (E_Na - V);
	}

	float I_K() {
		// placeholder formula: g_K * n^4 * (V - E_K)
		return g_K * gates.n * gates.n * gates.n * gates.n * (E_K - V);
	}

	float I_L() {
		return g_L * (E_L - V);
	}

	float dV_dt(float V_parent) {
	
	}

	void step(float dt) {
	
	}

	void recive_current(float I) {
	
	}

	bool fired() {
		return V >= 0.02;
	}
};

