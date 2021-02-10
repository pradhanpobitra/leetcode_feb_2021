class PeekingIterator : public Iterator {
        
    int size;
    int index;
    vector<int> arr;
public:    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    size = nums.size();;
        for(int x : nums) arr.push_back(x);
        index = 0;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return arr[index];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        return arr[index++];
	}
	
	bool hasNext() const {
	    return index < size ? true : false;
	}
};