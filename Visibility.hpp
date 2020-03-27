#pragma once

/*
class Visitor {
    unsigned int id;
};
*/

/* square area */
class Chunk {
public:
    int VisitorsCount;
    unsigned int* visitorIds;
};

class ChunksGrid {
public:
    int width, height;
    double sideLength;
    Chunk** chunks;
private:
    size_t chunkDataSize;
    Chunk* chunkData;
};
