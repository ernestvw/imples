// BEGIN HEAP TEMPLATE

template<typename T>
class heap {
private:
	int n = 0;
	vector<T> data;

public:
	int size() { return n; }
	void shrink() { data.shrink_to_fit(); }
	void clear() { n = 0; data.clear(); }
	bool empty() { return n == 0; }
	
	void push(T x) {
		if(n+1 >= (int)data.size()) data.resize(2 * ((int)data.size()) + 1);
		++n;
		int i = n - 1;
		data[i] = x;
		while(i > 0 && data[(i - 1) / 2] < data[i]) {
			swap(data[i], data[(i-1) / 2]);
			i = (i - 1) / 2;
		}
	}
	T top() {
		if(n == 0) throw invalid_argument("Heap is empty");
		return data[0];
	}
	void pop() {
		if(n == 0) throw invalid_argument("Heap is empty");
		swap(data[n-1], data[0]);
		--n;
		int i = 0;
		while(2*i+1 < n) {
			if(data[i] < data[2*i+1] && (2*i+2 >= n || data[2*i+2] < data[2*i+1])) {
				swap(data[i], data[2*i+1]);
				i = 2 * i + 1;
			}
			else if(2*i+2 < n && data[i] < data[2*i+2]) {
				swap(data[i], data[2*i+2]);
				i = 2 * i + 2;
			}
			else break;
		}
	}
};

// END HEAP TEMPLATE
