class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        int closestX, closestY;
        // bottom left on right
        if (x1 > xCenter) {
            closestX = x1;
        }
        // top right on left
        else if (x2 < xCenter) {
            closestX = x2;
        }
        // somewhere within rectangle
        else {
            closestX = xCenter;
        }
        // bottom left on right
        if (y1 > yCenter) {
            closestY = y1;
        }
        // top right on left
        else if (y2 < yCenter) {
            closestY = y2;
        }
        // somewhere within rectangle
        else {
            closestY = yCenter;
        }

        int dx = xCenter - closestX, dy = yCenter - closestY;
        return dx * dx + dy * dy <= radius * radius;
    }
};