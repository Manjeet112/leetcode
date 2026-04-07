class Robot {
    private:
    int w, h;
    int pos = 0;
    int perimeter;
    bool moved = false;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        // Total unique cells on the boundary
        perimeter = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        moved = true;
        pos = (pos + num) % perimeter;
    }
    
    vector<int> getPos() {
        int p = pos;
        // 1. Bottom edge: (0,0) -> (w-1, 0)
        if (p < w) return {p, 0};
        
        // 2. Right edge: (w-1, 1) -> (w-1, h-1)
        p -= (w - 1);
        if (p < h) return {w - 1, p};
        
        // 3. Top edge: (w-2, h-1) -> (0, h-1)
        p -= (h - 1);
        if (p < w) return {w - 1 - p, h - 1};
        
        // 4. Left edge: (0, h-2) -> (0, 1)
        p -= (w - 1);
        return {0, h - 1 - p};
    }
    
    string getDir() {
        if (!moved || pos == 0) {
            return !moved ? "East" : "South";
        }
        
        // Logical boundaries for directions based on perimeter index
        if (pos > 0 && pos < w) return "East";
        if (pos >= w && pos < w + h - 1) return "North";
        if (pos >= w + h - 1 && pos < 2 * w + h - 2) return "West";
        
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */