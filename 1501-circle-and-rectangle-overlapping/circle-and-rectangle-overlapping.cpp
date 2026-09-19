class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int xMin = min(abs(xCenter - x1), abs(xCenter - x2));
        int yMin = min(abs(yCenter - y1), abs(yCenter - y2));

        int minix = min(x1, x2);
        int maxix = max(x1, x2);
        int miniy = min(y1, y2);
        int maxiy = max(y1, y2);

        // Center's x is inside rectangle
        if (xCenter >= minix && xCenter <= maxix) {
            if (yMin <= radius)
                return true;
        }

        // Center's y is inside rectangle
        if (yCenter >= miniy && yCenter <= maxiy) {
            if (xMin <= radius)
                return true;
        }

        // Center is inside rectangle
        if ((xCenter >= minix && xCenter <= maxix) &&
            (yCenter >= miniy && yCenter <= maxiy))
            return true;

        // NEW: center is outside in both x and y
        if (xCenter < minix || xCenter > maxix) {
            if (yCenter < miniy || yCenter > maxiy) {
                if (xMin * xMin + yMin * yMin <= radius * radius)
                    return true;
            }
        }

        return false;
    }
};