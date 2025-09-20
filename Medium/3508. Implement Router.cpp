class Router {
public:
    queue<vector<int>> packets;     // FIFO queue
    set<vector<int>> packetSet;     // for duplicate check
    map<int, deque<int>> destTimes; // destination -> timestamps
    int memoryLimit;

    Router(int memoryLimit) { 
        this->memoryLimit = memoryLimit; 
    }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};

        if (packetSet.count(packet) > 0)
            return false;

        if (packets.size() == memoryLimit) {
            vector<int> front = packets.front();
            packets.pop();
            packetSet.erase(front);
            destTimes[front[1]].pop_front();
        }

        packets.push(packet);
        packetSet.insert(packet);
        destTimes[destination].push_back(
            timestamp); // append, timestamps increasing
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty())
            return {};
        vector<int> packet = packets.front();
        packets.pop();
        packetSet.erase(packet);
        destTimes[packet[1]].pop_front();
        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& dq = destTimes[destination];
        if (dq.empty())
            return 0;

        // timestamps are sorted because they come in increasing order
        auto l = lower_bound(dq.begin(), dq.end(), startTime);
        auto r = upper_bound(dq.begin(), dq.end(), endTime);
        return distance(l, r);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
