class Solution {
public:
    double angleClock(int hour, int minutes){
    
    double angle;

    if(minutes/5<hour){
        angle = abs(hour - minutes / 5.0) * 30 + minutes * 0.5;
    }
    // Calculate the angle using the provided formula
    else{
        angle = abs(hour - minutes / 5.0) * 30 - minutes * 0.5;
    }

    // Ensure the angle is non-negative
    angle = abs(angle);

    // Return the smaller angle between the two possible angles
    return min(angle, 360 - angle);
    }
};
