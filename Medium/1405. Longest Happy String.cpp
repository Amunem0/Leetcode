class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

        while (!pq.empty()) {
            auto [currCount, currChar] = pq.top(); pq.pop();

            // If adding this character would cause three consecutive same chars
            if (result.length() >= 2 &&
                result.back() == currChar &&
                result[result.length() - 2] == currChar) {

                // If no other character is available, break out of the loop
                if (pq.empty()) break;

                // Use the next most frequent character
                auto [nextCount, nextChar] = pq.top(); pq.pop();
                result.push_back(nextChar);
                nextCount--;

                // Push back the character if any occurrence remains
                if (nextCount > 0) pq.push({nextCount, nextChar});

                // Push the previously popped character back into the queue
                pq.push({currCount, currChar});
            } 
            else {
                // Add the current character to the result
                result.push_back(currChar);
                currCount--;

                // Push back the character if any occurrence remains
                if (currCount > 0) pq.push({currCount, currChar});
            }
        }

        return result;
    }
};
