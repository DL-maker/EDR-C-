class Point {
    private:
        int x;
        int y;
    public:
        Point(int _x, int _y):x(_x), y(_y){
//            :x(_x), y(_y)
//            c'est equivalent a 
//            x = _x
//            y = _y
            
        };
        int operator+(int param_x){
            return x;
        };

}