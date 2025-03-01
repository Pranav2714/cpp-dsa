#include <vector>
            }

            // Process all events with the same timestamp
            int j = i;
            while (j < n && stoi(eventLog[j][1]) == currentTime) {
                j++;
            }

            // Handle OFFLINE events
            for (int k = i; k < j; ++k) {
                if (eventLog[k][0] == "OFFLINE") {
                    int userId = stoi(eventLog[k][2]);
                    if (userId >= 0 && userId < userCount && isOnline[userId]) {
                        isOnline[userId] = false;
                        pendingOnline.push({currentTime + 60, userId});
                    }
                }
            }

            // Handle MESSAGE events
            for (int k = i; k < j; ++k) {
                if (eventLog[k][0] == "MESSAGE") {
                    const string& mentionTarget = eventLog[k][2];

                    if (mentionTarget == "ALL") {
                        // Increment mention count for all users
                        for (int user = 0; user < userCount; ++user) {
                            ++mentionCounts[user];
                        }
                    } else if (mentionTarget == "HERE") {
                        // Increment mention count for online users
                        for (int user = 0; user < userCount; ++user) {
                            if (isOnline[user]) {
                                ++mentionCounts[user];
                            }
                        }
                    } else {
                        // Handle mentions for specific users
                        stringstream ss(mentionTarget);
                        string token;
                        while (ss >> token) {
                            if (token.size() >= 3 && token.substr(0, 2) == "id") {
                                string userIdStr = token.substr(2);
                                if (all_of(userIdStr.begin(), userIdStr.end(), ::isdigit)) {
                                    int userId = stoi(userIdStr);
                                    if (userId >= 0 && userId < userCount) {
                                        ++mentionCounts[userId];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // Move to the next batch of events
            i = j;
        }

        return mentionCounts;
    }
};
©leetcode