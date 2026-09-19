bool checkOverlap(int radius, int xCenter, int yCenter,int x1, int y1, int x2, int y2) {

    int closestX, closestY;

    if (xCenter < x1)
        closestX = x1;
    else if (xCenter > x2)
        closestX = x2;
    else
        closestX = xCenter;

    if (yCenter < y1)
        closestY = y1;
    else if (yCenter > y2)
        closestY = y2;
    else
        closestY = yCenter;

    int dx = xCenter - closestX;
    int dy = yCenter - closestY;

    return (dx * dx + dy * dy) <= radius * radius;
}