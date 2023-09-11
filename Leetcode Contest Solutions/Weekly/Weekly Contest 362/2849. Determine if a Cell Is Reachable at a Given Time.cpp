class Solution {
public:
    bool isReachableAtTime(int start_x, int start_y, int finish_x, int finish_y, int time) {
    

    if(start_x == finish_x && start_y == finish_y)
    {
        if(time == 1)
        {
            return false;
        }
        return true;
    }
    
    int distance = max(abs(start_x - finish_x), abs(start_y - finish_y));
    if(distance <= time)
    {
        return true;
    }
    else
    {
        return false;
    }    
}
};
