#pragma once

template <typename T>
class RingBuffer {
private:
	T* data;
	int head, tail, capacity;
public:
	RingBuffer(T* d) {
		data = d;

		capacity = std::size(data);
		head = 0;
		tail = 0;
	}

	~RingBuffer() {
		delete data;
		delete head;
		delete tail;
		delete capacity;
	}

	void push(T val, int delay_steps) {
		data[(head + delay_steps) % capacity] = val;

		tail = (tail + 1) % capacity;
	}

	bool pop(T& out) {
		out = data[head];
		head = (head + 1) % capacity;
		return true;
	}

	bool peek_ready(int now) {
		//if (data.length == 0) return false; not really nessesary, just adds extra runtime
		return now == tail;//might not work
	}
};